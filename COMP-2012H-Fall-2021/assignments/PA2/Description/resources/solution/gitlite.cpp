#include "gitlite.h"
#include "Utils.h"

using namespace std;

const string msg_initial_commit = "initial commit";

const string msg_no_changes_added = "No changes added to the commit.";

const string msg_no_reason_remove = "No reason to remove the file.";

const string msg_commit_does_not_exist = "No commit with that id exists.";

const string msg_file_does_not_exist = "File does not exist in that commit.";

const string msg_untracked_file = "There is an untracked file in the way; delete it, or add and commit it first.";

const string msg_branch_does_not_exist = "A branch with that name does not exist.";

const string msg_checkout_current = "No need to checkout the current branch.";

const string msg_branch_exists = "A branch with that name already exists.";

const string msg_remove_current = "Cannot remove the current branch.";

const string msg_merge_current = "Cannot merge a branch with itself.";

const string msg_exists_uncommitted_changes = "You have uncommitted changes.";

const string msg_given_is_ancestor_of_current = "Given branch is an ancestor of the current branch.";

const string msg_fast_forward = "Current branch fast-forwarded.";

const string msg_encountered_merge_conflict = "Encountered a merge conflict.";

const string status_branches_header = "=== Branches ===";

const string status_staged_files_header = "=== Staged Files ===";

const string status_removed_files_header = "=== Removed Files ===";

const string status_modifications_not_staged_header = "=== Modifications Not Staged For Commit ===";

const string msg_status_deleted = " (deleted)";

const string msg_status_modified = " (modified)";

const string status_untracked_files_header = "=== Untracked Files ===";

string get_merge_commit_message(const Blob *given_branch, const Blob *current_branch) {
    string message("Merged " + given_branch->name + " into " + current_branch->name + ".");
    return message;
}

void init(Blob *&current_branch, List *&branches, List *&staged_files, List *&tracked_files, Commit *&head_commit) {
    branches = list_new();
    staged_files = list_new();
    tracked_files = list_new();

    Commit *commit = new Commit;
    commit->message = msg_initial_commit;
    commit->time = get_time_string();
    commit->commit_id = get_sha1(commit->message, commit->time);

    commit->tracked_files = list_copy(tracked_files);
    head_commit = commit;
    current_branch = branch("master", branches, commit);
}

bool add(const string &filename, List *staged_files, List *tracked_files, const Commit *head_commit) {
    string hash = get_sha1(filename);
    list_put(tracked_files, filename, hash);

    Blob *node = list_find_name(head_commit->tracked_files, filename);
    if (node != nullptr && node->ref == hash) {
        list_remove(staged_files, filename);
        return false;
    }

    list_put(staged_files, filename, hash);
    return true;
}

bool commit(const string &message, Blob *current_branch, List *staged_files, List *tracked_files, Commit *&head_commit) {
    if (staged_files->head->next == staged_files->head && list_size(tracked_files) == list_size(head_commit->tracked_files)) {
        cout << msg_no_changes_added << endl;
        return false;
    }

    Commit *commit = new Commit;
    commit->message = message;
    commit->time = get_time_string();
    commit->commit_id = get_sha1(commit->message, commit->time);

    commit->parent = head_commit;
    commit->tracked_files = list_copy(tracked_files);

    current_branch->commit = commit;
    head_commit = commit;
    list_clear(staged_files);
    return true;
}

bool remove(const string &filename, List* staged_files, List *tracked_files, const Commit *head_commit) {
    bool tracked = false;
    if (list_find_name(head_commit->tracked_files, filename)) {
        tracked = true;
        restricted_delete(filename);
    }

    if (list_remove(tracked_files, filename) && list_remove(staged_files, filename))
        tracked = true;

    if (!tracked)
        cout << msg_no_reason_remove << endl;
    return tracked;
}

void log(const Commit *head_commit) {
    const Commit *curr = head_commit;
    while (curr->parent != nullptr) {
        cout << "===" << endl;
        commit_print(curr);
        cout << endl << endl;
        curr = curr->parent;
    }
    cout << "===" << endl;
    commit_print(curr);
    cout << endl << endl;
}

void status(const Blob *current_branch, const List *branches, const List *staged_files, const List *tracked_files,
            const List *cwd_files, const Commit *head_commit) {
    cout << status_branches_header << endl;
    for (Blob *node = branches->head->next; node != branches->head; node = node->next) {
        if (node == current_branch) {
            cout << "*";
        }
        cout << node->name << endl;
    }

    cout << endl << status_staged_files_header << endl;
    for (Blob *node = staged_files->head->next; node != staged_files->head; node = node->next) {
        cout << node->name << endl;
    }

    cout << endl << status_removed_files_header << endl;
    const List *head_tracked_files = head_commit->tracked_files;
    for (Blob *node = head_tracked_files->head->next; node != head_tracked_files->head; node = node->next) {
        if (!list_find_name(tracked_files, node->name)) {
            cout << node->name << endl;
        }
    }

    cout << endl << status_modifications_not_staged_header << endl;
    for (Blob *node = tracked_files->head->next; node != tracked_files->head; node = node->next) {
        if (!is_file_exist(node->name))
            cout << node->name << msg_status_deleted << endl;
        else if (node->ref != get_sha1(node->name))
            cout << node->name << msg_status_modified << endl;
    }

    cout << endl << status_untracked_files_header << endl;
    for (Blob *node = cwd_files->head->next; node != cwd_files->head; node = node->next) {
        if (!list_find_name(tracked_files, node->name))
            cout << node->name << endl;
    }
}

bool checkout(const string &filename, Commit *commit) {
    if (commit == nullptr) {
        cout << msg_commit_does_not_exist << endl;
        return false;
    }

    List *tracked_files = commit->tracked_files;
    Blob *node = list_find_name(tracked_files, filename);
    if (node == nullptr) {
        cout << msg_file_does_not_exist << endl;
        return false;
    }
    write_file(filename, node->ref);
    return true;
}

bool checkout(Commit *commit, List *staged_files, List *tracked_files, const List *cwd_files, Commit *&head_commit) {
    if (commit == nullptr) {
        cout << msg_commit_does_not_exist << endl;
        return false;
    }

    List *commit_tracked_files = commit->tracked_files;
    List *head_tracked_files = head_commit->tracked_files;
    for (Blob *node = cwd_files->head->next; node != cwd_files->head; node = node->next) {
        if (list_find_name(commit_tracked_files, node->name) && !list_find_name(head_tracked_files, node->name)) {
            cout << msg_untracked_file << endl;
            return false;
        }
    }

    for (Blob *node = cwd_files->head->next; node != cwd_files->head; node = node->next) {
        if (!list_find_name(commit_tracked_files, node->name) && list_find_name(head_tracked_files, node->name)) {
            restricted_delete(node->name);
        }
    }

    for (Blob *node = commit_tracked_files->head->next; node != commit_tracked_files->head; node = node->next) {
        write_file(node->name, node->ref);
    }

    list_clear(staged_files);
    list_replace(tracked_files, commit_tracked_files);

    head_commit = commit;
    return true;
}

bool checkout(const string &branch_name, Blob *&current_branch, const List *branches, List *staged_files,
              List *tracked_files, const List *cwd_files, Commit *&head_commit) {
    Blob *branch = list_find_name(branches, branch_name);
    if (branch == nullptr) {
        cout << msg_branch_does_not_exist << endl;
        return false;
    }

    if (branch == current_branch && branch->commit == head_commit) {
        cout << msg_checkout_current << endl;
        return false;
    }

    if (!checkout(branch->commit, staged_files, tracked_files, cwd_files, head_commit))
        return false;

    current_branch = branch;
    return true;
}

bool reset(Commit *commit, Blob *current_branch, List *staged_files, List *tracked_files, const List *cwd_files,
           Commit *&head_commit) {
    if (!checkout(commit, staged_files, tracked_files, cwd_files, head_commit))
        return false;

    current_branch->commit = commit;
    return true;
}

Blob *branch(const string &branch_name, List *branches, Commit *head_commit) {
    if (list_find_name(branches, branch_name)) {
        cout << msg_branch_exists << endl;
        return nullptr;
    }
    return list_put(branches, branch_name, head_commit);
}

bool remove_branch(const string &branch_name, Blob *current_branch, List *branches) {
    if (current_branch->name == branch_name) {
        cout << msg_remove_current << endl;
        return false;
    }

    if (!list_remove(branches, branch_name)) {
        cout << msg_branch_does_not_exist << endl;
        return false;
    }

    return true;
}

void add_conflict_marker(const string &filename, const string &ref, List *staged_files, List *tracked_files) {
    add_conflict_marker(filename, ref);
    stage_content(filename);     // ensure the staged version is the latest
    string hash = get_sha1(filename);
    list_put(staged_files, filename, hash);
    list_put(tracked_files, filename, hash);
}

bool process_sp_tracked_file(const string &filename, List *staged_files, List *tracked_files, Commit *branch_head,
                             const string &sp_ref, const Commit *head_commit) {
    Blob *curr_tracked = list_find_name(tracked_files, filename);
    Blob *branch_tracked = list_find_name(branch_head->tracked_files, filename);

    if (!curr_tracked && branch_tracked) {
        if (branch_tracked->ref != sp_ref) {
            add_conflict_marker(filename, branch_tracked->ref, staged_files, tracked_files);
            return false;
        }
        return true;
    }

    if (curr_tracked && !branch_tracked) {
        if (curr_tracked->ref == sp_ref) {
            remove(filename, staged_files, tracked_files, head_commit);
        } else {
            add_conflict_marker(filename, string(), staged_files, tracked_files);
            return false;
        }
        return true;
    }

    if (curr_tracked && branch_tracked) {
        if (branch_tracked->ref != sp_ref) {
            if (curr_tracked->ref == sp_ref) {
                checkout(filename, branch_head);
                stage_content(filename);
                list_put(staged_files, filename, branch_tracked->ref);
                list_put(tracked_files, filename, branch_tracked->ref);
            } else if (curr_tracked->ref != branch_tracked->ref) {
                add_conflict_marker(filename, branch_tracked->ref, staged_files, tracked_files);
                return false;
            }
        }
    }
    return true;
}

bool process_sp_untracked_file(const string &filename, List *staged_files, List *tracked_files, const Blob *branch_tracked,
                               Commit *branch_head) {
    Blob *curr_tracked = list_find_name(tracked_files, filename);

    if (!curr_tracked) {
        checkout(filename, branch_head);
        stage_content(filename);
        list_put(staged_files, filename, branch_tracked->ref);
        list_put(tracked_files, filename, branch_tracked->ref);
        return true;
    }

    if (curr_tracked->ref != branch_tracked->ref) {
        add_conflict_marker(filename, branch_tracked->ref, staged_files, tracked_files);
        return false;
    }
    return true;
}

bool merge(const string &branch_name, Blob *&current_branch, List *branches, List *staged_files, List *tracked_files,
           const List *cwd_files, Commit *&head_commit) {
    Blob *branch = list_find_name(branches, branch_name);
    if (branch == nullptr) {
        cout << msg_branch_does_not_exist << endl;
        return false;
    }
    if (branch == current_branch) {
        cout << msg_merge_current << endl;
        return false;
    }
    if (staged_files->head->next != staged_files->head || list_size(tracked_files) != list_size(head_commit->tracked_files)) {
        cout << msg_exists_uncommitted_changes << endl;
        return false;
    }

    Commit *branch_head = branch->commit;
    Commit *split_point = get_lca(head_commit, branch_head);

    if (split_point == branch_head) {
        cout << msg_given_is_ancestor_of_current << endl;
        return true;
    }

    List *branch_tracked_files = branch_head->tracked_files;
    for (Blob *node = cwd_files->head->next; node != cwd_files->head; node = node->next) {
        string &filename = node->name;
        if (!list_find_name(head_commit->tracked_files, filename) && list_find_name(branch_tracked_files, filename)) {
            cout << msg_untracked_file << endl;
            return false;
        }
    }

    if (split_point == head_commit) {
        if (reset(branch_head, current_branch, staged_files, tracked_files, cwd_files, head_commit)) {
            cout << msg_fast_forward << endl;
            return true;
        }
        return false;
    }

    List *sp_tracked_files = split_point->tracked_files;
    bool conflict = false;
    for (Blob *node = sp_tracked_files->head->next; node != sp_tracked_files->head; node = node->next) {
        if (!process_sp_tracked_file(node->name, staged_files, tracked_files, branch_head, node->ref, head_commit))
            conflict = true;
    }

    for (Blob *node = branch_tracked_files->head->next; node != branch_tracked_files->head; node = node->next) {
        if (!list_find_name(sp_tracked_files, node->name)
            && !process_sp_untracked_file(node->name, staged_files, tracked_files, node, branch_head))
            conflict = true;
    }

    if (conflict)
        cout << msg_encountered_merge_conflict << endl;

    string message = get_merge_commit_message(branch, current_branch);
    if (commit(message, current_branch, staged_files, tracked_files, head_commit)) {
        head_commit->second_parent = branch_head;
    }
    return true;
}
