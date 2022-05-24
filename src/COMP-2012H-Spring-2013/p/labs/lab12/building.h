//building.h
//header file for building

#include <vector>
#include <string>
using namespace std;

class building
{
public:
  
  //Default Constructor
  //Creates new building with all rooms empty
  building();

  //Constructor
  //Creates a new building with one person with name s[ ] and ID number N[], 
  //into room 0 on floor 0.
  building(const char s[ ], const char N[ ]);
  
  //Puts person with name s[] and number N into
  //room on floor f and room number n
  void Put(const char s[], const char N[], int f, int n);
  
  //Defines room on floor f and number n to be empty
  void Empty(int f, int n);
  
  //Prints name/ID No. of occupant of room
  //on floor f and number n
  //If room is empty prints message
  //"Room n on floor f is empty"
  //where n,f are replaced by the appropriate values
  void Display(int f, int n);
  
  //Prints, in alphabetical order,
  //one person per line, the
  //name/ID No of all occupants of floor f
  //If floor is empty prints message
  //"Floor f is empty"
  //where f is replaced by the appropriate values
  void Display(int f);
  
  //Prints, in alphabetical order,
  // name/ID Nos  of all occupants of building
  //If building is empty prints message
  //"Building is empty"
  void Display();
  
  //returns the number of empty rooms on floor f
  int Vacancies(int f) const;
  
  //returns the number of empty rooms in the building
  int Vacancies() const;

  //Overloads the << operator for  buildings, such that it prints  the names of the persons that occupy a building.
  friend ostream& operator<<(ostream& os, const building& b);
  
  //Overloads the ==operator so that it returns true if two buildings have the same
  //number of persons otherwise false
  friend bool operator==(const building& b1, const building& b2);

  //Prints YOUR name, ID Number, Lecture and Lab section
  //This will be used for marking purposes
  void Identify_Writer();
  
private:

  // check if f is an valid floor number or not
  bool IsValidFloor(int f) const;

  // check if f is an valid room number or not
  bool IsValidRoom(int r) const;

  // check if floor f, room r is valid
  bool IsValid(int f, int r) const;

  /*
    names & ids are 2D array using vector to implement them.

    names[i] refers to the occupant name at the (i+1) floor. The type is
    an array/vector of class string (i.e. vector<string>).

    names[i][j] refers to the occupant name at the (i+1) floor in (j+1)
    room. The type is class string.
  */
  vector< vector<string> > names;
  vector< vector<string> > ids;
};

