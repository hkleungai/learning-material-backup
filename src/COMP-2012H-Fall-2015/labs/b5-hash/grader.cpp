// Non-interactive test program for the Table template class

#include <iostream> // Provides cout.
#include "table2.h"   // Provides the Table template class.
using namespace std;

// Descriptions and points for each of the tests:
const int MANY_TESTS = 2;
const int POINTS[MANY_TESTS+1] = {
    15,  // Total points for all tests.
    10, // Test 1 points
    5,  // Test 2 points
};
const char DESCRIPTION[MANY_TESTS+1][256] = {
    "tests for Table template class",
    "Testing insert and the const member functions",
    "Testing remove",
};

// **************************************************************************
// TRec type
//   Each table will use the following data type for its entries, with
//   keys ranging from 0 through MAX_KEY.
// **************************************************************************
struct TRec
{
    int key;
    double examdata;
};
const int MAX_KEY = 5000;



// **************************************************************************
// bool correct(const Table<TRec>& test, int s, double right_data[])
//   This function determines if the Table (test) is "correct" according to
//   these requirements for each i in the range 0..MAX_KEY:
//   a. if right_data[i] < 0 then there should be no item with key i
//      in the table.
//   b. if right_data[i] > 0, then the item with key i in the table should
//      have data of right_data[i].
//   If the requirements are met, then the function returns true. Otherwise
//   the function returns false. In either case a message about the test
//   result is printed to cout.
// **************************************************************************
bool correct(const Table<TRec>& test, double right_data[])
{
    int i;
    bool answer = true;
    bool find_result, is_present_result, should_be_present;
    TRec find_record;
    int n = 0;

    for (i = 0; answer && (i <= MAX_KEY); i++)
    {   // Test the is_present and find member functions
        should_be_present = (right_data[i] >= 0);
        is_present_result = test.is_present(i);
        test.find(i, find_result, find_record);
        // Check that the boolean values are correct
        if (should_be_present != is_present_result)
            answer = false;
        else if (should_be_present != find_result)
            answer = false;
        else if (should_be_present && (right_data[i] != find_record.examdata))
            answer = false;
        // Update the count of the size of the Table
        if (should_be_present) n++;
    }
    if (test.size( ) != n)
        answer = false;

    cout << (answer ? "Test passed.\n" : "Test failed.\n") << endl;
    return answer;
}



// **************************************************************************
// int test1( )
//   Performs some basic tests of insert and the constant member
//   functions. Returns POINTS[1] if the tests are passed. Otherwise returns 0.
// **************************************************************************
int test1( )
{
    const int TESTSIZE = 3000; // Size of a large test.
    
    Table<TRec> test;
    TRec test_record;
    double right_data[MAX_KEY+1];
    char test_letter = 'A';
    int i;
    int next;

    // Initialize each right_data[i] to -1, indicating that there is
    // no entry in the table for key i.
    for (i = 0; i <= MAX_KEY; i++)
        right_data[i] = -1;

    cout << test_letter++ << ". ";
    cout << "Testing size, is_present and find for an empty table.";
    cout << endl;
    if (!correct(test, right_data)) return 0;

    cout << test_letter++ << ". ";
    cout << "Adding a record with key 4 to the Table, and then testing\n";
    cout << "   size, is_present and find.";
    cout << endl;
    test_record.key = 4;
    test_record.examdata = right_data[4] = 40.0;
    test.insert(test_record);
    if (!correct(test, right_data)) return 0;

    cout << test_letter++ << ". ";
    cout << "Adding a record with key 813 to the Table, and then testing\n";
    cout << "   size, is_present and find.";
    cout << endl;
    test_record.key = 813;
    test_record.examdata = right_data[813] = 8130.0;
    test.insert(test_record);
    if (!correct(test, right_data)) return 0;

    cout << test_letter++ << ". ";
    cout << "Adding a NEW record with key 4 to the Table, and then testing.\n";
    cout << "   This should change the record with key number 4.";
    cout << endl;
    test_record.key = 4;
    test_record.examdata = right_data[4] = 400.0;
    test.insert(test_record);
    if (!correct(test, right_data)) return 0;
    
    cout << test_letter++ << ". ";
    cout << "Adding a record with key 811 to the Table, and then testing.\n";
    cout << endl;
    test_record.key = 811;
    test_record.examdata = right_data[811] = 8110.0;
    test.insert(test_record);
    if (!correct(test, right_data)) return 0;

    cout << test_letter++ << ". ";
    cout << "Adding a record with key 810 to the Table, and then testing.\n";
    cout << endl;
    test_record.key = 810;
    test_record.examdata = right_data[810] = 8100.0;
    test.insert(test_record);
    if (!correct(test, right_data)) return 0;

    cout << test_letter++ << ". ";
    cout << "Adding a record with key 1611 to the Table, and then testing.\n";
    cout << endl;
    test_record.key = 1611;
    test_record.examdata = right_data[1611] = 16110.0;
    test.insert(test_record);
    if (!correct(test, right_data)) return 0;

    cout << test_letter++ << ". ";
    cout << "Adding a record with key 0 to the Table, and then testing.\n";
    cout << endl;
    test_record.key = 0;
    test_record.examdata = right_data[0] = 42.0;
    test.insert(test_record);
    if (!correct(test, right_data)) return 0;

    cout << test_letter++ << ". ";
    cout << "Inserting " << TESTSIZE << " random items with keys\n";
    cout << "between 0 and " << MAX_KEY << ", and then testing.";
    cout << endl;
    for (i = 6; i < TESTSIZE; i++)
    {
        next = rand( ) % (MAX_KEY + 1);
        test_record.key = next;
        test_record.examdata = right_data[next] = next/10.0;
        test.insert(test_record);
    }
    if (!correct(test, right_data)) return 0;

    return POINTS[1];
}



// **************************************************************************
// int test2( )
//   Performs some basic tests of the remove function.
//   Returns POINTS[2] if the tests are passed. Otherwise returns 0.
// **************************************************************************
int test2( )
// Postcondition: A handful of removal tests have been run on the 
// Table<TRec> data type. If all tests are passed, then the function
// returns 20. Otherwise the function returns zero.
{
    const int TESTSIZE = 3000; // Size of a large test.
    
    Table<TRec> test;
    TRec test_record;
    double right_data[MAX_KEY+1];
    char test_letter = 'A';
    int i;
    int next;

    // Initialize each right_data[i] to -1, indicating that there is
    // no entry in the table for key i.
    for (i = 0; i <= MAX_KEY; i++)
        right_data[i] = -1;

    cout << test_letter++ << ". ";
    cout << "Putting one record into the Table, then removing it.\n";
    test_record.key = 0;
    test_record.examdata = 42.0;
    test.insert(test_record);
    test.remove(0);
    cout << endl;
    if (!correct(test, right_data)) return 0;

    cout << test_letter++ << ". ";
    cout << "Adding a records with keys 4,5,6 to the Table, and then\n";
    cout << "   removing the 5 before testing.";
    cout << endl;
    test_record.key = 4;
    test_record.examdata = right_data[4] = 40.0;
    test.insert(test_record);
    test_record.key = 5;
    test_record.examdata = 50.0;
    test.insert(test_record);
    test_record.key = 6;
    test_record.examdata = right_data[6] = 60.0;
    test.insert(test_record);
    test.remove(5);
    if (!correct(test, right_data)) return 0;

    cout << test_letter++ << ". ";
    cout << "Trying to remove a key that is not present.\n";
    cout << "   This should have no effect on the Table.";
    cout << endl;
    test.remove(815);
    if (!correct(test, right_data)) return 0;

    cout << test_letter++ << ". ";
    cout << "Inserting " << TESTSIZE << " random items with keys\n";
    cout << "between 0 and " << MAX_KEY << ", and then removing about half.";
    cout << endl;
    for (i = 0; i < TESTSIZE; i++)
    {
        next = rand( ) % (MAX_KEY + 1);
        test_record.key = next;
        test_record.examdata = right_data[next] = next/10.0;
        test.insert(test_record);
    }
    for (i = 0; i < MAX_KEY; i++)
    {
        if (rand( ) % 2 == 0)
        {
            test.remove(i);
            right_data[i] = -1;
        }
    }
    if (!correct(test, right_data)) return 0;

    return POINTS[2];
}

int run_a_test(int number, const char message[], int test_function( ), int max)
{
    int result;
    
    cout << endl << "START OF TEST " << number << ":" << endl;
    cout << message << " (" << max << " points)." << endl;
    result = test_function( );
    if (result > 0)
    {
        cout << "Test " << number << " got " << result << " points";
        cout << " out of a possible " << max << "." << endl;
    }
    else
        cout << "Test " << number << " failed." << endl;
    cout << "END OF TEST " << number << "." << endl << endl;
    
    return result;
}


// **************************************************************************
// int main( )
//   The main program calls all tests and prints the sum of all points
//   earned from the tests.
// **************************************************************************
int main( )
{
    int sum = 0;
    
    
    cout << "Running " << DESCRIPTION[0] << endl;

    sum += run_a_test(1, DESCRIPTION[1], test1, POINTS[1]);
    sum += run_a_test(2, DESCRIPTION[2], test2, POINTS[2]);

    cout << "If you submit this List to the TA now, you will have\n";
    cout << sum << " points out of the " << POINTS[0];
    cout << " points from this test program.\n";
    
	int dummy;
	cin >> dummy;

    return EXIT_SUCCESS;

}
