#ifndef FANGZHEN_LIN_LAB7_H
#define FANGZHEN_LIN_LAB7_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char Tower_Name[3]={'A', 'B', 'C'}; //Names for the three towers

//return 1 if tower B contains letter 'c', and return 2 if tower C
//contains the letter
int locate_a_letter(char c, string towers[3]);

//execute a moving action, including writing it to the output file
void move(string towers[3],int i,int j,ofstream& fout);

//loation the position of a letter in a string; if not found, return -1
int locate_position(char c, string s);

//clear the letters on top of a given letter in tower i using tower j 
//as the dump, and write the results to fout
void clear(char c, int t1, int t2, string towers[3], ofstream& fout);

//put 'f' into the bottom of tower A if it is not already there
void achieve_first_letter(string towers[3],ofstream& fout);

//put a letter c into its position pos in the goal state
void achieve_rest_letter(string towers[3], char c, int pos, ofstream& fout);

#endif //FANGZHEN_LIN_LAB7_H
