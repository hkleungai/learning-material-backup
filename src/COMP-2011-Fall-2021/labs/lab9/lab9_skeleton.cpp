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


/** Task 1:  create an initial linked list with kid_num nodes with random heights, each presenting a kid. **/
kidNode* createKidList(int kid_num, int min_height, int max_height){
// Please implement task 1 here.
}

/**Task 2: reverse the initial linked list.**/
kidNode* reverseKidList(kidNode* head){
// Please implement task 2 here.
}

/**Task 3: line up the kids according to their heights in an ascending order.**/
kidNode* sortKidList(kidNode* head){
// Please implement task 3 here.
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
   } while(true);

   return 0;
}