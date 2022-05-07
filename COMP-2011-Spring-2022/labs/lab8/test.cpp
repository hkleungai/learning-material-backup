#include <iostream>
#include <algorithm>
#include <iterator>
#include "consts.h"
#include "lab8.h"

using namespace std;

const int LINKED_IDS[1+MAP_SIDE_LEN*MAP_SIDE_LEN] = {-1, 22, -1, -1, 13, -1, -1, -1, 10, -1, -1, -1, -1, -1, 20, -1, -1, 15, -1, 11, -1, 7, -1, -1, 3, -1};
const int LINKED_IDS1[1+MAP_SIDE_LEN*MAP_SIDE_LEN] = {-1, 22, -1, -1, 12, -1, -1, -1, 10, -1, -1, -1, -1, 20, -1, -1, -1, 14, -1, 15, -1, 7, -1, -1, 3, -1};
const int LINKED_IDS2[1+MAP_SIDE_LEN*MAP_SIDE_LEN] = {-1, 22, -1, -1, 11, -1, -1, -1, 10, -1, -1, -1, 20, -1, -1, -1, -1, 13, -1, 14, -1, 7, -1, -1, 3, -1};
const int LINKED_IDS3[1+MAP_SIDE_LEN*MAP_SIDE_LEN] = {-1, 21, -1, -1, 11, -1, -1, -1, 10, -1, -1, -1, 20, -1, -1, -1, -1, 13, -1, 14, -1, -1, -1, 3, -1, 7};
const bool LANDSLIDES[1+MAP_SIDE_LEN*MAP_SIDE_LEN] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
const bool LANDSLIDES1[1+MAP_SIDE_LEN*MAP_SIDE_LEN] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
const bool LANDSLIDES2[1+MAP_SIDE_LEN*MAP_SIDE_LEN] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
const bool LANDSLIDES3[1+MAP_SIDE_LEN*MAP_SIDE_LEN] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
const int CUR_IDS[2*MAP_SIDE_LEN*MAP_SIDE_LEN-1] = {22, 2, 3, 13, 5, 6, 7, 10, 9, 10, 11, 12, 13, 20, 15, 16, 15, 18, 11, 20, 7, 22, 23, 3, 25, 3, 23, 22, 7, 20, 11, 18, 15, 16, 15, 20, 13, 12, 11, 10, 9, 10, 7, 6, 5, 13, 3, 2, 22};

int main() {
    Cell game_cells[1+MAP_SIDE_LEN*MAP_SIDE_LEN];
    Cell* game_cell_ptrs[1+MAP_SIDE_LEN*MAP_SIDE_LEN];
    int cur_cell_id = 0;
    for (int i=0; i<=MAP_SIDE_LEN*MAP_SIDE_LEN; ++i) {
        game_cell_ptrs[i] = &game_cells[i];
    }

    // test for init_game()
    init_game(game_cell_ptrs);
    
    int linked_ids[1+MAP_SIDE_LEN*MAP_SIDE_LEN];
    bool landslides[1+MAP_SIDE_LEN*MAP_SIDE_LEN];
    bool temp_landslides[1+MAP_SIDE_LEN*MAP_SIDE_LEN];

    for (int i=0; i<1+MAP_SIDE_LEN*MAP_SIDE_LEN; ++i) {
        linked_ids[i] = game_cell_ptrs[i]->to_cell_id;
        landslides[i] = game_cell_ptrs[i]->landslide;
    }

    if ((equal(begin(LINKED_IDS), end(LINKED_IDS), begin(linked_ids))) && (equal(begin(LANDSLIDES), end(LANDSLIDES), begin(landslides)))) {
        cout << "Task 1 finished!" << endl;
    } else {
        cout << "Some mistakes with your Task 1..." << endl;
    }

    // test for move()
    cur_cell_id = 0;
    int cur_ids[2*MAP_SIDE_LEN*MAP_SIDE_LEN-1];

    for (int i=0; i<2*MAP_SIDE_LEN*MAP_SIDE_LEN-1; ++i) {
        init_game(game_cell_ptrs);
        cur_cell_id = 0;
        move(game_cell_ptrs, cur_cell_id, i+1);
        cur_ids[i] = cur_cell_id;
    }

    if (equal(begin(CUR_IDS), end(CUR_IDS), begin(cur_ids))) {
        cout << "Task 2 finished!" << endl;
    } else {
        cout << "Some mistakes with your Task 2..." << endl;
    }

    // test for landslide()
    cur_cell_id = 0;
    for (int i=0; i<=MAP_SIDE_LEN*MAP_SIDE_LEN; ++i) {
        game_cell_ptrs[i] = &game_cells[i];
    }
    init_game(game_cell_ptrs);
    move(game_cell_ptrs, cur_cell_id, 11);
    for (int i=0; i<1+MAP_SIDE_LEN*MAP_SIDE_LEN; ++i) {
        linked_ids[i] = game_cell_ptrs[i]->to_cell_id;
        landslides[i] = game_cell_ptrs[i]->landslide;
        temp_landslides[i] = game_cells[i].landslide;
    }
    if ((equal(begin(LINKED_IDS1), end(LINKED_IDS1), begin(linked_ids))) && (equal(begin(LANDSLIDES1), end(LANDSLIDES1), begin(landslides))) && (equal(begin(LANDSLIDES), end(LANDSLIDES), begin(temp_landslides)))) {
        cout << "Task 3 Test 1 finished!" << endl;
    } else {
        cout << "Some mistakes with your Task 3 after one rotation..." << endl;
    }
    move(game_cell_ptrs, cur_cell_id, 1);
    for (int i=0; i<1+MAP_SIDE_LEN*MAP_SIDE_LEN; ++i) {
        linked_ids[i] = game_cell_ptrs[i]->to_cell_id;
        landslides[i] = game_cell_ptrs[i]->landslide;
        temp_landslides[i] = game_cells[i].landslide;
    }
    if ((equal(begin(LINKED_IDS2), end(LINKED_IDS2), begin(linked_ids))) && (equal(begin(LANDSLIDES2), end(LANDSLIDES2), begin(landslides))) && (equal(begin(LANDSLIDES), end(LANDSLIDES), begin(temp_landslides)))) {
        cout << "Task 3 Test 2 finished!" << endl;
    } else {
        cout << "Some mistakes with your Task 3 after two rotations..." << endl;
    }
    move(game_cell_ptrs, cur_cell_id, 11);
    for (int i=0; i<1+MAP_SIDE_LEN*MAP_SIDE_LEN; ++i) {
        linked_ids[i] = game_cell_ptrs[i]->to_cell_id;
        landslides[i] = game_cell_ptrs[i]->landslide;
        temp_landslides[i] = game_cells[i].landslide;
    }
    if ((equal(begin(LINKED_IDS3), end(LINKED_IDS3), begin(linked_ids))) && (equal(begin(LANDSLIDES3), end(LANDSLIDES3), begin(landslides))) && (equal(begin(LANDSLIDES), end(LANDSLIDES), begin(temp_landslides)))) {
        cout << "Task 3 Test 3 finished!" << endl;
    } else {
        cout << "Some mistakes with your Task 3 after three rotations..." << endl;
    }
}