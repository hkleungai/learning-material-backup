#include <stdlib.h>
#include <iostream>
using namespace std;
const int MAX_HEIGHT=6;
const int MAX_WIDTH=6;


bool findUncoveredGrid(int board[][MAX_WIDTH], int height, int width, int& r_id, int& c_id){
    // to be completed
    //
    return true;
}


int numberLayout(int board[][MAX_WIDTH], int height, int width){
    int result = 0;
    // to be completed
    //
    return result;
}


int main(){
    int width, height;
    int board[MAX_HEIGHT][MAX_WIDTH] = {};

    // enter the height (number of rows)
    do{
    cout << "Please enter the height [1, " << MAX_HEIGHT << "]:" << endl;
    cin >> height;
    }
    while((height < 1)||(height > MAX_HEIGHT));

    // enter the width (number of columns)
    do{
    cout << "Please enter the width [1, " << MAX_WIDTH << "]:" << endl;
    cin >> width;
    }while((width < 1)||(width > MAX_WIDTH));

    cout << "The number of layouts is " << numberLayout(board, height, width) << "." << endl;

    return 0;
}