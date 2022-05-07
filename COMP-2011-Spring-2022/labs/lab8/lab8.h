enum printing_mode {PlayerMode, LandslideMode, LadderMode, SnakeMode};

struct Cell {
    int to_cell_id; // indicating the cell id this cell links to, please set to -1 if there is no such link
    bool landslide; // please set to false if will not cause landslide
};

// helper functions, provided in util.cpp
void print(const Cell* cell_ptr); // print the attributes of a cell
void print(Cell* cell_ptrs[], int cur_cell_id, printing_mode print_mode); // print the gameboard
bool reach_dest(int cur_cell_id); // check whether the player has won

// TODOs, please implement those functions in lab8.cpp
void init_game(Cell* cell_ptrs[]); // initialize the cells of the game
void move(Cell* cell_ptrs[], int& cur_cell_id, int num_moves); // move the player using the given number of moves
void landslide(Cell* cell_ptrs[], int cur_cell_id); // trigger landslide for the current cell location