#include <iostream>
#include "consts.h"
#include "lab8.h"

using namespace std;

int main() {
    srand(time(NULL));

    Cell game_cells[1+MAP_SIDE_LEN*MAP_SIDE_LEN]; // game cells
    Cell* game_cell_ptrs[1+MAP_SIDE_LEN*MAP_SIDE_LEN]; // pointer to the cells
    int cur_cell_id = 0;
    for (int i=0; i<=MAP_SIDE_LEN*MAP_SIDE_LEN; ++i) {
        game_cell_ptrs[i] = &game_cells[i];
    }

    int step = 0, moves = 0, print_mode = 0;
    bool random = false, stop = false;
    char choice;

    init_game(game_cell_ptrs);

    cout << "Want random game (Y/y for yes, N/n for no)? ";
    cin >> choice;
    if ((choice=='Y')||(choice=='y'))
    {
        cout << "Now you got a dice!" << endl;
        random = true;
    }

    while (!stop) {
        cout << "Step: " << step;
        cout << ". You are at cell " << cur_cell_id << "." << endl;
        if (random)
        {
            moves = rand()%6+1;
            cout << "Move by " << moves << " cells." << endl;
            move(game_cell_ptrs, cur_cell_id, moves);
            cout << "You are at cell " << cur_cell_id << " after movement." << endl;
            ++step;
            stop = reach_dest(cur_cell_id);
            if (stop) {
                cout << "Congrats! You reach the end!" << endl;
                continue;
            }
        } else
        {
            cout << "How many steps to move?" << endl;
            cin >> moves;
            cout << "Move by " << moves << "cells." << endl;
            move(game_cell_ptrs, cur_cell_id, moves);
            cout << "You are at cell " << cur_cell_id << " after movement." << endl;
            ++step;
            stop = reach_dest(cur_cell_id);
            if (stop) {
                cout << "Congrats! You reach the end!" << endl;
                continue;
            }
            cout << "Choose your action after the movement (0-2)\n0 - Does nothing\n1 - Print the map\n2 - Quit the game" << endl;
            cin >> choice;
            if (choice=='1') {
                cout << "Now select in which way you want to check the map (0-4): " << endl;
                cin >> print_mode;
                print(game_cell_ptrs, cur_cell_id, static_cast<printing_mode>(print_mode));
            } else if (choice=='2') {
                cout << "Game abandoned after " << step << " step(s). You reach cell " << cur_cell_id << "." << endl;
                stop = true;
            }
        }
    }
}