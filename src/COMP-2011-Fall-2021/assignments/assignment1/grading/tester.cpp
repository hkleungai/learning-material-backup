#include <iostream>
using namespace std;
const int MAX_ARR_LEN = 16;
const int MAX_ROTATIONS = 1024;

// Task 1
int rotate(int arr[], int arrLen, int k);
// Task 2
int swapAndRecord(int arr[], int arrLen, int indexA, int indexB, int rotations[], int &rotationLen);
// Task 3
void sortAndRecord(int arr[], int arrLen, int rotations[], int &rotationLen);
// Task 4
int transformAndRecord(int src[], int tgt[], int arrLen, int rotations[], int &rotationLen);

// Please copy and paste your implementation of the tasks under this line.
// If you have defined your own helper functions please also copy and paste them here.

// End of your implementation

int batchRotate(int arr[], int arrLen, int rotations[], int rotationLen)
{
    int tmp = 0;
    if (rotationLen < 0 || rotationLen >= MAX_ROTATIONS)
    {
        cout << "Testing Error: rotationLen = ";
        cout << rotationLen;
        cout << ", which is not in [0,MAX_ROTATIONS]." << endl;
        return -1;
    }
    for (int j = 0; j < rotationLen; j++)
    {
        if (rotations[j] >= arrLen || rotations[j] < 0)
        {
            cout << "Testing Error: rotations[";
            cout << j;
            cout << "] = ";
            cout << rotations[j];
            cout << ", which is not in [0,arrLen]." << endl;
            return -1;
        }
        for (int i = 0; i <= rotations[j] / 2; i++)
        {
            tmp = arr[i];
            arr[i] = arr[rotations[j] - i];
            arr[rotations[j] - i] = tmp;
        }
    }
    return 0;
}

void printArr(int arr[], int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
        cout << arr[i];
        if (i < arrLen - 1)
        {
            cout << ',';
        }
    }
    cout << endl;
}

void copyArr(int src[], int tgt[], int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
        tgt[i] = src[i];
    }
}

void testTask1(int arr[], int arrLen, int k)
{
    int returnVal;
    cout << "************************ Task 1 test settings ************************" << endl;
    cout << "arr=" << endl;
    printArr(arr, arrLen);
    cout << "arrLen=" << endl;
    cout << arrLen << endl;
    cout << "k=" << endl;
    cout << k << endl;
    cout << "********************** Calling Task 1 function ***********************" << endl;
    returnVal = rotate(arr, arrLen, k);
    cout << "After function call:" << endl;
    cout << "return=" << endl;
    cout << returnVal << endl;
    if (returnVal > -1)
    {
        cout << "arr=" << endl;
        printArr(arr, arrLen);
    }
}

void testTask2(int arr[], int arrLen, int indexA, int indexB)
{
    int arrCopy[MAX_ARR_LEN], rotations[MAX_ROTATIONS], rotationLen = 0, returnVal, testResult;
    copyArr(arr, arrCopy, arrLen);
    cout << "************************ Task 2 test settings ************************" << endl;
    cout << "arr=" << endl;
    printArr(arr, arrLen);
    cout << "arrLen=" << endl;
    cout << arrLen << endl;
    cout << "indexA=" << endl;
    cout << indexA << endl;
    cout << "indexB=" << endl;
    cout << indexB << endl;
    cout << "********************** Calling Task 2 function ***********************" << endl;
    returnVal = swapAndRecord(arr, arrLen, indexA, indexB, rotations, rotationLen);
    cout << "After function call:" << endl;
    cout << "return=" << endl;
    cout << returnVal << endl;
    if (returnVal > -1)
    {
        cout << "arr=" << endl;
        printArr(arr, arrLen);
        cout << "*** Checking the rotations by applying them on the original array ****" << endl;
        testResult = batchRotate(arrCopy, arrLen, rotations, rotationLen);
        if (testResult > -1)
        {
            cout << "arr'=" << endl;
            printArr(arrCopy, arrLen);
        }
    }
}

void testTask3(int arr[], int arrLen)
{
    int arrCopy[MAX_ARR_LEN], rotations[MAX_ROTATIONS], rotationLen = 0, returnVal, testResult;
    copyArr(arr, arrCopy, arrLen);
    cout << "************************ Task 3 test settings ************************" << endl;
    cout << "arr=" << endl;
    printArr(arr, arrLen);
    cout << "arrLen=" << endl;
    cout << arrLen << endl;
    cout << "********************** Calling Task 3 function ***********************" << endl;
    sortAndRecord(arr, arrLen, rotations, rotationLen);
    cout << "After function call:" << endl;
    cout << "arr=" << endl;
    printArr(arr, arrLen);
    cout << "*** Checking the rotations by applying them on the original array ****" << endl;
    testResult = batchRotate(arrCopy, arrLen, rotations, rotationLen);
    if (testResult > -1)
    {
        cout << "arr'=" << endl;
        printArr(arrCopy, arrLen);
    }
}

void testTask4(int src[], int tgt[], int arrLen)
{
    int arrCopy[MAX_ARR_LEN], rotations[MAX_ROTATIONS], rotationLen = 0, returnVal, testResult;
    copyArr(src, arrCopy, arrLen);
    cout << "************************ Task 4 test settings ************************" << endl;
    cout << "src=" << endl;
    printArr(src, arrLen);
    cout << "tgt=" << endl;
    printArr(tgt, arrLen);
    cout << "arrLen=" << endl;
    cout << arrLen << endl;
    cout << "********************** Calling Task 4 function ***********************" << endl;
    returnVal = transformAndRecord(src, tgt, arrLen, rotations, rotationLen);
    cout << "After function call:" << endl;
    cout << "return=" << endl;
    cout << returnVal << endl;
    if (returnVal > -1)
    {
        cout << "src=" << endl;
        printArr(src, arrLen);
        cout << "*** Checking the rotations by applying them on the original array ****" << endl;
        testResult = batchRotate(arrCopy, arrLen, rotations, rotationLen);
        if (testResult > -1)
        {
            cout << "src'=" << endl;
            printArr(arrCopy, arrLen);
        }
    }
}

void test01()
{
    int arr[] = {9, 1, 3, 5, 4}, arrLen = 5, k = 3;
    testTask1(arr, arrLen, k);
}

void test02()
{
    int arr[] = {9, 1, 3, 5, 4}, arrLen = 5, k = 6;
    testTask1(arr, arrLen, k);
}

void test03()
{
    int arr[] = {1, 3, 5, 7, 2, 4, 6}, arrLen = 7, indexA = 5, indexB = 2;
    testTask2(arr, arrLen, indexA, indexB);
}

void test04()
{
    int arr[] = {1, 3, 5, 7, 2, 4, 6}, arrLen = 7, indexA = 5, indexB = 10;
    testTask2(arr, arrLen, indexA, indexB);
}

void test05()
{
    int arr[] = {1, 3, 5, 7, 2, 4, 6}, arrLen = 7;
    testTask3(arr, arrLen);
}

void test06()
{
    int src[] = {1, 3, 5, 7, 2, 4, 6}, tgt[] = {1, 5, 3, 7, 2, 4, 6}, arrLen = 7;
    testTask4(src, tgt, arrLen);
}

void test07()
{
    int src[] = {1, 3, 5, 7, 2, 4, 6}, tgt[] = {1, 5, 3, 7, 2, 4, 7}, arrLen = 7;
    testTask4(src, tgt, arrLen);
}

void test08()
{
    int arr[] = {1}, arrLen = 1, k = 0;
    testTask1(arr, arrLen, k);
}

void test09()
{
    int arr[] = {1, 2}, arrLen = 2, k = 1;
    testTask1(arr, arrLen, k);
}

void test10()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, k = 1;
    testTask1(arr, arrLen, k);
}

void test11()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, k = 2;
    testTask1(arr, arrLen, k);
}

void test12()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, k = 15;
    testTask1(arr, arrLen, k);
}

void test13()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, k = 16;
    testTask1(arr, arrLen, k);
}

void test14()
{
    int arr[] = {1, 2}, arrLen = 2, indexA = 0, indexB = 1;
    testTask2(arr, arrLen, indexA, indexB);
}

void test15()
{
    int arr[] = {1, 2, 3}, arrLen = 3, indexA = 0, indexB = 2;
    testTask2(arr, arrLen, indexA, indexB);
}

void test16()
{
    int arr[] = {1, 2, 3}, arrLen = 3, indexA = 1, indexB = 2;
    testTask2(arr, arrLen, indexA, indexB);
}

void test17()
{
    int arr[] = {1, 2, 3, 4}, arrLen = 4, indexA = 0, indexB = 3;
    testTask2(arr, arrLen, indexA, indexB);
}

void test18()
{
    int arr[] = {1, 2, 3, 4}, arrLen = 4, indexA = 1, indexB = 3;
    testTask2(arr, arrLen, indexA, indexB);
}

void test19()
{
    int arr[] = {1, 2, 3, 4, 5}, arrLen = 5, indexA = 0, indexB = 4;
    testTask2(arr, arrLen, indexA, indexB);
}

void test20()
{
    int arr[] = {1, 2, 3, 4, 5}, arrLen = 5, indexA = 1, indexB = 4;
    testTask2(arr, arrLen, indexA, indexB);
}

void test21()
{
    int arr[] = {1, 2, 3, 4, 5}, arrLen = 5, indexA = 2, indexB = 4;
    testTask2(arr, arrLen, indexA, indexB);
}

void test22()
{
    int arr[] = {1, 2, 3, 4, 5, 6}, arrLen = 6, indexA = 2, indexB = 5;
    testTask2(arr, arrLen, indexA, indexB);
}

void test23()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, indexA = 6, indexB = 15;
    testTask2(arr, arrLen, indexA, indexB);
}

void test24()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, indexA = 15, indexB = 6;
    testTask2(arr, arrLen, indexA, indexB);
}

void test25()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6}, arrLen = 16, indexA = 15, indexB = 16;
    testTask2(arr, arrLen, indexA, indexB);
}

void test26()
{
    int arr[] = {1}, arrLen = 1;
    testTask3(arr, arrLen);
}

void test27()
{
    int arr[] = {9, 8}, arrLen = 2;
    testTask3(arr, arrLen);
}

void test28()
{
    int arr[] = {9, 8, 7, 6, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0}, arrLen = 16;
    testTask3(arr, arrLen);
}

void test29()
{
    int arr[] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9}, arrLen = 16;
    testTask3(arr, arrLen);
}

void test30()
{
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, arrLen = 16;
    testTask3(arr, arrLen);
}

void test31()
{
    int arr[] = {4, 3, 7, 5, 8, 1, 5, 0, 8, 0, 5, 6, 3, 7, 6}, arrLen = 15;
    testTask3(arr, arrLen);
}

void test32()
{
    int arr[] = {5, 0, 8, 7, 4, 6}, arrLen = 6;
    testTask3(arr, arrLen);
}

void test33()
{
    int arr[] = {2, 6, 6, 2, 7, 9, 7, 7}, arrLen = 8;
    testTask3(arr, arrLen);
}

void test34()
{
    int arr[] = {8, 8, 9, 5, 0, 0, 5, 8, 1, 5, 0, 9, 4}, arrLen = 13;
    testTask3(arr, arrLen);
}

void test35()
{
    int arr[] = {8, 5, 8, 6, 2, 0, 6}, arrLen = 7;
    testTask3(arr, arrLen);
}

void test36()
{
    int src[] = {1}, tgt[] = {1}, arrLen = 1;
    testTask4(src, tgt, arrLen);
}

void test37()
{
    int src[] = {1, 2}, tgt[] = {2, 1}, arrLen = 2;
    testTask4(src, tgt, arrLen);
}

void test38()
{
    int src[] = {1, 2}, tgt[] = {2, 3}, arrLen = 2;
    testTask4(src, tgt, arrLen);
}

void test39()
{
    int src[] = {1, 1}, tgt[] = {1, 1}, arrLen = 2;
    testTask4(src, tgt, arrLen);
}

void test40()
{
    int src[] = {0, 6, 3, 4, 4, 5, 6, 1, 2, 8}, tgt[] = {4, 6, 0, 1, 8, 2, 3, 5, 4, 6}, arrLen = 10;
    testTask4(src, tgt, arrLen);
}

void test41()
{
    int src[] = {5, 0, 8, 9, 3, 7, 3, 1, 3, 0, 0, 0, 5, 1}, tgt[] = {9, 8, 5, 0, 0, 1, 3, 3, 7, 0, 5, 0, 3, 1}, arrLen = 14;
    testTask4(src, tgt, arrLen);
}

void test42()
{
    int src[] = {2, 0, 6, 5, 1, 5, 5, 8, 9, 3, 8, 7, 0, 2, 0, 0}, tgt[] = {2, 0, 9, 0, 6, 8, 7, 3, 0, 5, 2, 0, 8, 5, 5, 1}, arrLen = 16;
    testTask4(src, tgt, arrLen);
}

void test43()
{
    int src[] = {1, 0, 4, 5, 9, 7, 5, 9, 1, 8}, tgt[] = {8, 1, 5, 9, 5, 4, 0, 1, 7, 9}, arrLen = 10;
    testTask4(src, tgt, arrLen);
}

void test44()
{
    int src[] = {3, 5}, tgt[] = {5, 3}, arrLen = 2;
    testTask4(src, tgt, arrLen);
}

void test45()
{
    int src[] = {9, 6, 9}, tgt[] = {9, 9, 6}, arrLen = 3;
    testTask4(src, tgt, arrLen);
}

void test46()
{
    int src[] = {9, 9, 7, 3, 7, 6, 3}, tgt[] = {3, 9, 7, 9, 6, 7, 3}, arrLen = 7;
    testTask4(src, tgt, arrLen);
}

void test47()
{
    int src[] = {0, 2, 7, 2, 0, 2, 7}, tgt[] = {2, 7, 0, 2, 7, 2, 0}, arrLen = 7;
    testTask4(src, tgt, arrLen);
}

int main(int argc, char **argv)
{
    test10(); //run test case 10
    test20(); //run test case 20
    test30(); //run test case 30
    return 0;
}
