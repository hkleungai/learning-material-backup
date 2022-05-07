#include "ManagementSystem.h"
#include <iostream>
#include <cstring>
using namespace std;

ManagementSystem::ManagementSystem() 
    : firstBook(nullptr) {
}

ManagementSystem::~ManagementSystem() {
    while (firstBook != nullptr) {
        Book* newFirstBook = firstBook -> getNext();
        delete firstBook;
        firstBook = newFirstBook;
    }
}

void ManagementSystem::printCommandChoices() const {
    cout << endl << "Please select commond from following:" << endl;
    cout << AddBook << " : Add a new book to the library" << endl;
    cout << DeleteBookByName << " : Delete books with given name" << endl;
    cout << SearchBookByName << " : Search for books by name" << endl;
    cout << SearchBookByAuthor << " : Search for books by author" << endl;
    cout << PrintAll << " : Print out the information of all the books" << endl;
    cout << ExitSystem << " : Exit" << endl;
    cout << "Please enter the index of command: ";
}

void ManagementSystem::processAddingBook(const char* name, char** authorList, int numPages, int numAuthor) {
    Book *newFirstBook = new Book(name, authorList, numPages, numAuthor);
    newFirstBook->setNext(firstBook);
    firstBook = newFirstBook;
}

void ManagementSystem::processDeletingBook(const char* name) {
    firstBook -> deleteBookByName(name);   
    if (strcmp(firstBook -> getName(), name) == 0) {
        Book* newFirstBook = firstBook -> getNext();
        delete firstBook;
        firstBook = newFirstBook;
    }
}

void ManagementSystem::processSearchByName(const char* name) const {
    cout << "\nSearching for book " << name << " :\n";
    if (firstBook != nullptr) {
        firstBook -> printBookInfoByName(name);
    }
}

void ManagementSystem::processSearchByAuthor(const char* name) const {
    cout << "\nSearching for books by " << name << " :\n";
    if (firstBook != nullptr) {
        firstBook -> printBooksInfoByAuthor(name);
    }
}

void ManagementSystem::processPrintAll() const {
    if (firstBook == nullptr) {
        cout << "No book in the library!" << endl;
    } else {
        cout << endl << "List of all books:" << endl;
        firstBook -> printAllBooks();
    }
}
