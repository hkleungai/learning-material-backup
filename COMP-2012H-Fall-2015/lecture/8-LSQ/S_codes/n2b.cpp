#include <iostream>

using namespace std;

// write out a decimal number in its binary form
void binary( int n ){

  if( n == 0 )
    return;
  binary( n/2 );
  cout << n%2 << " ";
}

int main( int argc, char * argv[]){
  int n;
  if( argc != 2 ){
    cout << "Integer to binary usage: " << argv[0] << " <integer>\n";
    exit( -1 );
  }
  
  n = atoi( argv[ 1 ] );
  cout << n << " = ";
  binary( n );
  cout << "\n";

  return 1;
}
