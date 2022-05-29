#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Student {
private:
	string name;
	int id;
	string department;

public:
	Student (string _name, int _id, string _department): name (_name), id (_id), department (_department) { }

	string getName () const { return name; }
	int getId () const { return id; }
	string getDepartment () const { return department; }

	friend ostream & operator << (ostream & os, const Student & s) {
		os << '<' << s.name << ", " << s.id << ", " << s.department << '>';
		return os;
	}
};

int main() {
	//////////////////////////////////////////
	// code 1: insert data to the containers
	//////////////////////////////////////////

	// data
	string names[] = {"Alex", "Michael", "Olivia", "Grace", "David"};
	int id[] = {1, 2, 3, 4, 5};
	string dept[] = {"math", "comp", "math", "math", "comp"};
	const int size = sizeof (names) / sizeof (names[0]);

	// insert all data to the vector students
	vector < Student * > students;

	int i =0;
	for (i = 0; i < size; i++) {
		students.push_back (new Student (names[i], id[i], dept[i]));
	}

	// dept-to-student
	typedef multimap < string, Student *, less < string > > DeptToStudentPtr;
	DeptToStudentPtr deptMap;
	for (i = 0; i < size; i++) {
		deptMap.insert (DeptToStudentPtr::value_type (dept[i], students[i]) );
	}

	//////////////////////////////////////////
	// code 2: search info from containers
	//////////////////////////////////////////

	cout << "d to search via department" << endl
	   << "q to quit" << endl;
	char command;
	bool isQuit = false;
	while ( !isQuit && (cout << "> ") && (cin >> command) ) {
		switch (command) {
		case 'd': {
			string input;
			cin >> input;
			typedef DeptToStudentPtr::const_iterator Dts_Const_Itr;
			pair < Dts_Const_Itr, Dts_Const_Itr > p = deptMap.equal_range (input);
			if (p.first != p.second) {
				Dts_Const_Itr i = p.first;
				while (i != p.second) {
					cout << *(i->second) << endl;
					i++;
				}
			}
			else {
				cout << "not found!" << endl;
			}
		}
			break; // break of case 'd'

		case 'q':
			isQuit = true;
			break; // break of case 'q'

		default:
			cout << "bad command" << endl;
			break;
		}
		cout << "d to search via department" << endl
		<<"q to quit" << endl;
	}

	//////////////////////////////////////////
	// code 3: release all Student objects
	//////////////////////////////////////////
	vector < Student * >::iterator itr = students.begin ();
	while (itr != students.end ()) {
		delete (*itr);
		itr++;
	}
	return 0;
}
