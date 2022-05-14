#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Node{
	string frame;
	Node* next;
	Node* prev;
};
typedef Node* NodePtr;


void append_frame(NodePtr &Head, NodePtr &Rear, string nframe);	//append a frame node to the doubly link list, used in load_tape() function
void load_tape(NodePtr &Head, string filename);  //load a movie text file to the memory and store in doubly link list 
void play_forward(NodePtr &ptr);	//play forward a frame
void play_backward(NodePtr &ptr);	//play backward a frame
void copy_frame(NodePtr &ptr);	//duplicate the current frame pointed to by ptr
void delete_frame(NodePtr &Head, NodePtr &ptr);	//delete the current frame pointed to by ptr
void stop(NodePtr Head, NodePtr &ptr);	//stops the player and moves ptr back to Head
void start_104player(NodePtr &Head);	//movie player control
void erase_tape(NodePtr &Head);	//free the memory
void menu();	//player menu

void main(){
	NodePtr Head = NULL;
	string filename;
	cout << "input filename: ";
	cin >> filename;
	load_tape(Head, filename);
	start_104player(Head);
	erase_tape(Head);
}

//this function is given to the students
void start_104player(NodePtr &Head){
	NodePtr ptr = Head;
	char input = 's';
	int time = 100;	//control playback speed
	do{
		if (kbhit()) 
			input = getch();
		switch(input){
		case 'f':	
			system("cls");
			play_forward(ptr);
			menu();
			Sleep(time);
			break;
		case 'b':	
			system("cls");
			play_backward(ptr);
			menu();
			Sleep(time);
			break;
		case 's':	
			system("cls");
			stop(Head, ptr);
			menu();
			input = ' ';
			break;
		case 'p':	
			input = ' ';
			break;
		case 'd':	
			system("cls");
			delete_frame(Head, ptr);
			menu();
			input = ' ';
			break;
		case 'c':	
			copy_frame(ptr);
			input = ' ';
			break;
		}
	}while(input != 'x');
}


//this function is given to the students
void menu(){
	cout << "press f for forward\n"
		 << "press b for backward\n"
		 << "press p for pause\n"
		 << "press s for stop\n"
		 << "press d for delete current frame\n"
		 << "press c for copy current frame\n"
		 << "press x to exit\n";
}

//this function is given to the students
void load_tape(NodePtr &Head, string filename){
	string nframe = "";
	char c;
	NodePtr Rear = NULL;
	ifstream fin(filename.c_str());
	while(!fin.eof()){
		nframe = "";
		for(int i=0; i<14; i++){
			do{
				c = fin.get();
				if(fin.eof())
					return;
				nframe+=c;
			}while(c != '\n');
		}
		//append a frame node to the doubly link list
		append_frame(Head, Rear, nframe);
	}
	fin.close();
}

void append_frame(NodePtr &Head, NodePtr &Rear, string nframe){
	NodePtr n = new Node;
	n->frame = nframe;
	n->next = NULL;
	n->prev = NULL;
	if(Head == NULL){
		Head = Rear = n;
	}
	else{
		Rear->next = n;
		n->prev = Rear;
		Rear = n;
	}
}

void play_forward(NodePtr &ptr){
	system("cls");
	if(ptr!=NULL){
		if(ptr->next != NULL){
			ptr = ptr->next;
			cout<<ptr->frame;
		}
		else{
			cout<<ptr->frame;
			cout<<"no more forward\n";
		}
	}
	else
		cout<<"no more forward\n";
}

void play_backward(NodePtr &ptr){
	system("cls");
	if(ptr!=NULL){
		if(ptr->prev != NULL){
			ptr = ptr->prev;
			cout<<ptr->frame;
		}
		else{
			cout<<ptr->frame;
			cout<<"no more backward\n";
		}
	}
	else
		cout<<"no more backward\n";
}

void copy_frame(NodePtr &ptr){
	if(ptr != NULL){
		NodePtr dupl = new Node;
		dupl->frame = ptr->frame;
		dupl->prev = ptr;
		dupl->next = ptr->next;
		if(ptr->next != NULL)
			ptr->next->prev = dupl;
		ptr->next = dupl;
	}
}

void delete_frame(NodePtr & Head, NodePtr & ptr){
	system("cls");
	if(ptr == NULL){
		Head = NULL;
		cout<<"no more delete\n";
		return;
	}

	NodePtr temp = ptr;

	if(ptr->next!=NULL && ptr->prev!=NULL){
		ptr = ptr->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	else if(ptr->prev==NULL && ptr->next != NULL){
		ptr = ptr->next;
		Head = ptr;
		temp->next->prev = NULL;
	}
	else if(ptr->next==NULL && ptr->prev != NULL){
		ptr = ptr->prev;
		temp->prev->next = NULL;
	}else{
		ptr = NULL;
		Head = NULL;
		cout<<"no more delete"<<endl;
	}
	delete temp;
	if(ptr != NULL){
		cout<<ptr->frame;
	}
}

void stop(NodePtr Head, NodePtr &ptr){
	ptr = Head;
	if(Head!=NULL)
		cout << ptr->frame;
}

void erase_tape(NodePtr &Head){
	NodePtr temp;
	while(Head != NULL){
		temp = Head;
		Head = Head->next;
		delete temp;
	}
}


