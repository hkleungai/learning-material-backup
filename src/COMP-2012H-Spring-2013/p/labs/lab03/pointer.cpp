//YourName, Lab Session
//pointer.cpp
//Introduction of Pointer

#include <iostream>

using namespace std;

void main()
{
    int *p, *q;
    int a,b;
    
    a = 10;
    b = 20;
    p=&a;       // p is a pointer variable pointed to the address of a
    q=&b;       // q is a pointer variable pointed to the address of b
    
    //What is the difference between 
    //			1.	*p=*q and 
    //			2.	p=q  ?
    cout<<"\n The value of a             : "<<  a ;  // the value of a
    cout<<"\n The address of a           : "<<  &a ; // the address of a 
    cout<<"\n The value of b             : "<<  b ;  // the value of b 
    cout<<"\n The address of b           : "<<  &b ; // the address of b
    cout<<"\n The value of p (address)   : "<<  p ;  // the value of p
    cout<<"\n The value that p points to : "<<  *p ; // the value that pointed by p
    cout<<"\n The address of p           : "<<  &p ; // the address of p
    cout<<"\n The value of q (address)   : "<<  q ;  // the value of q
    cout<<"\n The value that q points to : "<<  *q ; // the value that q points to 
    cout<<"\n The address of q           : "<<  &q ; // the address of q
    cout<<"\n ==========================================="<<endl;
    
    
    *p = *q;    // change the value of address that pointed by p to the value pointed by q
    *q = 30;    // change the value of address that pointed by q to 30
    
    cout<<"\n The value of a             : "<<  a ;  // the value of a
    cout<<"\n The address of a           : "<<  &a ; // the address of a 
    cout<<"\n The value of b             : "<<  b ;  // the value of b 
    cout<<"\n The address of b           : "<<  &b ; // the address of b
    cout<<"\n The value of p (address)   : "<<  p ;  // the value of p
    cout<<"\n The value that p points to : "<<  *p ; // the value that pointed by p
    cout<<"\n The address of p           : "<<  &p ; // the address of p
    cout<<"\n The value of q (address)   : "<<  q ;  // the value of q
    cout<<"\n The value that q points to : "<<  *q ; // the value that q points to 
    cout<<"\n The address of q           : "<<  &q ; // the address of q
    cout<<"\n ==========================================="<<endl;    
    
    p = q;      // p is now pointing to the same address as q
    *q = 40;    // change the value that pointed by q to 40
    
    cout<<"\n The value of a             : "<<  a ;  // the value of a
    cout<<"\n The address of a           : "<<  &a ; // the address of a 
    cout<<"\n The value of b             : "<<  b ;  // the value of b 
    cout<<"\n The address of b           : "<<  &b ; // the address of b
    cout<<"\n The value of p (address)   : "<<  p ;  // the value of p
    cout<<"\n The value that p points to : "<<  *p ; // the value that pointed by p
    cout<<"\n The address of p           : "<<  &p ; // the address of p
    cout<<"\n The value of q (address)   : "<<  q ;  // the value of q
    cout<<"\n The value that q points to : "<<  *q ; // the value that q points to 
    cout<<"\n The address of q           : "<<  &q ; // the address of q
    cout<<"\n ==========================================="<<endl;    
    
    
    //What is the difference between
    //			1.	reference 
    //			2.	pointers
    
    int &refa = a;      // refa is an alias of a
    p = &a;             // p is pointed to memory address of a		
        
    cout<<"\n The value of a             : "<<  a ;     // the value of a
    cout<<"\n The value of refa          : "<<  refa ;  // the value of refa    		
    cout<<"\n The address of a           : "<<  &a ;    // the address of a
    cout<<"\n The address of refa        : "<<  &refa ; // the address of refa
    cout<<"\n The value of p (address)   : "<<  p ;     // contains a's memory address
    cout<<"\n The value that p points to : "<<  *p ;    // the value that pointed by p
    cout<<"\n The address of p           : "<<  &p ;    // p's  memory location
    cout<<"\n ==========================================="<<endl;
    
    
    refa = 3;           // change the value of refa
    cout<<"\n The value of a             : "<<  a ;     // the value of a
    cout<<"\n The value of refa          : "<<  refa ;  // the value of refa    		
    cout<<"\n The address of a           : "<<  &a ;    // the address of a
    cout<<"\n The address of refa        : "<<  &refa ; // the address of refa
    cout<<"\n The value of p (address)   : "<<  p ;     // contains a's memory address
    cout<<"\n The value that p points to : "<<  *p ;    // the value that pointed by p
    cout<<"\n The address of p           : "<<  &p ;    // p's  memory location
    cout<<"\n ==========================================="<<endl;
}



