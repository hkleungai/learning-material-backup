#include <string>
#include <iostream>
using namespace std;    

template<class T>
void swap(const T& x, const T& y)
{
  T tmp = x;
  x = y;
  y = tmp;
} 


int main()
{
  int i,j;  
  i=1;j=2;       
  swap(i,j);  // Instantiates a swap for int
  cout << i << "," << j << endl;

  float a,b;  
  a=1.0;b=2.0;   
  swap(a,b);  // Instantiates a swap for float
  cout << a << "," << b << endl;
  
  char c,d;  
  c='c';d='d';   
  swap(c,d);  // Instantiates a swap for char
  cout << c << "," << d << endl;
  
  string s,t;  
  s="string1";t="string2";  
  swap(s,t);  // Instantiates a swap for string
  cout << s << "," << t << endl;
  
  return 0;
} 

