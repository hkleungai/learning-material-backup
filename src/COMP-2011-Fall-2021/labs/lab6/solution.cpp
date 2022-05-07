#include<iostream>
using namespace std;

// pretty print for the farm state
void print_farm(char farm[][10], int M, int N) {
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cout << farm[i][j] << "  ";
        }
        cout << endl;
    }
}

// helper function: copy an array (assign a testcase array to the farm array)
void copy_array(char farm[][10], char testcase[][10], int M) {
    for (int i=0; i<M; i++) {
        for (int j=0; j<10; j++) {
            farm[i][j] = testcase[i][j];
        }
    }
}


// This function identify whether the cell (x,y) of the farm is a zombie
bool is_zombie(char farm[][10], int x, int y, int M, int N) {
    return farm[y][x] == 'x';
}

// This function identify whether the cell (x,y) of the farm is a sunflower
bool is_sunflower(char farm[][10], int x, int y, int M, int N) {
    return farm[y][x] == '.';
}

// This function identify whether the cell (x,y) of the farm is a nut
bool is_nut(char farm[][10], int x, int y, int M, int N) {
    return farm[y][x] == '#';
}
// This function identify whether the cell (x,y) of the farm is a damaged_nut
bool is_damaged_nut(char farm[][10], int x, int y, int M, int N) {
    return farm[y][x] == '+';
}



// This function is to infect the cell (x,y) of the farm, changing the cell state accrodingly
void infect_cell(char farm[][10], int x, int y, int M, int N){
    if (is_nut(farm,x,y,M,N))
        farm[y][x] = '+';
    else if (is_damaged_nut(farm,x,y,M,N))
        farm[y][x] = '+';
    else
        farm[y][x] = 'x';
    return;
}


// The core function you need to implement
void infect_farm(char farm[][10], int x, int y, int t, int M, int N, int T){
    // Base case
    // 1. You may firstly identify the condition (boundry case) for stopping this funcition.
    // 2. You may define some basic function here or outside to produce the infrction. For example infect cell to

    if ( y<0 || y >= M || x<0 || x >= N || t > T)
        return;
    if (t == 0){
        farm[y][x] = 'x';
    }

    infect_cell(farm, x, y, M, N);
    if (is_damaged_nut(farm, x, y, M, N))
        return;

    // Recursive Case
    // You may define how to use recursion to iteratively infect the cells nearby 
    infect_farm(farm, x+1, y,   t+1, M, N, T);
    infect_farm(farm, x-1, y,   t+1, M, N, T);
    infect_farm(farm, x,   y+1, t+1, M, N, T);
    infect_farm(farm, x,   y-1, t+1, M, N, T);
    
}

 
// Driver code
int main()
{
    unsigned int M;  // Maximum row number of the farm
    unsigned int N;  // Maximum column number of the farm
    unsigned int T;  // Timestamp (we need to output all the farm states before T)
    unsigned int zombie_x; // x-axis to initialize zombie
    unsigned int zombie_y; // y-axis to initialize zombie
    char farm[10][10]; // farm state 

    // Change this paramenter from 1 to 5 to test different cases.  //
    unsigned int test_case = 5;

    // set M, N and for each test_case
    switch(test_case) {
        case 1:
            M = 5; N = 5; 
            break;
        case 2:
            M = 7; N = 7; 
            break;
        case 3:
            M = 9; N = 9; 
            break;
        case 4:
            M = 3; N = 7; 
            break;
        case 5:
            M = 4; N = 6; 
            break;
        default:
            M = 5; N = 5; 
            break;
    };

    if (test_case == 1) {
        char farm1[10][10] = {{'.', '.', '.', '.', '.', '/', '/', '/', '/', '/'},
                            {'.', '.', '.', '.', '.', '/', '/', '/', '/', '/'},
                            {'.', '#', '.', '.', '.', '/', '/', '/', '/', '/'},
                            {'.', '.', '.', '.', '.', '/', '/', '/', '/', '/'},
                            {'.', '.', '.', '.', '.', '/', '/', '/', '/', '/'},
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'},
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'},
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'},
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'},
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}};
        copy_array(farm, farm1, 10);
    }
    else if (test_case == 2) {
        char farm2[10][10] = {{'.', '.', '.', '.', '.', '.', '#', '/', '/', '/'},
                            {'.', '.', '.', '#', '.', '.', '.', '/', '/', '/'},
                            {'.', '#', '.', '.', '.', '#', '.', '/', '/', '/'},
                            {'.', '.', '#', '#', '.', '.', '.', '/', '/', '/'}, 
                            {'#', '.', '.', '.', '#', '.', '.', '/', '/', '/'},
                            {'.', '#', '#', '.', '.', '#', '.', '/', '/', '/'},
                            {'.', '.', '.', '.', '.', '.', '.', '/', '/', '/'},
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'},
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'},
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}}; 
        copy_array(farm, farm2, 10);
    }
    else if (test_case == 3) {
        char farm3[10][10] = {{'.', '.', '.', '.', '.', '.', '#', '.', '.', '/'},
                            {'.', '.', '.', '#', '.', '.', '.', '.', '.', '/'},
                            {'.', '#', '.', '.', '#', '#', '.', '.', '.', '/'},
                            {'.', '.', '#', '#', '.', '.', '.', '.', '.', '/'},
                            {'#', '.', '.', '.', '#', '.', '.', '#', '.', '/'},
                            {'.', '#', '#', '.', '.', '#', '.', '.', '.', '/'},
                            {'.', '.', '.', '.', '.', '.', '.', '#', '.', '/'},
                            {'.', '#', '.', '#', '.', '.', '#', '.', '.', '/'},
                            {'.', '.', '.', '.', '#', '.', '.', '.', '.', '/'},
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}}; 
        copy_array(farm, farm3, 10);
    }
    else if (test_case == 4) {
        char farm4[10][10] = {{'.', '.', '#', '.', '.', '.', '#', '/', '/', '/'},
                            {'.', '.', '#', '.', '#', '.', '.', '/', '/', '/'},
                            {'.', '#', '#', '.', '.', '#', '.', '/', '/', '/'},
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}, 
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}, 
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}, 
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}, 
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}, 
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}, 
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}}; 
        copy_array(farm, farm4, 10);
    }
    else if (test_case == 5) {
        char farm5[10][10] = {{'.', '.', '#', '.', '.', '.', '/', '/', '/', '/'},
                            {'.', '#', '.', '.', '#', '.', '/', '/', '/', '/'},
                            {'.', '.', '#', '.', '.', '#', '/', '/', '/', '/'},
                            {'.', '.', '.', '#', '.', '#', '/', '/', '/', '/'},
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}, 
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}, 
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}, 
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}, 
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}, 
                            {'/', '/', '/', '/', '/', '/', '/', '/', '/', '/'}}; 
        copy_array(farm, farm5, 10);
    }
    else {
        cout << "No more test cases!" << endl;
        return 0;
    }


    cout << "**************************************************" << endl;
    cout << "Zombie Game Start" << endl;
    cout << "Test Case: " << test_case << endl;
    cout << "Farm Size (M x N): " << M << "x" << N << endl;
    cout << "**************************************************" << endl;
    cout << "Please the Location of Zombie" << endl;
    cin  >> zombie_x >> zombie_y;
    cout << "Please input the timestamp T" << endl;
    cin  >> T;
    cout << "Zombie Location: (" << zombie_x << "," << zombie_y << ")" << endl;
    cout << "Initial Farm: \n";
    print_farm(farm, M, N);
    cout << "**************************************************" << endl;

    // compute and display for each timestamp (recursive depth)
    for (int t=0; t<=T; t++){
        char farm_copy[10][10];
        copy_array(farm_copy, farm, 10);
        infect_farm(farm_copy, zombie_x, zombie_y, 0, M, N, t);
        // output farm state at timestamp t
        cout << "Farm state at step " << t << ":" << endl;
        print_farm(farm_copy, M, N);
    }
}
