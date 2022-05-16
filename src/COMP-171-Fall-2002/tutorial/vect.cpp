// Prepared for
// HKUST COMP 171 Fall 2002 Tutorial 1
// by Ken Lee & Kawah Wong

// Simple example on how to use vector in STL


#include <vector>       // no .h for standard library
#include <iostream.h>
using namespace std;    // optional in simple program


int main() {
    vector<int> v_int(5);   // Declare a int vector of size 5.
    vector<double> v_double;    // declare a vector of double

    v_int[0] = 7;
    v_int[1] = v_int[0] + 3;
    v_int[2] = v_int[0] + v_int[1];

    // note: the size is 5. Two '0' will be displayed
    for (int i = 0; i < v_int.size(); i++) {
        cout << v_int[i] << " ";
        if (v_int[i] == 7+3) cout << " YEAH! ";
    }
    cout << endl;

    // note: only 3 elements will be displayed.
    v_double.push_back(3.5);
    v_double.push_back(4.7);
    v_double.push_back(7.2);
    for (int j = 0; j < v_double.size(); j++) {
        cout << v_double[j] << " ";
    }
    cout << endl;


    return 0;
}
