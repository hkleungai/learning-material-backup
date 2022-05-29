// COMP152 Lab

#include <cassert>
#include <string>

using namespace std;

typedef int T;

class Array
{
public:
/* Constructors & Destructor */
    Array ();
    Array (int size);
    Array (const Array& arr);
    Array (const T * arr, int size);
    virtual ~Array ();

/* Operators Overloaded */
// The main task
    // TO DO: complete the overload operator assingment =
    // assign the size and the value of each element in the _data to this Array
    Array& operator=(const Array& arr);

    // TO DO: complete the overload operator comparison ==
    // compare the size and the values in *_data
    // if both the size and the values is the same, return true.
    // Otherwise return false
    bool operator==(const Array& arr) const;

    // TO DO: complete the overload operator index []
    // return the value of _data[index], which is the index element in the *_data
    T& operator[](int index);  // rvalue & lvalue
    T operator[](int index) const;  // rvalue, const-variant

    // TO DO: implement the overload operator plus equal +=, its declaration included
    // append an Array object to the end of another Array object.
    // assign this appended result to this Array


/* Methods */
    void Append (const T& item);

/* Properties */
    bool IsValid () const;
    int Size () const;

/* Member variables */
private:
    T* _data;
    int _size;
};

