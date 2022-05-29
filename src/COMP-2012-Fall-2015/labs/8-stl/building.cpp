#define MY_NAME "My name"
#define MY_STU_ID "12345678"

//building.cpp

#include <iostream>  //Library file so uses <>
#include <algorithm>
#include "building.h"

using namespace std;


building::building()
: names(0, vector<string>(0)),
  ids(0, vector<string>(0))
{
}

building::building(const int f, const int r)
: names(f, vector<string>(r)),
  ids(f, vector<string>(r))
{
}

building::building(const int f, const int r, const char theName[], const char theID[])
: names(f, vector<string>(r)),
  ids(f, vector<string>(r))
{
	//... put person with name s[ ] and ID number N[]
	//... into room 0 on floor 0
}

void building::Put(const char s[], const char ID[], int f, int n)
{
  //... check if f and n are valid
  //... update the room info
}

void building::Empty(int f, int r)
{
    if (IsValidRoom(f,r))
		names[f][r] = "";
}

void building::Display(int f, int r)
{
  if (IsValidRoom(f, r)) {
    if (IsEmpty(f,r))
    {
      cout << "Room " << r << " on floor " << f << " is empty" << endl;
    }
    else
    {
      cout << "Occupant of Room " << r << " on floor " << f;
      cout << " is " << names[f][r];
      cout << ", Identity number "  << ids[f][r] << endl;
    }
  }
}

void building::Display(int f)
{
  if (IsValidFloor(f)) {
    int nonEmptyRoom = 0;

	for(int r = 0; r < names[f].size(); r++) {
      if (!IsEmpty(f,r))
      {
        nonEmptyRoom++;
        cout << "Occupant of Room " << r << " on floor " << f;
        cout << " is " << names[f][r];
        cout << ", Identity number "  << ids[f][r] << endl;
      }
    }

    if (nonEmptyRoom == 0)
      cout << "Floor " << f << " is empty" << endl;
  }
}

void building::Display()
{
  int nonEmptyRoom = 0;
  for (int f = 0; f < names.size(); f++) {
    for(int r = 0; r < names[f].size(); r++) {
      if (!IsEmpty(f,r))
      {
        nonEmptyRoom++;
        cout << "Occupant of Room " << r << " on floor " << f;
        cout << " is " << names[f][r];
        cout << ", Identity number "  << ids[f][r] << endl;
      }
    }
  }
  if (nonEmptyRoom == 0)
    cout << "The building is empty" << endl;
}

int building::Vacancies(int f) const
{
  //... check f is valid
  //... count the number of empty rooms at floor f
  //... if f is invalid output error message and return -1

	cout << "Floor " << f << " is invalid, cannot cound vacancies" << endl;
	return -1;
}

int building::Vacancies() const
{
  //... count the number of empty rooms in the whole building

	return -1;
}

bool building::IsEmpty(int f, int r) const
{
	return (names[f][r] == "");
}

void building::AddFloor(int r)
{
  //... add a floor with r number of rooms to the building
  //... all newly added rooms should be empty
}

void building::AddRoom(int f)
{
  //... check if f is valid
  //... add an empty room with on floor f to the building
}

void building::RemoveFloor()
{
  //... remove the last (highest level) floor
}

void building::RemoveRoom(int f)
{
  //... check if f is valid
  //... remove the last room (biggest room number) on floor f
}

ostream& operator<<(ostream& os, const building& b)
{
  //... print out the names separated with a space (i.e. ' ')
  //... in alphabetical order
  //... hints:
  //... store all names in a string vector and apply STL algorithm sort()

	return os;
}

bool operator==(const building& b1, const building& b2)
{
  return b1.Vacancies() == b2.Vacancies();
}

void building::Identify_Writer()
{
  cout << MY_NAME << " " << MY_STU_ID << endl;
}

bool building::IsValidFloor(int f) const {
  bool valid = ((0 <= f) && (f < names.size()));
  if (! valid) {
    cerr << "Floor " << f << " is out of range!\n";
  }
  return valid;
};

bool building::IsValidRoom(int f, int r) const {
  bool valid = (IsValidFloor(f) && (0 <= r) && (r < names[f].size()));
  if (! valid) {
    cerr << "Room " << r << " on floor " << f << " is out of range!\n";
  }
  return valid;
};
