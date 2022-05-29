/*-------------------------------------------------------------------------
           Program to demonstrate use of STL's deque container.
  ------------------------------------------------------------------------*/
#include <deque>
#include <iostream>
using namespace std;

int main()
{
  deque<int> d;
  
  // Output number of values stored in d
  cout << d.size() << " elements in an empty deque\n";

  // Add first 6 integers alternately to front and back
  for (int i = 1; i <= 6; i += 2)
    {
      d.push_front(i);
      d.push_back(i+1);
    }
  cout << "Contents after alternating adds at front and back:\n";
  for (int i = 0; i < d.size(); i++)
    cout << d[i] << "  ";
  cout << endl;
  
  // Change back value to 999, remove front value;
  d.back() = 999; 
  d.pop_front();
  
  // Display contents of d again, but use an iterator
  cout << "Contents (via iterators) after changing back "
    "and popping front:\n";
  for (deque<int>::iterator it = d.begin(); 
       it != d.end(); it++)
    cout << *it << "  ";
  cout << endl;
  
  // Dump contents of d from back to front
  cout << "Dumping the deque from the back:\n";
  while (!d.empty())
    {
      cout << d.back() << "  ";
      d.pop_back();
    }
  cout << endl;
  return 0;
}
