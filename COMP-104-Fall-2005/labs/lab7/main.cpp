// main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "lab7.h"
using namespace std;


void main() {
  string towers[3];  //the contents of the three towers
  ifstream fin;
  ofstream fout;

  fin.open("initial_state.txt"); //open the file containing the initial state
  fin >> towers[0] >> towers[1] >> towers[2]; 
  //read in the initial states of the three towers
  fin.close(); //done with the input file

  fout.open("solution.txt"); //open the output file for storing a sequence
  //operators that will achieve the goal, and all the intermediate states
  fout << "A: " << towers[0] << endl  
       << "B: " << towers[1] << endl
       << "C: " << towers[2] << endl;
  //write the initial state to the output file first
  
  //the first letter needs to be put into its position with special care
  //as it may need to clear the entire tower A first.
  //the rest of the letters can be put into their position using a common
  //routine
  achieve_first_letter(towers,fout);
  achieve_rest_letter(towers,'r',1,fout);
  achieve_rest_letter(towers,'u',2,fout);
  achieve_rest_letter(towers,'i',3,fout);
  achieve_rest_letter(towers,'t',4,fout);
  achieve_rest_letter(towers,'c',5,fout);
  achieve_rest_letter(towers,'a',6,fout);
  achieve_rest_letter(towers,'k',7,fout);
  achieve_rest_letter(towers,'e',8,fout);
  fout.close();
}
