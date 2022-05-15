/*
  ****REMEMBER TO WRITE YOUR NAME/ID/ACCOUNT NAME****
  ****     otherwise marks will be DEDUCTED!!!    ****
 
  name:
  student id:
  email:
*/
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//////////////////////////
// enhanced vector class
//////////////////////////
template<typename T>
class evector : public vector<T> {
public:
  //overloaded member function operators += -= + *
  evector& operator+=(const T& t);

  /*  
  evector& operator-=(const T& t);
  evector<T>  operator+   (const evector<T> & E2);
  evector<T>  operator*   (const evector<T> & E2);
  */

  friend ostream& operator<< <T>(ostream&, const evector<T>&);

};





template<typename T>
evector<T>& evector<T>::operator+=(const T& t) {
  for(size_type i = 0; i < size(); i++)
    (*this)[i] += t;
  return *this;
};




template<typename T>
ostream& operator<<(ostream& os, const evector<T>& ev) {
  os << '<';
  for (int i = 0; i < ev.size(); i++)
    os << ev[i] << ' ';
  os << '>';
  return os;
};





//////////////////////////
// main program
//////////////////////////
int main() {
  evector<int> ev;

  ev.push_back(1);
  ev.push_back(2);
  ev.push_back(3);
  ev.push_back(4);
  ev.push_back(5);
  cout << "ev = " << ev << endl;

  ev += 100;
  cout << "ev += 100\n";
  cout << "ev = " << ev << endl;


  /*
  ev -= 10;
  cout << "ev -= 10\n";
  cout << "ev = " << ev << endl;

  evector<int> vec;
  vec.push_back(6);
  vec.push_back(7);
  vec.push_back(8);
  vec.push_back(9);
  vec.push_back(10);
  cout << "vec = " << vec << endl;

  
    evector<int> p = ev * vec;
  cout << "p = ev * vec\n";
  cout << "p = " << p << endl;

  evector<int> vec2;
  vec2.push_back(1);
  vec2.push_back(2);
  cout << "vec2 = " << vec2 << endl;
 
  
  p = ev * vec2;
  cout << "p = ev * vec2\n";
  cout << "p = " << p << endl;
     evector<int> p2;
  p2 = ev + vec;
  cout << "p2 = ev + vec" << endl;
  cout << "p2 = " << p2 << endl;
  */
  return 0;
};
