#include <iostream> 
#include <cstdlib> 
 
using namespace std; 

const int MIN_HEIGHT = 120;
const int MAX_HEIGHT = 160;

struct kidNode 
{ 
    int height; 
    kidNode* next; 
}; 


int getRandomHeight(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

void printLinkedList(kidNode* head){
    for (kidNode* p = head; p != nullptr; p = p->next){
        cout << p->height;
        cout << " ";
    }
    cout << endl;
}

void deleteLinkedList(kidNode*& head){
    if (head == nullptr)
        return;
    deleteLinkedList(head->next);
    delete head;
    head = nullptr;
}


/** Task 1:  create an initial linked list with kid_num nodes with random heights, each presenting a kid. **/
kidNode* createKidList(int kid_num, int min_height, int max_height){
    kidNode* head = new kidNode;
    head->height = getRandomHeight(min_height, max_height);

    kidNode* scan = head;

    for (int i = 1; i < kid_num; ++i){
        scan->next = new kidNode;
        scan = scan->next;
        scan->height = getRandomHeight(min_height, max_height);
        if (i == kid_num - 1){
            scan->next = nullptr;
        }
    }
    return head;
}

/**Task 2: reverse the initial linked list.**/
kidNode* reverseKidList(kidNode* head){
    kidNode* cur = head;
    kidNode* pre = nullptr;
    while(cur) {
        kidNode* temp; 
        temp = cur->next;  
        cur->next = pre; 
        pre = cur;
        cur = temp;
    }
    return pre;
}

/**Task 3: line up the kids according to their heights in an ascending order.**/
kidNode* sortKidList(kidNode* head){
    if (head == nullptr || head->next == nullptr)
        return head;
    else {
        for (kidNode* i = head; i != nullptr; i = i->next) {
            for (kidNode* j = i->next; j != nullptr; j = j->next) {
                if (i->height > j->height){
                    int temp = i->height;
                    i->height = j->height;
                    j->height = temp;
                }
            }
        }
        return head;
    }    
}


int main()
{   
   int kid_num;

   do {
        cout << "===========================================" << endl;
        cout << "Please input the number of kids in the class (no more than 20) or enter an alphabet to exit:" << endl;
        cin >> kid_num;
        if (cin.fail())
            return 0;

        if (kid_num <= 0 || kid_num > 20){
            cout << "Invalid number! Please input a number again." << endl;
            continue;
        }

        kidNode* initial_line_head = createKidList(kid_num, MIN_HEIGHT, MAX_HEIGHT);

        cout << endl;
        cout << "Output:" << endl;
        cout << "The initial list of kids' heights is:" << endl;
        printLinkedList(initial_line_head);

        kidNode* reversed_line_head = reverseKidList(initial_line_head);
        cout << "The reversed list of kids' heights is:" << endl;
        printLinkedList(reversed_line_head);

        kidNode* sorted_line_head = sortKidList(reversed_line_head);
        cout << "The ascending list of kids' heights is:" << endl;
        printLinkedList(sorted_line_head);

        // Delete Linked List; 
        // Nodes in the other two lists share the same address with the initial list
        deleteLinkedList(initial_line_head);

    cout << endl;
        
   } while(true);

   return 0;
}