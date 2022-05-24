#include <iostream>
#include "randomized_queue.h"

/*
This main program only checks your class, functions' signatures correct or not.
To check the correctness of your program, you may need to use more complicated examples.
*/

using namespace std;

int main(int argc, char ** argv){

	srand(time(0));
	RandomizedQueue<char> rq;

	cout << "Empty? " << rq.isEmpty() << endl;
	cout << "Size? " << rq.size() << endl;
	rq.enqueue('a');
	rq.enqueue('b');
	rq.enqueue('c');
	rq.enqueue('d');
	cout << "Empty? " << rq.isEmpty() << endl;
	cout << "Size? " << rq.size() << endl;

	int i;
	RandomizedQueue<char>::Iterator itr = rq.iterator();
	cout << "queue : ";
	for(i = 0; i < rq.size();i++){
		cout << *itr << " ";
		++itr;
	}
	cout << endl;

	cout << "sampling : " ;
	for(i = 0; i < rq.size()*2;i++){
		cout << rq.sample() << " ";
	}
	cout << endl;

	cout << "dequeue :  " << rq.dequeue() << endl;
	itr = rq.iterator();
	cout << "queue : ";
	for(i = 0; i < rq.size();i++){
		cout << *itr << " ";
		++itr;
	}
	cout << endl;

	return 0;
}