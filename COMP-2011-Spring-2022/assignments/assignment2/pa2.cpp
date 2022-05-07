#include <iostream>
using namespace std;
//you are NOT allowed to include any additional library
const int ARRAY_MAX_SIZE = 12;

//given; do NOT modify; please refer to the webpage description
void printArray(int array[], int arraySize, int currentPosition)
{
    cout << array[currentPosition];
    if(currentPosition < arraySize-1)
    {
        if(array[currentPosition+1] > 0)
            cout << "+";
        printArray(array, arraySize, currentPosition+1);
    }
    else
        cout << endl;
}

//given; do NOT modify; please refer to the webpage description
void printArray(int array[], int arraySize)
{
     printArray(array, arraySize, 0);
}

//***** Only write your code below this line, remember that NO loop is allowed! ***** 
int arraySum(int array[], int arraySize)
{
    return 0;  //change this line if you want
}

bool solve(int input[], int size, int target, int result[], int& resultSize) 
{
    return false;  //change this line if you want
}

void printString(const char str[])
{
}

int getIntValue(const char str[], int start, int end)
{
    return 0;  //change this line if you want
}

int evaluate(const char str[])
{
    return 0;  //change this line if you want
}
//***** Only write your code above this line, remember that NO loop is allowed! *****


int main()
{
    int testCase;
    cout << "Hi, recursion master! Which test case do you want to run?" << endl;
    cin >> testCase;

    cout << endl << "Test case " << testCase << " output:" << endl;
    cout << "===================================" << endl;

    if(testCase == 0) //this test case is used to show you how printArray works; it is NOT used to grade your work and it is NOT on ZINC; no mark is allocated to this; try it on your own computer if you want
    {
        int array1[] = {1, 2, 3};
        printArray(array1, 3);
        int array2[] = {1, 2, 3, -4};
        printArray(array2, 4);
        int array3[] = {-8, 2, 1, -4};
        printArray(array3, 4);
        int array4[] = {99};
        printArray(array4, 1);
        int array5[] = {-1199};
        printArray(array5, 1);
    }
    
    else if(testCase == 1) //test arraySum
    {
        int array[] = {1, 2, 3};
        cout << arraySum(array, 3) << endl;
    }
    else if(testCase == 2) //test arraySum
    {
        int array[] = {-1, -234, 33, 5};
        cout << arraySum(array, 4) << endl;
    }

    else if(testCase == 3) //test solve
    {
        int input[] = {1, 2, 3, 4};
        int size = 4;
        int target = 2;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 4) //test solve
    {
        int input[] = {1, 2, 3, 4};
        int size = 4;
        int target = -2;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 5) //test solve
    {
        int input[] = {1, 2, 3, 4};
        int size = 4;
        int target = -9;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 6) //test solve
    {
        int input[] = {8, 13, 1, 3, 5, 9};
        int size = 6;
        int target = 9;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 7) //test solve
    {
        int input[] = {88, 13, 1, 3, 5, 9};
        int size = 6;
        int target = 9;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 8) //test solve
    {
        int input[] = {888, 13333, 20000, 1, 99, 3, 5, 9, 33, 44, 55, 100};
        int size = 12;
        int target = -165;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }

    else if(testCase == 9) //test printString
    {
        printString("1+1-2+1234");
    }
    else if(testCase == 10) //test printString
    {
        printString("Wow this assignment is so much fun!!!");
    }

    else if(testCase == 11) //test getIntValue
    {
        char str[] = "567";
        cout << getIntValue(str, 0, 2) << endl;
    }
    else if(testCase == 12) //test getIntValue
    {
        char str[] = "567";
        cout << getIntValue(str, 0, 1) << endl;
    }
    else if(testCase == 13) //test getIntValue
    {
        char str[] = "567";
        cout << getIntValue(str, 0, 0) << endl;
    }
    else if(testCase == 14) //test getIntValue
    {
        char str[] = "abc567abc";
        cout << getIntValue(str, 4, 5) << endl;
    }
    
    else if(testCase == 15) //test evaluate
    {
        cout << evaluate("172") << endl;
    }
    else if(testCase == 16) //test evaluate
    {
        cout << evaluate("3+2") << endl;
    }
    else if(testCase == 17) //test evaluate
    {
        cout << evaluate("1+2-4") << endl;
    }
    else if(testCase == 18) //test evaluate
    {
        cout << evaluate("11+21-43") << endl;
    }
    else if(testCase == 19) //test evaluate
    {
        cout << evaluate("11+21-43+888") << endl;
    }
    else if(testCase == 20) //test evaluate
    {
        cout << evaluate("-21") << endl;
    }
   
    cout << "===================================" << endl;

    return 0;
}


