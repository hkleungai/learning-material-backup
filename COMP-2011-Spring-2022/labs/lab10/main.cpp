#include "Book.h"
#include "ManagementSystem.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_NAME_LENGTH = 50;

void processAddBook(ManagementSystem *managementSystem) {
    cout << endl << "Please enter the title of this new book:";
    char* name;
    name = new char[MAX_NAME_LENGTH];
    cin  >> name;
                
    cout << endl << "Please enter the number of pages of this new book:";
    int numPages;
    cin >> numPages;

    cout << endl << "Please enter the number of authors of this new book:";
    int numAuthor;
    cin >> numAuthor;

    cout << endl << "Please enter the name of authors of this new book:";
    char **authorList = new char* [numAuthor + 1];
    for (int index = 0; index < numAuthor; ++index) {
        authorList[index] = new char [MAX_NAME_LENGTH];
        cin >> authorList[index];
    }

    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    delete [] name;
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;
}

void processDeleteBook(ManagementSystem *managementSystem) {
    cout << endl << "Please enter the title of the book to delete:";
    char* name;
    name = new char[MAX_NAME_LENGTH];
    cin  >> name;
    managementSystem -> processDeletingBook(name);
    delete [] name;
}

void processSearchByName(ManagementSystem* managementSystem) {
    cout << endl << "Please enter the title of the book to search for:";
    char* name;
    name = new char[MAX_NAME_LENGTH];
    cin  >> name;
    managementSystem -> processSearchByName(name);
    delete [] name;
}

void processSearchByAuthor(ManagementSystem* managementSystem) {
    cout << endl << "Please enter the name of the author to search for:";
    char* name;
    name = new char[MAX_NAME_LENGTH];
    cin  >> name;
    managementSystem -> processSearchByAuthor(name);
    delete [] name;
}

void libraryManagementSystem() {
    cout << endl << "Welcome to the library management system!" << endl;
    ManagementSystem *managementSystem = new ManagementSystem();
    bool ifContinueLoop = true;
    while (ifContinueLoop) {
        managementSystem -> printCommandChoices();
        int commandIndex;
        cin >> commandIndex;
        switch (commandIndex) {
            case ManagementSystem::AddBook:
                processAddBook(managementSystem);
                break;
            case ManagementSystem::DeleteBookByName:
                processDeleteBook(managementSystem);
                break;
            case ManagementSystem::SearchBookByName:
                processSearchByName(managementSystem);
                break;
            case ManagementSystem::SearchBookByAuthor:
                processSearchByAuthor(managementSystem);
                break;
            case ManagementSystem::PrintAll:
                managementSystem -> processPrintAll();
                break;
            case ManagementSystem::ExitSystem:
                ifContinueLoop = false;
                cout << endl << "Thanks for using our management system!" << endl;
                break;
        }
    }
    delete managementSystem;
}

// In Test Case 1, only task1 and task2 (i.e., constructor and destructor) are tested.
void testCase1() {
    ManagementSystem *managementSystem = new ManagementSystem();
    char* name;
    name = new char[MAX_NAME_LENGTH];
    strcpy(name, "Book1");
    int numPages = 100;
    int numAuthor = 2;
    char **authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author1");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author2");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book2");
    numPages = 100;
    numAuthor = 3;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author2");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author3");
    authorList[2] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[2], "Author4");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book3");
    numPages = 100;
    numAuthor = 1;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author2");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    managementSystem -> processPrintAll();
    delete [] name;
    delete managementSystem;
}

// In Test Case 2, only task1, task2 and task3 are tested.
void testCase2() {
    ManagementSystem *managementSystem = new ManagementSystem();
    char* name;
    name = new char[MAX_NAME_LENGTH];
    strcpy(name, "Book1");
    int numPages = 100;
    int numAuthor = 2;
    char **authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author1");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author2");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book2");
    numPages = 100;
    numAuthor = 3;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author2");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author3");
    authorList[2] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[2], "Author4");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book3");
    numPages = 100;
    numAuthor = 1;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author2");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    managementSystem -> processPrintAll();

    strcpy(name, "Book1");
    managementSystem -> processSearchByName(name);

    strcpy(name, "Book2");
    managementSystem -> processSearchByName(name);

    strcpy(name, "Book3");
    managementSystem -> processSearchByName(name);

    delete [] name;
    delete managementSystem;    
}

// In Test Case 3, only task1, task2 and task4 are tested.
void testCase3() {
    ManagementSystem *managementSystem = new ManagementSystem();
    char* name;
    name = new char[MAX_NAME_LENGTH];
    strcpy(name, "Book1");
    int numPages = 100;
    int numAuthor = 2;
    char **authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author1");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author2");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book2");
    numPages = 100;
    numAuthor = 3;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author2");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author3");
    authorList[2] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[2], "Author4");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book3");
    numPages = 100;
    numAuthor = 1;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author2");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    managementSystem -> processPrintAll();

    strcpy(name, "Author1");
    managementSystem -> processSearchByAuthor(name);

    strcpy(name, "Author2");
    managementSystem -> processSearchByAuthor(name);

    strcpy(name, "Author3");
    managementSystem -> processSearchByAuthor(name);

    strcpy(name, "Author4");
    managementSystem -> processSearchByAuthor(name);

    delete [] name;

    delete managementSystem;   
}

// In Test Case 4, only task1, task2, task3 and task4 are tested.
void testCase4() {
    ManagementSystem *managementSystem = new ManagementSystem();
    char* name;
    name = new char[MAX_NAME_LENGTH];
    strcpy(name, "Book1");
    int numPages = 100;
    int numAuthor = 2;
    char **authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author1");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author2");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book2");
    numPages = 100;
    numAuthor = 4;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author2");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author3");
    authorList[2] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[2], "Author4");
    authorList[3] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[3], "Author7");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book3");
    numPages = 100;
    numAuthor = 1;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author2");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book4");
    numPages = 100;
    numAuthor = 3;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author4");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author5");
    authorList[2] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[2], "Author6");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    managementSystem -> processPrintAll();

    for (int authorIndex = 1; authorIndex <= 7; ++authorIndex) {
        string authorName = "Author" + to_string(authorIndex);
        strcpy(name, authorName.c_str());
        managementSystem -> processSearchByAuthor(name);
    }
    
    for (int bookIndex = 1; bookIndex <= 4; ++bookIndex) {
        string bookName = "Book" + to_string(bookIndex);
        strcpy(name, bookName.c_str());
        managementSystem -> processSearchByName(name);
    }

    delete [] name;

    delete managementSystem;   
}

// In Test Case 5, only task1, task2 and task5 are tested.
void testCase5() {
    ManagementSystem *managementSystem = new ManagementSystem();
    char* name;
    name = new char[MAX_NAME_LENGTH];
    strcpy(name, "Book1");
    int numPages = 100;
    int numAuthor = 2;
    char **authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author1");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author2");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book2");
    numPages = 100;
    numAuthor = 3;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author2");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author3");
    authorList[2] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[2], "Author4");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book3");
    numPages = 100;
    numAuthor = 1;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author2");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book4");
    numPages = 100;
    numAuthor = 1;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author1");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    managementSystem -> processPrintAll();

    strcpy(name, "Book2");
    managementSystem -> processDeletingBook(name);
    managementSystem -> processPrintAll();

    strcpy(name, "Book1");
    managementSystem -> processDeletingBook(name);
    managementSystem -> processPrintAll();

    strcpy(name, "Book4");
    managementSystem -> processDeletingBook(name);
    managementSystem -> processPrintAll();
    
    strcpy(name, "Book3");
    managementSystem -> processDeletingBook(name);
    managementSystem -> processPrintAll();

    delete [] name;

    delete managementSystem;   
}

// In Test Case 6, all the tasks are tested.
void testCase6() {
    ManagementSystem *managementSystem = new ManagementSystem();
    char* name;
    name = new char[MAX_NAME_LENGTH];
    strcpy(name, "Book1");
    int numPages = 100;
    int numAuthor = 2;
    char **authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author1");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author2");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book2");
    numPages = 100;
    numAuthor = 4;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author2");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author3");
    authorList[2] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[2], "Author4");
    authorList[3] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[3], "Author7");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book3");
    numPages = 100;
    numAuthor = 1;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author2");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    strcpy(name, "Book4");
    numPages = 100;
    numAuthor = 3;
    authorList = new char* [numAuthor + 1];
    authorList[0] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[0], "Author4");
    authorList[1] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[1], "Author5");
    authorList[2] = new char [MAX_NAME_LENGTH];
    strcpy(authorList[2], "Author6");
    managementSystem -> processAddingBook(name, authorList, numPages, numAuthor);
    for (int index = 0; index < numAuthor; ++index) {
        delete [] authorList[index];
    }
    delete [] authorList;

    managementSystem -> processPrintAll();

    for (int authorIndex = 1; authorIndex <= 7; ++authorIndex) {
        string authorName = "Author" + to_string(authorIndex);
        strcpy(name, authorName.c_str());
        managementSystem -> processSearchByAuthor(name);
    }
    
    for (int bookIndex = 1; bookIndex <= 4; ++bookIndex) {
        string bookName = "Book" + to_string(bookIndex);
        strcpy(name, bookName.c_str());
        managementSystem -> processSearchByName(name);
    }

    strcpy(name, "Book2");
    managementSystem -> processDeletingBook(name);
    managementSystem -> processPrintAll();

    for (int authorIndex = 1; authorIndex <= 7; ++authorIndex) {
        string authorName = "Author" + to_string(authorIndex);
        strcpy(name, authorName.c_str());
        managementSystem -> processSearchByAuthor(name);
    }
    
    for (int bookIndex = 1; bookIndex <= 4; ++bookIndex) {
        string bookName = "Book" + to_string(bookIndex);
        strcpy(name, bookName.c_str());
        managementSystem -> processSearchByName(name);
    }

    strcpy(name, "Book1");
    managementSystem -> processDeletingBook(name);
    managementSystem -> processPrintAll();

    for (int authorIndex = 1; authorIndex <= 7; ++authorIndex) {
        string authorName = "Author" + to_string(authorIndex);
        strcpy(name, authorName.c_str());
        managementSystem -> processSearchByAuthor(name);
    }
    
    for (int bookIndex = 1; bookIndex <= 4; ++bookIndex) {
        string bookName = "Book" + to_string(bookIndex);
        strcpy(name, bookName.c_str());
        managementSystem -> processSearchByName(name);
    }

    strcpy(name, "Book4");
    managementSystem -> processDeletingBook(name);
    managementSystem -> processPrintAll();

    for (int authorIndex = 1; authorIndex <= 7; ++authorIndex) {
        string authorName = "Author" + to_string(authorIndex);
        strcpy(name, authorName.c_str());
        managementSystem -> processSearchByAuthor(name);
    }
    
    for (int bookIndex = 1; bookIndex <= 4; ++bookIndex) {
        string bookName = "Book" + to_string(bookIndex);
        strcpy(name, bookName.c_str());
        managementSystem -> processSearchByName(name);
    }

    delete [] name;

    delete managementSystem;   
}

int main() {
    int testCase;
    cout << "Hi, which test case do you want to run?" << endl;
    cin >> testCase;

    cout << endl << "Test case " << testCase << " output:" << endl;
    cout << "===================================" << endl;

    if(testCase == 0) {
        // This test case is used to run the library management system.
        // It is for you to test your program.
        // It would NOT be used to grade your work and it is NOT on ZINC.
        // No mark is allocated to this.
        libraryManagementSystem();
    } else if (testCase == 1) {
        // In Test Case 1, only task1 and task2 (i.e., constructor and destructor) are tested.
        testCase1();
    } else if (testCase == 2) {
        // In Test Case 2, only task1, task2 and task3 are tested.
        testCase2();
    } else if (testCase == 3) {
        // In Test Case 3, only task1, task2 and task4 are tested.
        testCase3();
    } else if (testCase == 4) {
        // In Test Case 4, only task1, task2, task3 and task4 are tested.
        testCase4();
    } else if (testCase == 5) {
        // In Test Case 5, only task1, task2 and task5 are tested.
        testCase5();
    } else if (testCase == 6) {
        // In Test Case 6, all the tasks are tested.
        testCase6();
    }
    return 0;
}
