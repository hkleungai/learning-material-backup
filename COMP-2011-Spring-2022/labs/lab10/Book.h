#ifndef BOOK_H_
#define BOOK_H_

class Book
{
  private:
    // Stores a list of author names of a book.
    char **authorList;

    // Stores the title of the book.
    char *name;

    // Stores the number of pages and authors of a book.
    int numPages, numAuthor;

    // Stores the pointer of the next book within the whole library management system (the
    // linked list).
    Book *next;

  public:
    // Task 1: Constructor of a new book.
    Book(const char *name, char * const * authorList, int numPages = 0, int numAuthor = 0);

    // Task 2: Destructor to delete an existing book.
    ~Book();

    // Task 3: Search for and print out information of book(s) with a given name.
    void printBookInfoByName(const char * name) const;

    // Task 4: Search for and print out information of book(s) of a given author.
    void printBooksInfoByAuthor(const char * authorName) const;

    // A given function to print out the information of all the books.
    void printAllBooks() const;

    // A given function to print out the information of one single book.
    void printSingleBookInfo() const;
    
    // Set the value of next to a given pointer.
    void setNext(Book* book);
    
    // Task 5: Search for and delete book(s) of a given name.
    void deleteBookByName(const char * name);
    
    // Get the name of one single book.
    const char* getName() const;
    
    // Get next of a book.
    Book* getNext();
};

#endif /* BOOK_H_ */
