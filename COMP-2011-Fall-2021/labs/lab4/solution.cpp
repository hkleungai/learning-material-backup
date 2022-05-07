#include <iostream>
#include <cstring>
using namespace std;	

const int NUM_ROW_MAX = 100;
const int NUM_COL_MAX = 100;

void print_2D_array(const char s[][NUM_COL_MAX+1], int size[2]){
    for (int i = 0; i < size[0]; i++ ){
        for (int j = 0; j < size[1]; j++ )
            cout << s[i][j];
        cout << endl;    
    }        
}

void initialize_2D_array(char s[][NUM_COL_MAX+1]){
    for (int i = 0; i < NUM_ROW_MAX; i++)
        for (int j = 0; j < NUM_COL_MAX; j++)
            s[i][j] = ' ';
}

void h_flip(const char s[][NUM_COL_MAX+1], int num_row, int num_col, char h_flipped[][NUM_COL_MAX+1], int size[2]){ /* horizontal flip */
    // Task 1: horizontal flip of the 2D array, concatenate with the original 2D array
    // Please fill in your code here
    initialize_2D_array(h_flipped);
    size[0] = num_row;
    size[1] = 2*num_col;

    for (int i = 0; i < size[0]; i++){
        for (int j = 0; j < size[1]; j++)
            if (j < num_col)
                h_flipped[i][j] = s[i][j];
            else
                h_flipped[i][j] = s[i][size[1]-1-j];
    }
}

void v_flip(const char s[][NUM_COL_MAX+1], int num_row, int num_col, char v_flipped[][NUM_COL_MAX+1], int size[2]){ /* vertical flip */
    // Task 2: vertial flip of the 2D array, concatenate with the original 2D array
    // Please fill in your code here
    initialize_2D_array(v_flipped);
    size[0] = 2*num_row;
    size[1] = num_col;

    for (int j = 0; j < size[1]; j++)
        for (int i = 0; i < size[0]; i++)
            if (i < num_row)
                v_flipped[i][j] = s[i][j];
            else
                v_flipped[i][j] = s[size[0]-1-i][j];
}

void hv_flip(const char s[][NUM_COL_MAX+1], int num_row, int num_col, char hv_flipped[][NUM_COL_MAX+1], int size[2]){ /* horizontal and vertical flip */
    // Task 3: horizontal and vertical flips of the 2D array, concatenate with the original 2D array
    // Please fill in your code here
    char h_flipped[NUM_ROW_MAX][NUM_COL_MAX+1];
    h_flip(s, num_row, num_col, h_flipped, size);
    v_flip(h_flipped, num_row, 2*num_col, hv_flipped, size);
}

int initialize_self_defined_2D_array(char s[][NUM_COL_MAX+1], int num_row){/* initialize the self-defined 2D array */
    // Task 4: initialize any self-defined 2D array by typing to terminal
    // The user should type line-by-line
    // Please fill in your code here
    int num_col = 0;

    cin.get();
    for (int i = 0; i < num_row; i++){
        cin.getline(s[i], NUM_COL_MAX+1, '\n');       
        if (cin.gcount()-1 > num_col)
            num_col = cin.gcount()-1;
    }                    
    
    for (int i = 0; i < NUM_ROW_MAX; i++)
        for (int j = 0; j < NUM_COL_MAX+1; j++)
            if (s[i][j]=='\0')
                s[i][j]=' '; 
    
    return num_col;
}

int main(){  
    char s[NUM_ROW_MAX][NUM_COL_MAX+1];
    int num_row, num_col;
    int reply;
    do {
        initialize_2D_array(s);

        cout << "===========================================" << endl;
        cout << "choose which 2D array to operate on:" << endl;
        cout << "1: Sample Array 1" << endl;
        cout << "2: Sample Array 2" << endl;
        cout << "3: Sample Array 3" << endl;
        cout << "4: Any Self-defined Array" << endl;
        cout << "5: Quit" << endl;
        cin >> reply;
        if (cin.fail())
            return 0;

        switch(reply) {
        case 1:{
            num_row = 3;
            num_col = 3;
            s[0][2] = '*';
            s[1][1] = '*';
            s[2][0] = '*';            
            break;
        }     
        case 2:{
            num_row = 4;
            num_col = 4;
            for (int i = 0; i < num_row; i++)
                for (int j = 0; j < num_col-i; j++)
                    s[i][j]='0'+i+j;
            break;
        }       
        case 3:{
            num_row = 5;
            num_col = 9;
            char tmp[NUM_ROW_MAX][NUM_COL_MAX+1] = {"@#$%^    ",
                                                    " a   1   ", 
                                                    "   b  2  ",
                                                    "     c 3 ",
                                                    "        *"};
            for (int i = 0; i < num_row; i++)
                for (int j = 0; j < num_col; j++)
                    s[i][j]=tmp[i][j];
            break;
        }                     
        case 4:{
            cout << endl << "Task 4: Self-defined 2D Array Initialization:" << endl;
            cout << "Please input number of rows for your 2D array: " << endl;
            cin >> num_row;
            if (cin.fail()){
                cout << "The input is invalid. Please make sure you enter a number between 1 and "<< NUM_ROW_MAX << endl;
                return 0;
            }               
            while ( num_row < 1 || num_row > NUM_ROW_MAX){
                cout << "The input is invalid. Please make sure you enter a number between 1 and "<< NUM_ROW_MAX << endl;
                cin >> num_row;
            }
            
            cout << "Please enter your 2D array line by line: " << endl;
            
            //Task 4: initialize any self-defined 2D array by typing to terminal
            num_col = initialize_self_defined_2D_array(s, num_row);

            break;
        }            
        default:
            break;
        }
        
        if (reply >= 1 && reply <= 4){
            int size[2] = {num_row, num_col};//always record the size of the 2D array after the current operation

            cout << endl << "The initial 2D array is:" << endl;
            print_2D_array(s, size);

            //Task 1: horizontal flip of the 2D array, concatenate with the original 2D array
            cout << endl << "Task 1: Horizontal Flip & Concatenate:" << endl;
            char h_flipped[NUM_ROW_MAX][NUM_COL_MAX+1];
            h_flip(s, num_row, num_col, h_flipped, size);
            print_2D_array(h_flipped, size);


            //Task 2: vertial flip of the 2D array, concatenate with the original 2D array
            cout << endl << "Task 2: Vertical Flip & Concatenate:" << endl;
            char v_flipped[NUM_ROW_MAX][NUM_COL_MAX+1];
            v_flip(s, num_row, num_col, v_flipped, size);
            print_2D_array(v_flipped, size);


            //Task 3: horizontal and vertical flips of the 2D array, concatenate with the original 2D array
            cout << endl << "Task 3: Horizontal Flip & Vertical Flip & Concatenate:" << endl;
            char hv_flipped[NUM_ROW_MAX][NUM_COL_MAX+1];
            hv_flip(s, num_row, num_col, hv_flipped, size);
            print_2D_array(hv_flipped, size);
        }
    } 
    while (reply != 5);
   
    return 0;
}