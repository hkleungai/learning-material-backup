#include <iostream>
#include "consts.h"
#include "lab8.h"

using namespace std;

// print the attributes of a cell
void print(const Cell* cell_ptr) {
    cout << ((cell_ptr->to_cell_id<0)?"This cell is not linked to other cells":("This cell links to cell "+to_string(cell_ptr->to_cell_id)+".")) << endl;
    cout << "This cell will" << ((cell_ptr->landslide)?(" "):(" not ")) << "trigger landslide." << endl;
}

// print the gameboard
void print(Cell* cell_ptrs[], int cur_cell_id, printing_mode print_mode) {
    int board[1+MAP_SIDE_LEN*MAP_SIDE_LEN] = {0}; // storing the index of cells on the gameboard
    int map_size = MAP_SIDE_LEN*MAP_SIDE_LEN, cur_id = 0, counts = 1;
    switch(print_mode) {
        case PlayerMode:
            board[cur_cell_id] = 1;
            break;
        case LandslideMode:
            for (int i=0; i<=map_size; ++i) {
                board[i] = cell_ptrs[i]->landslide;
            }
            break;
        case LadderMode:
            for (int i=0; i<=map_size; ++i) {
                int start_id = i, end_id = cell_ptrs[i]->to_cell_id;
                if (start_id<end_id) {
                    board[i] = board[i+end_id-start_id] = counts;
                    ++counts;
                }
            }
            break;
        case SnakeMode:
            for (int i=0; i<=map_size; ++i) {
                int start_id = i, end_id = cell_ptrs[i]->to_cell_id;
                if ((start_id>end_id) && (end_id>0)) {
                    board[i] = board[i+end_id-start_id] = counts;
                    ++counts;
                }
            }
            break;
        default:
            break;
    }
    // print the array
    cout << "   1   2   3   4   5" << endl;
    for (int row=0; row<MAP_SIDE_LEN; ++row)
    {
        cout << "----------------------" << endl;
        cout << MAP_SIDE_LEN-row;
        for (int col=0; col<MAP_SIDE_LEN; ++col)
        {
            cout << "| " << board[(MAP_SIDE_LEN-row-1)*MAP_SIDE_LEN+col+1] << " ";
        }
        cout << endl;
    }
}

// check whether the player has won
bool reach_dest(int cur_cell_id) {
    return cur_cell_id==MAP_SIDE_LEN*MAP_SIDE_LEN;
}