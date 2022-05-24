#include <iostream>
#include "Array.h"
using namespace std;

int main ()
{
    int arr1size = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    Array <int> array1(arr1, arr1size);     // constructor with an array
    int i;
    for (i = 0; i<array1.Size(); i++)
    {
        cout << array1[i] << " ";
    }
    cout << endl;

    Array <int> array2;     // default constructor
    cout << "array1 == array2 is " << (array1 == array2) << endl;
    for (i = 0; i<arr1size; i++)
    {
        array2.Append(arr1[i]);
    }
    cout << "array1 == array2 is " << (array1 == array2) << endl;

    Array <int> array3 = array1;   // copy constructor
    cout << "array1 == array3 is " << (array1 == array3) << endl;
 
    Array <int> array4;     // default constructor
    array4 = array1;        // assignment operator
    cout << "array1 == array4 is " << (array1 == array4) << endl;

    Array <int> array5(arr1size);   // constructor with intial size
    cout << "array1 == array5 is " << (array1 == array5) << endl;
    for (i = 0; i<arr1size; i++)
    {
        array5[i] = arr1[i];
    }
    cout << "array1 == array5 is " << (array1 == array5) << endl;

    return 0;
}