// Prepared for
// HKUST COMP 171 Fall 2002 Tutorial 1
// by Kawah Wong & Ken Lee

// Simple example on how to use a class template to define a class

#include <iostream.h>

// a class defined by class template
// Notice the syntax on defining a class member function.

template <class T>
class Pair {
    T first;
    T second;
public:
    Pair(const T & x, const T & y) { first = x; second = y; }
    void setElement(int pos, const T & value);
    const T & getElement(int pos);
};

template<class T>
void Pair<T>::setElement(int pos, const T & value) {
    if (pos == 1) first = value;
    if (pos == 2) second = value;
}

template<class T>
const T & Pair<T>::getElement(int pos){
    if (pos == 2) return second;
    return first;
}

int main() {
    // testing pair<T>
    cout << endl << "pair<T>:" << endl;
    Pair<int> pair0(5,5);
    Pair<double> pair1(1.2,2.4);
    cout << "pair<int>(0)=" << pair0.getElement(0) << endl;
    cout << "pair<double>(1)=" << pair1.getElement(1) << endl;
    pair1.setElement(1,3.6);
    cout << "pair<double>(1)=" << pair1.getElement(1) << endl;

    return 0;
}
