#ifndef MANAGEMENTSYSTEM_H_
#define MANAGEMENTSYSTEM_H_

#include "Book.h"


class ManagementSystem
{
  private:
    
    Book *firstBook = nullptr;
  
  public:

    enum Command {AddBook, DeleteBookByName, SearchBookByName, SearchBookByAuthor, PrintAll, ExitSystem};

    ManagementSystem();

    ~ManagementSystem();

    void printCommandChoices() const;

    void processAddingBook(const char* name, char** authorList, int numPages, int numAuthor);

    void processDeletingBook(const char* name);

    void processSearchByName(const char* name) const;

    void processSearchByAuthor(const char* name) const;

    void processPrintAll() const;


};

#endif /* MANAGEMENTSYSTEM_H_ */
