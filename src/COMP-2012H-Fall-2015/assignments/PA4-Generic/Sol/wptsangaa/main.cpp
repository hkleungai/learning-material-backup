/*
 * main.cpp
 * This is only a demo of BigInt test program. The one which grades your homework will be more complete and more strict.
 */

#include "bigint.h"
#include "mathtest.h"

#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

char str[1024];

bool test_addition() {
	// 2000+3000
	BigInt bi1("2000");
	BigInt bi2("3000");
	BigInt result = bi1 + bi2;
	result.to_string(str);
	return strcmp(str, "5000") == 0;
}

bool test_subtraction() {
	// 2000-3000
	BigInt bi1("2000");
	BigInt bi2("3000");
	BigInt result = bi1 - bi2;
	result.to_string(str);
	return strcmp(str, "-1000") == 0;
}

bool test_multiplication() {
	// 500*600
	BigInt bi1("500");
	BigInt bi2("600");
	BigInt result = bi1 * bi2;
	result.to_string(str);
	return strcmp(str, "300000") == 0;
}

bool test_division() {
	// 1200/60
	BigInt bi1("1200");
	BigInt bi2("60");
	BigInt result = bi1 / bi2;
	result.to_string(str);
	return strcmp(str, "20") == 0;
}

bool test_mod() {
	// 1200/45
	BigInt bi1("1200");
	BigInt bi2("45");
	BigInt result = bi1 % bi2;
	result.to_string(str);
	return strcmp(str, "30") == 0;
}

bool test_assignment() {
	// bi2=-12345
	BigInt bi1("-12345");
	BigInt bi2;
	bi2 = bi1;
	bi2.to_string(str);
	return strcmp(str, "-12345") == 0;
}

bool test_incdec() {
	// bi++
	BigInt bi("12345");
	bi++;
	bi.to_string(str);
	return strcmp(str, "12346") == 0;
}

bool test_comparison() {
	// 12345<54321
	BigInt bi1("12345");
	BigInt bi2("54321");
	return bi1 < bi2;
}

bool test_shift() {
	// 1000<<2
	BigInt bi("1000");
	BigInt result = bi << 2;
	result.to_string(str);
	return strcmp(str, "4000") == 0;
}

bool test_iostream() {
    // output
    stringstream ss;
    BigInt bi("1000");
    ss << bi;
    return strcmp(ss.str().c_str(), "1000") == 0;
}

int main() {
    cout << "addition: " << test_addition() << endl;
    cout << "subtraction: " << test_subtraction() << endl;
    cout << "multiplication: " << test_multiplication() << endl;
    cout << "division: " << test_division() << endl;
    cout << "mod: " << test_mod() << endl;
    cout << "assigment: " << test_assignment() << endl;
    cout << "incdec: " << test_incdec() << endl;
    cout << "comparison: " << test_comparison() << endl;
    cout << "iostream: " << test_iostream() << endl;
    cout << "shift: " << test_shift() << endl;
}
