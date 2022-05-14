//--------------------------------------------------------------------------
// yourName yourLabSection
// lab3.cpp (model answer)
// MasterMind 
#include <iostream>           // contains cout and cin 
#include <cstdlib>            // contains the random number generator rand() 
#include <ctime>              // contains time() to seed the random number 
// generator to give a different answer each time 
using namespace std; 

int main(){ 
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;    // computer's digits 
    int u1 = 0, u2 = 0, u3 = 0, u4 = 0;    // user's guess 
    int t1 = 0, t2 = 0, t3 = 0, t4 = 0;    // temp storage for computer's digits 
    int pcorrect;              // counter to count the number of correct positions 
    int ccorrect;              // counter to count the number of correct digits 
    int p, q; 
    int step = 1;			   // counter to count the number of steps 
  
    srand(time(0));            // initialize random number 
    c1 = rand()%6 + 1; 
    c2 = rand()%6 + 1; 
    c3 = rand()%6 + 1; 
    c4 = rand()%6 + 1; 
  
    t1 = c1; 
    t2 = c2; 
    t3 = c3; 
    t4 = c4; 
  
    cout << "MasterMind" << endl; 
    cout << "Enter four digits (1 - 6) separated by a space" << endl; 
    cout << "----------------------------------------------" << endl; 
  
    do{ 
        //cout << "Computer: " << c1 << c2 << c3 << c4 << endl;    // for cheating 
       cout << "Round " << step << endl; 
       cout << "Enter Guess: ";               // user input 
       cin >> u1 >> u2 >> u3 >> u4; 
  
       pcorrect = 0; 
       if(u1 == c1){        // count number of correct positions 
            c1 = 0; 
            u1 = -1; 
            pcorrect++; 
        } 
        if(u2 == c2){ 
            c2 = 0; 
            u2 = -1; 
            pcorrect++; 
        } 
        if(u3 == c3){ 
            c3 = 0; 
            u3 = -1; 
            pcorrect++; 
        } 
        if(u4 == c4){ 
            c4 = 0; 
            u4 = -1; 
            pcorrect++; 
        } 
  
       ccorrect = 0; 
        if(u1 == c2){        // count number of correct digits 
            c2 = 0; 
            u1 = -1; 
            ccorrect++; 
        } 
        else if(u1 == c3){ 
            c3 = 0; 
            u1 = -1; 
            ccorrect++; 
        } 
        else if(u1 == c4){ 
            c4 = 0; 
            u1 = -1; 
            ccorrect++; 
        } 
        if(u2 == c1){ 
            c1 = 0; 
            u2 = -1; 
            ccorrect++; 
        } 
        else if(u2 == c3){ 
            c3 = 0; 
            u2 = -1; 
            ccorrect++; 
        } 
        else if(u2 == c4) 
        { 
            c4 = 0; 
            u2 = -1; 
            ccorrect++; 
        } 
        if(u3 == c1){ 
            c1 = 0; 
            u3 = -1; 
            ccorrect++; 
        } 
        else if(u3 == c2){ 
            c2 = 0; 
            u3 = -1; 
            ccorrect++; 
        } 
        else if(u3 == c4){ 
            c4 = 0; 
            u3 = -1; 
            ccorrect++; 
        } 
        if(u4 == c1){ 
            c1 = 0; 
            u4 = -1; 
            ccorrect++; 
        } 
        else if(u4 == c2){ 
            c2 = 0; 
            u4 = -1; 
            ccorrect++; 
        } 
        else if(u4 == c3){ 
            c3 = 0; 
            u4 = -1; 
            ccorrect++; 
        } 
        // replace the original computer digits 
        c1 = t1; 
        c2 = t2; 
        c3 = t3; 
        c4 = t4; 
        cout << "             "; 
        for(p=0; p<pcorrect; p++) 
            cout << "O " ; 
        for(q=0; q<ccorrect; q++) 
            cout << "# " ; 
        cout << endl; 
        cout << "----------------------------------------------" << endl; 
  
        step++; 
    }while(pcorrect < 4); 
    cout << "Congratulations! You win in " << step - 1 << " steps!" << endl; 
    return 0; 
} 
