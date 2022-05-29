#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>

#include "Polynomial.h"

using namespace std;

// extractExpon("x^60y", expx, expy)
void extractExpon(const string str, int& expx, int& expy)
{
    size_t foundx = str.find('x');
    size_t foundy = str.find('y');
    string strx="", stry="";
    
    if (foundx != string::npos){
      if (foundy != string::npos) {
        strx = str.substr(0, foundy);
        stry = str.substr(foundy);
      } else 
        strx = str;
    } else if (foundy != string::npos) {
      stry = str; 
    }   
    size_t findxat=string::npos, findyat=string::npos;
    if (strx != "") {
      findxat = strx.find('^');
      if (findxat != string::npos)
        expx = atoi(strx.substr(findxat+1).c_str()); 
      else
        expx = 1;
    } else 
      expx = 0;
    if (stry != "") {
      findyat = stry.find('^');
      if (findyat != string::npos)
        expy = atoi(stry.substr(findyat+1).c_str()); 
      else 
        expy = 1;
    } else 
      expy = 0;
}

void Polynomial::readPoly(const string& str)
{
  PolyNode* front, rear, temp;
  int coef, expx, expy;

  polyList.~PolyList();

  string str1(str);
  int pos=0;
  while (pos < (int)str1.size())
  {
    size_t foundplus, foundminus;
    if (str1.find("+", pos) < str1.find('-', pos) || ( str1.find('-', pos) == string::npos))
       foundplus = str1.find("+", pos);
    else 
       foundplus =  str1.find('-', pos);
    string str;
    if (foundplus == 0)
      pos++;
    else 
    {
      int length;
      if (foundplus != string::npos) 
      {
        length = foundplus-pos;
        if (pos > 0)
          str=str1.substr(pos-1, length+1);
        else 
          str=str1.substr(pos, length);
      } else 
      {
        length=str1.size()-pos;
        if (pos > 0)
          str=str1.substr(pos-1, length+1);
        else 
          str=str1.substr(pos, length);
      }

      size_t found, foundy;
      found = str.find('x');
      if (found == string::npos)
        found = str.find('y');

      if (found != string::npos)
      {
        if (found == str.size()-1)
        {
          if (str.substr(0,found) == "-")
            coef = -1;
          else if (str.substr(0,found) == "")
            coef = 1;
          else if (str.substr(0,found) == "+")
            coef = 1;
          else 
            coef = atoi(str.substr(0, found).c_str());
          extractExpon(str.substr(found).c_str(), expx, expy);
        } 
        else if (found == 0) 
        {
          coef = 1;
          extractExpon(str.substr(found).c_str(), expx, expy);
        } 
        else 
        {
          if (str.substr(0,found-0) == "-")
             coef = -1;
          else if (str.substr(0, found-0) == "+")
             coef = 1;
          else 
             coef = atoi(str.substr(0, found-0).c_str());
          extractExpon(str.substr(found).c_str(), expx, expy);
        }
      } 
      else 
      {
        coef = atoi(str.c_str());
        expx = 0;
        expy = 0;
      }
      if (coef != 0) {
        PolyNode* newNode = new PolyNode(coef, expx, expy); 
        polyList.attachNode(newNode);
      }
      pos += (length+1);
    } 
  }
  sortPoly();
}


