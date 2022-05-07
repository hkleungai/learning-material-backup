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

    //temporary variables to store code for comparing 
    int temp_p0;
    int temp_p1;
    int temp_p2;
    int temp_p3;

    //temporary variables to store user guesses for comparing 
    int temp_g0;
    int temp_g1;
    int temp_g2;
    int temp_g3;

    // debug
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

    for(int attempt = 1; attempt <= 12; attempt++) {

        cout << "Attempt " << attempt << endl;
        if (attempt == 12)
            cout << "Caution: this is your last chance" << endl;
        
        cout << "Please input your guess: " << endl;
        cin >> g0 >> g1 >> g2 >> g3;

        // reset hints
        redpin = 0;
        whitepin = 0;

        // copy answer pins and user guess pins to temporary variables since we may need to change the values for logic checking
        temp_p0 = p0;
        temp_p1 = p1;
        temp_p2 = p2;
        temp_p3 = p3;

        temp_g0 = g0;
        temp_g1 = g1;
        temp_g2 = g2;
        temp_g3 = g3;

        
        // We do not use arrays, so we compare each pin manually. total 4x4 = 16 logic comparisons. 

        // Check for number of red pins first
        if (temp_g0 == temp_p0){
            // if matched, we do not use the pins for matching again. 
            // We can do this by changing their values to something that will never be matched with each other, e.g. -1 and -2.             
            temp_p0 = -1;  
            temp_g0 = -2;
            redpin++;
        }

        if (temp_g1 == temp_p1){
            temp_p1 = -1;
            temp_g1 = -2;
            redpin++;
        }

        if (temp_g2 == temp_p2){
            temp_p2 = -1;
            temp_g2 = -2;
            redpin++;
        }

        if (temp_g3 == temp_p3){
            temp_p3 = -1;
            temp_g3 = -2;
            redpin++;
        }

        // Check for number of white pins
        if (temp_g0 == temp_p1){
            temp_p1 = -1;
            temp_g0 = -2;
            whitepin++;
        }

        if (temp_g0 == temp_p2){
            temp_p2 = -1;
            temp_g0 = -2;
            whitepin++;
        }

        if (temp_g0 == temp_p3){
            temp_p3 = -1;
            temp_g0 = -2;
            whitepin++;
        }

        if (temp_g1 == temp_p0){
            temp_p0 = -1;
            temp_g1 = -2;
            whitepin++;
        }

        if (temp_g1 == temp_p2){
            temp_p2 = -1;
            temp_g1 = -2;
            whitepin++;
        }

        if (temp_g1 == temp_p3){
            temp_p3 = -1;
            temp_g1 = -2;
            whitepin++;
        }

        if (temp_g2 == temp_p0){
            temp_p0 = -1;
            temp_g2 = -2;
            whitepin++;
        }

        if (temp_g2 == temp_p1){
            temp_p1 = -1;
            temp_g2 = -2;
            whitepin++;
        }

        if (temp_g2 == temp_p3){
            temp_p3 = -1;
            temp_g2 = -2;
            whitepin++;
        }

        if (temp_g3 == temp_p0){
            temp_p0 = -1;
            temp_g3 = -2;
            whitepin++;
        }

        if (temp_g3 == temp_p1){
            temp_p1 = -1;
            temp_g3 = -2;
            whitepin++;
        }

        if (temp_g3 == temp_p2){
            temp_p2 = -1;
            temp_g3 = -2;
            whitepin++;
        }

        cout << "Red pins: " << redpin << ", White pins: " << whitepin << endl << endl;

        // Player gets 4 redpins, wins the game and program returns
        if (redpin == 4){
            cout << "Congratulations!" << endl;
            cout << "Coder maker's colors:" << endl;
            cout << "p0=" << p0 << "\tp1=" << p1 << "\tp2=" << p2 << "\tp3=" << p3 << endl;
            if (attempt == 1)
                cout << "You cracked it with a SINGLE attempt. Today must be your LUCKY day!" << endl;
            else
                cout << "You cracked the code with " << attempt << " attempts" << endl;
            return 0;
        }

    }

    // Player runs out of attempts and loses 
    cout << "Sorry, you ran out of turns :( "<< endl; 

    return 0;
}