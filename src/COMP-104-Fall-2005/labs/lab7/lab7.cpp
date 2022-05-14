// lab7.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "lab7.h"
using namespace std;



//find which tower, towers[1] (B) or towers[2] (C), contains a given letter
int locate_a_letter(char c, string towers[3]) {
  int i;
  for (i=0;i<towers[1].length();i++) 
    if (towers[1][i]==c) return 1;
  return 2;
}


//execute a moving action
void move(string towers[3],int i,int j,ofstream& fout) {
  fout << "move(" << Tower_Name[i] << "," 
       << Tower_Name[j] << ")" << endl; //write the action to the file
  //carry out the effect of the action
  towers[j] = towers[j] + towers[i].substr(towers[i].length()-1,1);
  towers[i] = towers[i].substr(0,towers[i].length()-1);
  fout << "A: " << towers[0] << endl  
       << "B: " << towers[1] << endl
       << "C: " << towers[2] << endl;
  //write the new state to the file
  return;  
}

//loation the position of a letter in a string; if not found, return -1

int locate_position(char c, string s) {
  for (int i=0; i<s.length(); i++)
    if (s[i]==c) return i;
  return -1;
}

//clear the letters on top of a given letter in tower i using tower j 
//as the dump, and write the results to fout
void clear(char c, int t1, int t2, string towers[3], ofstream& fout) {
  int k = towers[t1].length();
  int pos = locate_position(c,towers[t1]);
  if (towers[t1][k-1] != c) //check if already clear
    for (int i=k-1; i > pos; i--)
      move(towers,t1,t2,fout);
}

//put 'f' into the bottom of tower A if it is not already there
void achieve_first_letter(string towers[3],ofstream& fout) {
  if (towers[0].length() !=0 && towers[0][0]=='f') clear('f', 0, 1, towers, fout); 
  //return if 'f' is already in the right position
  if (towers[0].length() != 0)    //otherwise, clear tower A first
    {
      int j = towers[0].length();
      for (int i=0; i<j; i++) 
      move(towers,0,1,fout);
    }
  int index = locate_a_letter('f',towers); //find out which tower has 'f'
  int dump; //use to denote the other tower to clear 'f'
  if (index == 1) dump = 2;
  else dump = 1;
  clear('f',index,dump,towers,fout); //make 'f' clear
  move(towers,index,0,fout); //move 'f' to its destination - tower A
}

void achieve_rest_letter(string towers[3], char c, int pos, ofstream& fout) {
  if (towers[0].length() > pos && towers[0][pos] == c) return;
  //if it is already in the right position, then return
  //the rest is the same as in achieve_first_letter()
  int index = locate_a_letter(c,towers); //find out which tower has c
  int dump; //use to denote the other tower to clear c
  if (index == 1) dump = 2;
  else dump = 1;
  clear(c,index,dump,towers,fout); //make c clear first
  move(towers,index,0,fout); //move c to its destination - tower A
}

