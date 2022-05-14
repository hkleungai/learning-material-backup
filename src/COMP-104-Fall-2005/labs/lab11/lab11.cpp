#include "lab11.h"

player::player(string filename){
	Head = NULL;
	Cur = NULL;
	load_tape(filename);
	Cur = Head;
}

void player::append_frame(string frame){
	if(Head == NULL){
		Head = new Node;
		Head->frame = frame;
		Head->next = NULL;
		Head->prev = NULL;
		Cur = Head;
	}else{
		Cur->next = new Node;
		Cur->next->frame = frame;
		Cur->next->next = NULL;
		Cur->next->prev = Cur;
		Cur = Cur->next;
	}
}

void player::erase_tape(){
	while(Head != NULL){
		Node * temp = Head;
		Head = Head->next;
		delete temp;
	}
	Cur = NULL;
}

void player::load_tape(string filename){
	string frame = "";
	char c;
	Node* temp = NULL;
	ifstream fin(filename.c_str());
	
	while(!fin.eof()){
		frame = "";
		for(int i=0; i<14; i++){
			do{
				c = fin.get();
				if(fin.eof())
					return;
				frame+=c;
			}while(c != '\n');
		}
		//append a frame node to the doubly link list
		append_frame(frame);
	}
	fin.close();
}

void player::start(){
	char input = 's';
	int time = 100;	//control playback speed
	do{
		if (kbhit()) 
			input = getch();
		switch(input){
			case 'f':	play_forward();
						menu();
						Sleep(time);
						break;
			case 'b':	play_backward();
						menu();
						Sleep(time);
						break;
			case 's':	stop();
						menu();
						input = ' ';
						break;
			case 'p':	input = ' ';
						break;
			case 'd':	delete_frame();
						menu();
						input = ' ';
						break;
			case 'c':	copy_frame();
						input = ' ';
						break;
		}
	}while(input != 'x');
}

void player::play_forward(){
	system("cls");
	if(Cur!=NULL){
		if(Cur->next != NULL){
			Cur = Cur->next;
			cout<<Cur->frame;
		}
		else{
			cout<<Cur->frame;
			cout<<"no more forward\n";
		}
	}
	else
		cout<<"no more forward\n";
}

void player::play_backward(){
	system("cls");
	if(Cur!=NULL){
		if(Cur->prev != NULL){
			Cur = Cur->prev;
			cout<<Cur->frame;
		}
		else{
			cout<<Cur->frame;
			cout<<"no more backward\n";
		}
	}
	else
		cout<<"no more backward\n";
}

void player::stop(){
	Cur = Head;
	if(Cur != NULL){
		system("cls");
		cout<<Cur->frame;
	}
}

void player::menu(){
	cout<<"press f for forward\n"
		<<"press b for backward\n"
		<<"press p for pause\n"
		<<"press s for stop\n"
		<<"press d for delete current frame\n"
		<<"press c for copy current frame\n"
		<<"press x to exit\n";
}

void player::copy_frame(){
	if(Cur != NULL){
		Node* dupl = new Node;
		dupl->frame = Cur->frame;
		dupl->prev = Cur;
		dupl->next = Cur->next;
		if(Cur->next != NULL)
			Cur->next->prev = dupl;
		Cur->next = dupl;
	}
}

void player::delete_frame(){
	system("cls");
	if(Cur == NULL){
		Head = NULL;
		cout<<"no more delete\n";
		return;
	}

	Node* temp = Cur;

	if(Cur->next!=NULL && Cur->prev!=NULL){
		Cur = Cur->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	else if(Cur->prev==NULL && Cur->next != NULL){
		Cur = Cur->next;
		Head = Cur;
		temp->next->prev = NULL;
	}
	else if(Cur->next==NULL && Cur->prev != NULL){
		Cur = Cur->prev;
		temp->prev->next = NULL;
	}else{
		Cur = NULL;
		Head = NULL;
		cout<<"no more delete"<<endl;
	}
	delete temp;
	if(Cur != NULL){
		cout<<Cur->frame;
	}
}
