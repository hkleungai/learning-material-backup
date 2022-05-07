#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
const int MAX_HEIGHT=6;
const int MAX_WIDTH=6;


bool findUncoveredGrid(int board[][MAX_WIDTH], int height, int width, int& r_id, int& c_id){
    for (r_id = 0; r_id < height; r_id++)
        for (c_id = 0; c_id < width; c_id++)
            if (board[r_id][c_id] == 0)
                return true;
    
    return false;
}


int numberLayout(int board[][MAX_WIDTH], int height, int width){
    int result = 0;
    int r_id, c_id;
    bool findGrid;

    // find the upper leftmost grid
    findGrid = findUncoveredGrid(board, height, width, r_id, c_id);

    if (!findGrid)
        // means there's no uncovered grid
        return 1;

    // tile 1x2 horizontally
    if ((c_id + 1 < width)&&(board[r_id][c_id+1]==0)){
        board[r_id][c_id] = 1;
        board[r_id][c_id+1] = 1;
        result += numberLayout(board, height, width);
        board[r_id][c_id] = 0;
        board[r_id][c_id+1] = 0;
    }
 
    // tile 2x1 vertically
    if ((r_id + 1 < height)&&(board[r_id+1][c_id]==0)){
        board[r_id][c_id] = 1;
        board[r_id+1][c_id] = 1;
        result += numberLayout(board, height, width);
        board[r_id][c_id] = 0;
        board[r_id+1][c_id] = 0;
    }

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