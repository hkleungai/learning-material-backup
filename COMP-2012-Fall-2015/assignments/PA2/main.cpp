#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Polynomial.h"

using namespace std;

// Testing PolyList and PolyNode functions
void testList(ostream& out)
{
   PolyList alist;
   if (alist.empty())
      out << "alist empty\n";
   else
      out << "alist not empty\n";

   PolyNode* tmp = new PolyNode(2,3,5);
   alist.attachNode(tmp);
   alist.attachNode(new PolyNode(1,0,0));
   out << "length of alist=" << alist.length() << endl;
 
   tmp = alist[0];
   out << "before delete\n";
   out << "alist:" << tmp->coef << "," << tmp->expx << "," << tmp->expy << endl;
   tmp = alist[1];
   out << "alist:" << tmp->coef << "," << tmp->expx << "," << tmp->expy << endl;
   alist.deleteHead();

   out << "after delete\n";
   tmp = alist[0];
   out << "alist:" << tmp->coef << "," << tmp->expx << "," << tmp->expy << endl;

   PolyList blist;
   blist.attachNode(new PolyNode(1,1,1));
   blist.attachNode(new PolyNode(1,0,0));
   
   if (alist==blist)
      out << "alist is equal to blist\n";
   out << "alist=blist\n";
   alist=blist;
   if (alist==blist)
      out << "alist is equal to blist\n";
}

int main(int argc, char* argv[])
{
   Polynomial a, b, c;

   streambuf* buf;
   ofstream of;
   if (argc > 1) {
     of.open(argv[1]);
     buf = of.rdbuf();
   } else {
     buf = std::cout.rdbuf();
   }
   ostream out(buf);

   out << "=== Testing PolyList functions: ===\n";
   testList(out);  

   out << "=== Testing Polynomial functions: ===\n";

   out << "--- testing input/output operators: ---\n";
   ifstream ifs("input.txt");
   out << "Input polynomial a...";
   ifs >> a;
   out << "end\n";
   out << "Input polynomial b...";
   ifs >> b;
   out << "end\n";
   out << "By printPoly(), polynomial a=";
   a.printPoly(out);
   out << endl; 
   out << "By operator<<, polynomial a=" << a << endl; 
 
   out << "By printPoly(), polynomial b=";
   b.printPoly(out);
   out << endl; 
   out << "By operator<<. polynomial b=" << b << endl; 

   out << "--- testing operator=: ---\n";
   c=b;
   c=a;
   out << "Polynomial c=" << c << endl;

   out << "--- testing dx(): ---\n";
   out << a.dx() << endl;
   
   out << "--- testing copy constructor: ---\n";
   Polynomial d(b);
   out << "Polynomial d=" << d << endl;

   out << "--- testing operator(): ---\n";
   int x=0, y=0;
   out << "Evaluate the polynomial a at (input two integer numbers):\n";
   out << "x=";
   ifs >> x;
   out << "y=";
   ifs >> y;
   out << "a(" << x << "," << y << ")=" << a(x,y) << endl;

   out << "--- testing operator== ---\n";
   if (a==b) out << "a is equal to b." << endl;
   else out << "a is not equal to b." << endl;

   out << "--- testing operator+ ---\n";
   out << "a+b=" << a+b << endl;
   out << "10+b=" << 10+b << endl;
   out << "b+10=" << b+10 << endl;

   out << "--- testing operator- ---\n";
   out << "a-b=" << a-b << endl;
   out << "10-b=" << 10-b << endl;
   out << "b-10=" << b-10 << endl;

   out << "--- testing operator- ---\n";
   out << "a*b=" << a*b << endl; 
   out << "10*b=" << 10*b << endl;
   out << "b*10=" << b*10 << endl;

   out << "--- testing operator+= ---\n";
   c+=b;
   out << "c+=b; c=" << c << endl;
   c+=10;
   out << "c+=10; c=" << c << endl;

   
   out << "--- testing operator-= ---\n";
   c-=b;
   out << "c-=b; c=" << c << endl;
   c-=10;
   out << "c-=10; c=" << c << endl;

   out << "--- testing operator*= ---\n";
   d*=a;
   out << "d*=a; d=" << d << endl;
   d*=10;
   out << "d*=10; d=" << d << endl;

   return (0); 
}
