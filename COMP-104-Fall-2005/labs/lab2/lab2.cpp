
// yourName yourLabSection
// lab2a.cpp (model answer)
// Weight program
#include <iostream>			
using namespace std;

void main()
{
	int apple;						//number of apples
	int orange;						//number of oranges
	int weight;						//total weight
	int hundred;					//number of 100g-weights to use
	int fifty;						//number of 50g-weights to use
	int twenty;						//number of 20g-weights to use
	int	ten;						//number of 10g-weights to use
	int five;						//number of 5g-weights to use

	// fruit input
	cout << "Weight Program" << endl;	
	cout << "Enter the number of apples to buy: ";	
	cin >> apple;				
	cout << "Enter the number of oranges to buy: ";		
	cin >> orange;

	//calculate the total weight of the fruits
	weight = 0;						
	weight = weight + apple * 105;	
	weight = weight + orange * 120;


	//calculate the number of 100g, 50g, 20g, 10g and 5g weights needed
	hundred = weight / 100;
	weight = weight % 100;
	fifty =  weight / 50;
	weight = weight % 50;
	twenty = weight / 20;
	weight = weight % 20;
	ten = weight / 10;
	weight = weight % 10;
	five = weight / 5;


	//print out the number of weights needed
	cout << "100g-weight : " << hundred << endl;
	cout << "50g-weight  : " << fifty << endl;
	cout << "20g-weight  : " << twenty << endl;
	cout << "10g-weight  : " << ten <<endl;
	cout << "5g-weight   : " << five <<endl;

}

/*
// yourName yourLabSection
// lab2b.cpp (model answer)
// Leap year calculation program
#include <iostream>			
using namespace std;

void main()
{
	int year;					//year for leap year checking
	int day;					//days in a year.

	// leap year input
	cout << "Leap Year Calculation"<<endl;	
	cout << "Enter the year: ";
	cin >> year;

	// calculate number of days in year
	if(year % 4 != 0)			//NOT Leap year if not divisible by 4
		day = 365;
	else if(year % 400 == 0)	//Leap year if divisible by 400
		day = 366;
	else if(year % 100 == 0)	//NOT leap year if divisible by both 100 & 4, but not 400  
		day = 365;
	else						//Leap year if all previous condition not satisfied
		day = 366;
	
	//print out if the year is a leap year or not
	if (day ==366)
		cout << year << " is a Leap year." << endl;
	else 	
		cout << year << " is NOT a Leap year." << endl;
	
	//print out the number of days in the year.
	cout << "The number of days in year " << year << " is " << day << "." << endl; 
}
*/