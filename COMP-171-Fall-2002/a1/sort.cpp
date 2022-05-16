#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <iostream.h>
#include <math.h>
#include <string.h>
#include "sortlib.hpp"


int main(int argc, char** argv)
{
    // check if there are two arguments as required
    if (!(argc==3)) {
        cout << "you should use two arguments" << endl;
        return 0;
    }

    // get the first argument and make sure m is in the correct range
    int m=atoi((const char *)(argv[1]));
    if (!(m>=1) && (m<=4)) {
        cout << "you can only use 1-4 for the first argument" << endl;
        return 0 ;
    }

    // get the second argument, the length of the array, and turn into a string
    int length=atoi((const char *)(argv[2]));
    char fl[10];
    int l=length;
    int exp=log10(l);
    int i;
    for (i=0; i<=exp; i++) {
        int j=exp-i;
        char f=(floor(l/pow(10,j)))+48;
        fl[i]=f;
        l=l-(floor(l/pow(10,j))*pow(10,j));
    }

    // find the file to read array from
    fl[i]=0;
    char filename[15];
    strcpy(filename, "array");
    strcat(filename, fl);
    strcat(filename, ".txt");
    int key[524288]; // array to hold all the numbers to be sorted
    ifstream fin;

    // read the numbers from the array file into the array
    fin.open(filename);
    for (i=0; i<length; i++) { 
        char c[10];
        fin.getline(c, '\n');
        key[i]=atoi(c);
    }
    fin.close();

    // if the length of array<16384, run the sorting algorithm 100 times
    int round=1;
    if (length < 16384) {
        for (i=length; i<2*length; i++) key[i]=key[i-length];
        round=100;
    }
    switch (m) {
        case 1: // quicksort
	    if (round==1) {
	        qsort(key,length);
            } else {
                for (int j=1; j<round; j++) {
                    qsort(key, length);
                    for (int k=0; k<length; k++) key[k]=key[k+length];
                }
                qsort(key, length);
            }
            break;
        case 2: // heapsort
	    if (round==1) {
	        hsort(key,length);
            } else {
                for (int j=1; j<round; j++) {
                    hsort(key, length);
                    for (int k=0; k<length; k++) key[k]=key[k+length];
                }
                hsort(key, length);
            }
            break;
        case 3: // mergesort
	    if (round==1) {
	        msort(key,length);
            } else {
                for (int j=1; j<round; j++) {
                    msort(key,length);
                    for (int k=0; k<length; k++) key[k]=key[k+length];
                }
                msort(key, length);
            }
            break;
       case 4: // radixsort
	    if (round==1) {
	        rsort(key,length);
            } else {
                for (int j=1; j<round; j++) {
                    rsort(key,length);
                    for (int k=0; k<length; k++) key[k]=key[k+length];
                }
                rsort(key, length);
            }
            break;
    }

    // check if the array is sorted
    bool sorted=true;
    for (i=0; i<length-1; i++) {
        cout << key[i] << '\n';
        if (key[i]>key[i+1]) sorted=false;
    }

    if (sorted) cout << " The array is sorted" << endl;
    else cout << "The array is not sorted" << endl;
    return 1;

    // sample code to test your algorithm with arrays created by yourself
    /*
    int key[];
    int length;
    rsort(key, length);
    for (int i=0; i<length; i++) {
        cout << key[i] <<endl;
    }
    return 1;
    */
}
