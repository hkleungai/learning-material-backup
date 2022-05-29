#include <iostream>
#include "List.h"

using namespace std;

/******************* member functions *******************/
PolyList::PolyList()
{
  head=NULL;
  tail=NULL;
}

bool PolyList::empty() const
{
  if (head!=NULL) return false;
  else return true;
}

//////////////////////////////////////////////////////////
// add your implementation for the member functions below
// ...

