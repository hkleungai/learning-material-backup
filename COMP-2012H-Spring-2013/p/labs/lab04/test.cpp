#include <iostream>
using namespace std;

class Word
{
public:
	Word () { cout << "D" <<endl;}
	Word (char* s1) { cout <<s1 << endl;}
	Word (const Word & w) { cout <<"C\n";}
	Word & operator= (const Word & w) { cout <<"A\n"; return *this;}
};

class Word_Pair 
{
public:
	Word w1;
	Word w2;
	//Word_Pair (char *s1, char *s2) : w1(s1), w2(s2) {}
	Word_Pair (char *s1, char *s2) 
	{
		w1 = s1; 
		w2=s2;
	}		
};


int main ()
{
	Word_Pair p("hello", "world");
	return 0;
}