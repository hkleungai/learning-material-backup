// Lang.cpp
// Implementation file for the Lang class

#include "Lang.hpp"

using namespace std;

Lang::Lang(string lc)
{
  langcode = lc;
}
  
bool Lang::isEnglish()
{
  return (langcode == "en");
}

bool Lang::isChinese()
{
  return (langcode == "zh");
}
