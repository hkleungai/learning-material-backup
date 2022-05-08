#include "Commit.h"
#include "Utils.h"

using namespace std;

// Deep copy a given Blob object, setting the newly created object's prev and next to nullptr.
Blob *blob_copy(const Blob *source) {
    if (source == nullptr)
        return nullptr;

    Blob *blob = new Blob(*source);
    blob->prev = blob->next = nullptr;
    return blob;
}

// Replace the blob->ref with the given ref.
void blob_write(Blob *blob, const string &ref) {
    if (blob == nullptr)
        return;
    blob->ref = ref;
}

// Create a new List object with the sentinel node.
List *list_new() {
    List *list = new List;
    Blob *head = list->head = new Blob;
    head->prev = head;
    head->next = head;
    return list;
}

// Push the given blob to the end of the linked list, no deep copy is made.
void list_push_back(List *list, Blob *blob) {
    Blob *head = list->head;
    blob->prev = head->prev;
    blob->next = head;
    head->prev->next = blob;
    head->prev = blob;
}

// Find the blob in a list with matching name, return nullptr if not found.
Blob *list_find_name(const List *list, const string &name) {
    for (Blob *blob = list->head->next; blob != list->head; blob = blob->next) {
        if (blob->name == name)
            return blob;
    }
    return nullptr;
}

// Put a blob with given name and ref into the list. If the blob with given name
// does not exist, create and insert it at correct position following
// lexicographic order on name. Otherwise, replace its contents with given contents.
Blob *list_put(List *list, const string &name, const string &ref) {
    Blob *blob = list_find_name(list, name);
    if (blob != nullptr) {
        blob_write(blob, ref);
        return blob;
    }

    blob = new Blob;
    blob->name = name;
    blob->ref = ref;

    Blob *cur;
    for (cur = list->head->next; cur != list->head; cur = cur->next) {
        if (cur->name > name) {
            break;
        }
    }

    blob->prev = cur->prev;
    blob->next = cur;
    cur->prev->next = blob;
    cur->prev = blob;

    return blob;
}

// Put a blob containing the given name and commit in the list, following
// lexicographic order on name.
// Shallow copy the commit pointer.
Blob *list_put(List *list, const string &name, Commit *commit) {
    Blob *blob = list_find_name(list, name);
    if (blob != nullptr) {
        blob->commit = commit;
        return blob;
    }

    blob = new Blob;
    blob->name = name;
    blob->commit = commit;

    Blob *cur;
    for (cur = list->head->next; cur != list->head; cur = cur->next) {
        if (cur->name > name) {
            break;
        }
    }

    blob->prev = cur->prev;
    blob->next = cur;
    cur->prev->next = blob;
    cur->prev = blob;

    return blob;
}

// Remove a blob from a list.
bool list_remove(List *list, const string &target) {
    for (Blob *blob = list->head->next; blob != list->head; blob = blob->next) {
        if (blob->name == target) {
            blob->prev->next = blob->next;
            blob->next->prev = blob->prev;
            delete blob;
            return true;
        }
    }
    return false;
}

// Get the size of the blobs in the given list, excluding the sentinel node.
int list_size(const List *list) {
    int count = 0;
    for (Blob *blob = list->head->next; blob != list->head; blob = blob->next) {
        ++count;
    }
    return count;
}

// Clear a list by freeing all its nodes, except for the sentinel node.
void list_clear(List *list) {
    if (list == nullptr || list->head == nullptr) {
        return;
    }

    Blob *blob = list->head->next;
    while (blob != list->head) {
        blob = blob->next;
        delete blob->prev;
    }

    list->head->next = list->head->prev = list->head;
}

// Delete a list
void list_delete(List *list) {
    list_clear(list);
    delete list->head;
    delete list;
}

// Replace a list by another list
void list_replace(List *list, const List *another) {
    list_clear(list);
    for (Blob *blob = another->head->next; blob != another->head; blob = blob->next) {
        Blob *newBlob = blob_copy(blob);
        list_push_back(list, newBlob);
    }
}

// Deep copy a whole given list, maintaining the order of the elements.
List *list_copy(const List *list) {
    List *copy = list_new();
    for (Blob *blob = list->head->next; blob != list->head; blob = blob->next) {
        Blob *newBlob = blob_copy(blob);
        list_push_back(copy, newBlob);
    }
    return copy;
}

// Print out the commit info. Used in log.
void commit_print(const Commit *commit) {
    cout << "commit " << commit->commit_id << endl;

    if (commit->second_parent != nullptr) {
        cout << "Merge: " << commit->parent->commit_id.substr(0, 7)
             << " " << commit->second_parent->commit_id.substr(0, 7) << endl;
    }

    cout << "Date: " << commit->time << endl << commit->message;
}

void get_ancestors_helper(Commit *commit, List *ancestors) {
    if (commit == nullptr) {
        return;
    }

    if (! list_find_name(ancestors, commit->commit_id)) {
        list_put(ancestors, commit->commit_id, commit);

        get_ancestors_helper(commit->parent, ancestors);
        get_ancestors_helper(commit->second_parent, ancestors);
    }
}

List *get_ancestors(Commit *commit) {
    List *ancestors = list_new();
    get_ancestors_helper(commit, ancestors);
    return ancestors;
}

Commit *get_lca(Commit *c1, Commit *c2) {
    List *a1 = get_ancestors(c1);
    List *a2 = get_ancestors(c2);

    List *common_ancestors = list_copy(a1);
    for (Blob *curr = common_ancestors->head->next; curr != common_ancestors->head; ) {
        if (!list_find_name(a2, curr->name)) {
            // curr not found, delete curr
            Blob *del = curr;
            curr = curr->next;
            list_remove(common_ancestors, del->name);
        }
        else {
            curr = curr->next;
        }
    }

    List *common_ancestors2 = list_copy(common_ancestors);
    for (Blob *curr = common_ancestors2->head->next; curr != common_ancestors2->head; curr = curr->next) {
        Commit *parent = curr->commit->parent;
        Commit *second_parent = curr->commit->second_parent;
        if (parent && list_find_name(common_ancestors, parent->commit_id)) {
            list_remove(common_ancestors, parent->commit_id);
        }
        if (second_parent && list_find_name(common_ancestors, second_parent->commit_id)) {
            list_remove(common_ancestors, second_parent->commit_id);
        }
    }

    // Assume only 1 lca exists
    Commit *lca = common_ancestors->head->next->commit;

    list_delete(a1);
    list_delete(a2);
    list_delete(common_ancestors);
    list_delete(common_ancestors2);

    return lca;
}
