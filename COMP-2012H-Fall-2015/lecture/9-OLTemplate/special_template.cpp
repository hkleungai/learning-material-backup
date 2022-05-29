#include <iostream>
#include <vector>
using namespace std;

template< typename T = double, int size = 20 >
class foo{
public:
  foo(){
    number_obj++;
    for( int i = 0; i < size; i++ )
      data[ i ] = count + i;
  }
  void display( void ) const{
    for( int i = 0; i < size; i++ )
      cout << data[ i ] << " ";
    cout << endl;
  }
  ~foo(){
    number_obj--;
  }
  static void getinfo( void ) {
    cout << "count = " << count << "; # obj.=" << number_obj << endl;
  }
private:
  static int number_obj;  // number of objects for the class foo<T,size>
  static int count;  // start count of data in the object
  T data[ size ];   
};

template<typename T, int size> int foo<T, size>::number_obj = 0;

template<typename T, int size> int foo<T, size>::count = 1;
// Each specialized class gets the starting count of 1
// must have 2 parameters

// A tailor-made specialization for char and size 10
template<> int foo<char,10>::count = 'A';
// Gets a count of 65
// foo must have 2 parameters

int main(){

  foo<int, 10>::getinfo();  // count = 0
  foo<double>::getinfo();   // count = 0
  foo<char, 10>::getinfo();  // a specialized class with count = 65
  
  foo< int, 10 > i1,i2;       // overwrite default size
  foo<> d1, d2, d3;           // use default 
  foo< double > d4;           // this is the same as default
  foo< char, 10 > c;          // a specialization class
  
  i1.display();  // each gets a count and number_obj
  d2.display();  // each gets a count and number_obj
  d4.display();  // same class as d1, d2, and d3
  c.display();   // specialized class

  i1.getinfo();
  d2.getinfo();  // 4 objects (d1-d4)
  c.getinfo();

  return 0;
}
