// Lang.hpp
// Header File for Lang

#ifndef LANG_H 
#define LANG_H 


#include <string>

using namespace std;

class Lang
{ 
public:
  // Basic constructor
  // sets the language code to be lc
  Lang(string lc);
  
  // True if the language is "en"
  bool isEnglish();

  // True if the language is "zh"
  bool isChinese();

 private:
  string langcode;
};


#endif // LANG_H
