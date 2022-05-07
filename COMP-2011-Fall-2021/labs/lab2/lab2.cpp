// https://magisterrex.files.wordpress.com/2014/07/mastermindrules.pdf
// Cindy https://www.youtube.com/watch?v=dMHxyulGrEk

#include <iostream> 
#include <cstdlib>
#include <time.h>  
using namespace std;

int main() 
{
    srand( time(NULL) );
    //Codemaker's choice of a random 4-color combination among six colors 
    // 1 Yellow, 2 Orange, 3 black, 4 Green, 5 Blue, 6 Purple
    int p0 = rand() % 6 + 1; // 1 to 6
    int p1 = rand() % 6 + 1; // 1 to 6
    int p2 = rand() % 6 + 1; // 1 to 6
    int p3 = rand() % 6 + 1; // 1 to 6

    // variable for code breaker's guess
    int g0;
    int g1;
    int g2;
    int g3;

    // variable for codemaker's response
    // red: correct color and correct position
    // white: correct color but wrong position
    // red overrides white
    int redpin;
    int whitepin;

    //you may declare additional variables here  to help you solve the problem:
    







    
    bool debug = true;

    cout << "==============================" << endl;
    cout << "Welcome to the Mastermind Game" << endl;
    cout << "==============================" << endl;

    if (debug){
        cout << "Coder maker's colors:" << endl;
        cout << "p0=" << p0 << "\tp1=" << p1 << "\tp2=" << p2 << "\tp3=" << p3 << endl << endl;
    }

    cout << "Code maker has made his choice." << endl;
    cout << "Code breaker, you have 12 attempts to crack his code." << endl;
    cout << "Game starts!" << endl << endl;

    
    // Write your code below this section:









    // Player runs out of attempts and loses 
    cout << "Sorry, you ran out of turns :( "<< endl; 

    return 0;
}