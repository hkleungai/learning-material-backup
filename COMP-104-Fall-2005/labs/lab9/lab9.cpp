// lab9.cpp		Lab9 model answer

#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
using namespace std;

struct Node{
	string data;
	Node *next;
};
typedef Node* NodePtr;

void addHead(NodePtr& Head, string newdata);
bool removeTail(NodePtr& Head, NodePtr& Tail);
void deleteAll(NodePtr& Head);
void DisplayList(NodePtr Head);
void generate_items(string& temp, int width);
void initialize_list(NodePtr& Head, int width, int height, int man_pos);
void update_list(NodePtr& Head, int width, int& man_pos, int& score, char input);


void main() {
	srand(time(0));

	NodePtr Head=NULL, Tail=NULL;
	int width = 40, height = 20;
	int man_pos = width/2, score = 50;
	char input;


	initialize_list(Head, width, height, man_pos);
	cout << "------------- Falling Money --------------" << endl;
	DisplayList(Head);
	cout << "Your Score: " << score << endl;

	while (score>0 && score <100) {
		// getch(): get char immediately from input, no need to press enter
		// kbhit(): if someone hit the keyboard, return true.
		if (kbhit()) input = getch();

		update_list(Head, width, man_pos, score, input);

		input = '\0';

		// clear the screen and display the list
		system("cls");
		cout << "------------- Falling Money --------------" << endl;
		DisplayList(Head);
		cout << "Your Score: " << score << endl;

		// wait for 10 milliseconds (controling speed)
		Sleep(10);
	}

	if (score >= 100) {
		cout << "Yeah, you win!!" << endl;
	}
	else {
		cout << "Sorry, you lose..." << endl;
	}

	deleteAll(Head);

}




void addHead(NodePtr& Head, string newdata){
	NodePtr newPtr = new Node;
	if(newPtr != NULL){
		newPtr->data = newdata;
		newPtr->next = Head;
		Head = newPtr;
	}
	else {
		cout << "Memory allocation error" << endl;
		exit(1);
	}
}

bool removeTail(NodePtr& Head, NodePtr& Tail) {
	NodePtr cur, prev;
	// check if there are at least 2 elements
	if(Head->next!=NULL) {
		prev= Head;
		cur = Head->next;

		// search for the end of list
		while (cur->next!=NULL) {
			prev = cur;
			cur = cur->next;
		}

		// delete last element
		prev->next = NULL;
		delete cur;
		Tail = prev;
		return true;
	}
	else {
		return false;
	}
}

void deleteAll(NodePtr& Head) {
	NodePtr next;
	while (Head != NULL) {
		next = Head->next;
		delete Head;
		Head = next;
	}
}

void DisplayList(NodePtr Head){
	NodePtr cur;
	cur = Head;
	while(cur != NULL){
		cout << "|" << cur->data << "|" << endl;
		cur = cur->next;
	}
}

void generate_items(string& temp, int width) {
	int j=0, pos;

	// only 2 items for each line, either '$' or '.'
	while (j<2) {
		pos = rand()%width;
		if (temp[pos] == ' ') {
			if (rand()%2) {
				temp[pos]='$';
			}
			else {
				temp[pos]='.';
			}
			j++;
		}
	}
}

void initialize_list(NodePtr& Head, int width, int height, int man_pos) {
	// declare a string of spaces with lenght=width
	string temp(width, ' ');

	addHead(Head, temp);
	Head->data[man_pos] = 'U';

	for(int i=1; i <= height; i++) {
		addHead(Head, temp);
	}
}


void update_list(NodePtr& Head, int width, int& man_pos, int& score, char input) {
	NodePtr Tail=NULL;
	string temp(width, ' ');

	const char CPPKEYLEFT = 75;
	const char CPPKEYRIGHT = 77;

	if (input==CPPKEYLEFT) { // user pressed left arrow key
		man_pos -= 1;
		if (man_pos<0) man_pos += 1;
	}
	else if (input==CPPKEYRIGHT) { // right arrow key
		man_pos += 1;
		if (man_pos>(width-1)) man_pos -= 1;
	}


	if (removeTail(Head, Tail)) {

		// update score, find out what is above man_pos
		if (Tail->data[man_pos] == '$') {
			score += 10;
		}
		else if (Tail->data[man_pos] == '.') {
			score -= 15;
		}

		// update man's position
		Tail->data[man_pos]='U';

		generate_items(temp, width);
		addHead(Head, temp);

	}
}

