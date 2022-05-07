#include <iostream>
#include "consts.h"
#include "lab8.h"

using namespace std;

// TODO 1: initialize the cells of the game
void init_game(Cell* cell_ptrs[]) {
    int id = 0;
    // initialize each cell with default values
    for (id=0; id<=MAP_SIDE_LEN*MAP_SIDE_LEN; ++id) {
        cell_ptrs[id]->to_cell_id = -1;
        cell_ptrs[id]->landslide = false;
    }
    // add the links
    for (int i=0; i<sizeof(LINK_ENDS)/sizeof(LINK_ENDS[0]); ++i) {
        cell_ptrs[LINK_ENDS[i][0]]->to_cell_id = LINK_ENDS[i][1];
    }
    // add landslide events
    for (int i=0; i<sizeof(LANDSLIDE_LOCS)/sizeof(int); ++i) {
        cell_ptrs[LANDSLIDE_LOCS[i]]->landslide = true;
    }
}

// TODO 2: move the player using the given number of moves
void move(Cell* cell_ptrs[], int& cur_cell_id, int num_moves) {
    int map_size = MAP_SIDE_LEN*MAP_SIDE_LEN;
    cur_cell_id += num_moves;
    // if dest_cell is outside of the board, bounce back
    // here I consider the case where after the bounce back the dest_cell is still outside of the board
    while (!((cur_cell_id>=0)&&(cur_cell_id<=map_size))) {
        cur_cell_id -= ((cur_cell_id>map_size)?(2*(cur_cell_id-map_size)):(2*cur_cell_id));
    }
    Cell* dest_cell = cell_ptrs[cur_cell_id];
    // if there is a link at dest_cell, immediately move through it
    if (dest_cell->to_cell_id>=0) {
        cur_cell_id = dest_cell->to_cell_id;
        dest_cell = cell_ptrs[cur_cell_id];
    }
    // trigger landslide if there is such event
    if (dest_cell->landslide) {
        landslide(cell_ptrs, cur_cell_id);
    }
}

// TODO 3: trigger landslide for the current cell location
void landslide(Cell* cell_ptrs[], int cur_cell_id) {
    int start_id = (cur_cell_id-1)/MAP_SIDE_LEN*MAP_SIDE_LEN+1;
    int end_id = start_id+MAP_SIDE_LEN-1;
    Cell* first = cell_ptrs[start_id];
    for (int i = start_id+1; i<=end_id; ++i) {
        cell_ptrs[i-1] = cell_ptrs[i];
    }
    cell_ptrs[end_id] = first;
    // change the links associated with the current row
    for (Cell* check_cell=cell_ptrs[1]; check_cell<=cell_ptrs[MAP_SIDE_LEN*MAP_SIDE_LEN]; ++check_cell) {
        int cur_id = check_cell->to_cell_id;
        if ((cur_id>=start_id) && (cur_id<=end_id)) {
            check_cell->to_cell_id = (cur_id-1<start_id)?end_id:cur_id-1;
        }
    }
}