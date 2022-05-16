// Prepared for
// HKUST COMP 171 Fall 2002 Tutorial 1
// by Kawah Wong & Ken Lee

// Simple example on how to use function template

#include <iostream.h>
#include <string>

// a swap function defined by function template.
template<class T>
void swap (T & x, T & y){
    T temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    // testing swap(T,T)
    cout << endl << "swap(T,T):" << endl;
    // swap int
    int x = 2, y = 3;
    cout << "x=" << x << ", y=" << y << endl;
    swap(x, y);
    cout << "x=" << x << ", y=" << y << endl;

    // swap char
    char a='h', b='w';
    cout << "a=" << a << ", b=" << b << endl;
    swap(a, b);
    cout << "a=" << a << ", b=" << b << endl;

    // swap string
    string s1 = "first";
    string s2 = "second";
    cout << "s1=" << s1 << ", s2=" << s2 << endl;
    swap(s1, s2);
    cout << "s1=" << s1 << ", s2=" << s2 << endl;

    return 0;
}

