/**
 * This is the student's tester
 */

#include "bigint.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <string>



using namespace std;



///If we want to test left-handed operators (e.g. int + BigInt, ...)
///Change: TestingType = int, TESTING_LHS = 1
///Otherwise: TestingType = long long, TESTING_LHS = 0

typedef long long TestingType;
const int TESTING_LHS = 0;

int TESTING_PARAM[2][4] = {{10000000, 1000000000, 20, 999999999}, {100, 100000, 10, 99999}};



int n, m;
BigInt b[201];
TestingType a[201];

ifstream fin;
ofstream fout1, fout2;



template <typename T>
void readToArray(T arr[]) {
    fin.open("input.txt");

    for (int i = 1; i <= n; ++i) {
        fin >> arr[i];
    }

    fin.close();
}



int main() {
    srand(time(NULL));

    cout << "Amount of numbers you want to generate (1 - 200): ";
    cin >> n;

    cout << "Amount of test you want to do: ";
    cin >> m;

    fout1.open("input.txt");

    TestingType x;

    for (int i = 1; i <= n; ++i) {
        x = ((TestingType)TESTING_PARAM[TESTING_LHS][0] * 100 + rand() % TESTING_PARAM[TESTING_LHS][1]);

        if (rand() % 30 == 0) {
            x = 0;
        }

        if (rand() % 15 == 0) {
            x = TESTING_PARAM[TESTING_LHS][3];
        }

        if (rand() % 2 == 0) {
            x = -x;
        }

        fout1 << x << endl;
    }

    fout1.close();

    readToArray(a);
    readToArray(b);

    fout1.open("outputLong.txt");
    fout2.open("outputBigInt.txt");

    for (int i = 1; i <= n; ++i) {
        fout1 << a[i] << endl;
        fout2 << b[i] << endl;
    }

    int first, second, v, shift;
    TestingType longFirst, longSecond;
    long long longRes;
    BigInt bigFirst, bigSecond, bigRes;

    for (int i = 1; i <= m; ++i) {
        first = 1 + rand() % n;
        second = 1 + rand() % n;

        longFirst = a[first];
        longSecond = a[second];

        bigFirst = b[first];
        bigSecond = b[second];

        v = rand() % 15;

        switch (v) {
            case 0:
                longRes = (long long)longFirst + longSecond;
                bigRes = (TESTING_LHS ? longFirst : bigFirst) + bigSecond;

                fout1 << longFirst << "+" << longSecond << "=" << longRes << endl;
                fout2 << bigFirst << "+" << bigSecond << "=" << bigRes << endl;

                break;

            case 1:
                longRes = (long long)longFirst - longSecond;
                bigRes = (TESTING_LHS ? longFirst : bigFirst) - bigSecond;

                fout1 << longFirst << "-" << longSecond << "=" << longRes << endl;
                fout2 << bigFirst << "-" << bigSecond << "=" << bigRes << endl;

                break;

            case 2:
                longRes = (long long)longFirst * longSecond;
                bigRes = (TESTING_LHS ? longFirst : bigFirst) * bigSecond;

                fout1 << longFirst << "*" << longSecond << "=" << longRes << endl;
                fout2 << bigFirst << "*" << bigSecond << "=" << bigRes << endl;

                break;

            case 3:
                if (bigSecond != 0) {
                    longRes = (long long)longFirst / longSecond;
                    bigRes = (TESTING_LHS ? longFirst : bigFirst) / bigSecond;

                    fout1 << longFirst << "/" << longSecond << "=" << longRes << endl;
                    fout2 << bigFirst << "/" << bigSecond << "=" << bigRes << endl;
                }

                break;

            case 4:
                if (bigSecond != 0) {
                    longRes = (long long)longFirst % longSecond;
                    bigRes = (TESTING_LHS ? longFirst : bigFirst) % bigSecond;

                    fout1 << longFirst << "+" << longSecond << "=" << longRes << endl;
                    fout2 << bigFirst << "+" << bigSecond << "=" << bigRes << endl;
                }

                break;

            case 5:
                longFirst = longSecond;
                bigFirst = bigSecond;

                fout1 << longFirst << " " << longSecond << endl;
                fout2 << bigFirst << " " << bigSecond << endl;

                break;

            case 6:
                fout1 << "++" << longFirst << " = " << ++longFirst << endl;
                fout2 << "++" << bigFirst << " = " << ++bigFirst << endl;

                fout1 << longSecond << "++ = " << longSecond++ << " " << longSecond << endl;
                fout2 << bigSecond << "++ = " << bigSecond++ << " " << bigSecond << endl;

                break;

            case 7:
                fout1 << "--" << longFirst << " = " << --longFirst << endl;
                fout2 << "--" << bigFirst << " = " << --bigFirst << endl;

                fout1 << longSecond << "-- = " << longSecond-- << " " << longSecond << endl;
                fout2 << bigSecond << "-- = " << bigSecond-- << " " << bigSecond << endl;


                break;

            case 8:
                longRes = (longFirst > longSecond);
                bigRes = BigInt((int)((TESTING_LHS ? longFirst : bigFirst) > bigSecond));

                fout1 << longFirst << ">" << longSecond << "=" << longRes << endl;
                fout2 << bigFirst << ">" << bigSecond << "=" << bigRes << endl;

                break;

            case 9:
                longRes = (longFirst >= longSecond);
                bigRes = BigInt((int)((TESTING_LHS ? longFirst : bigFirst) >= bigSecond));

                fout1 << longFirst << ">=" << longSecond << "=" << longRes << endl;
                fout2 << bigFirst << ">=" << bigSecond << "=" << bigRes << endl;

                break;

            case 10:
                longRes = (longFirst < longSecond);
                bigRes = BigInt((int)((TESTING_LHS ? longFirst : bigFirst) < bigSecond));

                fout1 << longFirst << "<" << longSecond << "=" << longRes << endl;
                fout2 << bigFirst << "<" << bigSecond << "=" << bigRes << endl;

                break;

            case 11:
                longRes = (longFirst <= longSecond);
                bigRes = BigInt((int)((TESTING_LHS ? longFirst : bigFirst) <= bigSecond));

                fout1 << longFirst << "<=" << longSecond << "=" << longRes << endl;
                fout2 << bigFirst << "<=" << bigSecond << "=" << bigRes << endl;

                break;

            case 12:
                longRes = (longFirst != longSecond);
                bigRes = BigInt((int)((TESTING_LHS ? longFirst : bigFirst) != bigSecond));

                fout1 << longFirst << "!=" << longSecond << "=" << longRes << endl;
                fout2 << bigFirst << "!=" << bigSecond << "=" << bigRes << endl;

                break;

            case 13:
                shift = rand() % TESTING_PARAM[TESTING_LHS][2];

                if (longFirst < 0) {
                    longFirst = -longFirst;
                }

                if (bigFirst < 0) {
                    bigFirst = - bigFirst;
                }

                longRes = (long long)longFirst  << shift;
                bigRes = bigFirst << shift;

                fout1 << longFirst << "<<" << shift << "=" << longRes << endl;
                fout2 << bigFirst << "<<" << shift << "=" << bigRes << endl;

                break;

            case 14:
                shift = rand() % TESTING_PARAM[TESTING_LHS][2];

                if (longFirst < 0) {
                    longFirst = -longFirst;
                }

                if (bigFirst < 0) {
                    bigFirst = - bigFirst;
                }

                longRes = longFirst  >> shift;
                bigRes = bigFirst >> shift;

                fout1 << longFirst << ">>" << shift << "=" << longRes << endl;
                fout2 << bigFirst << ">>" << shift << "=" << bigRes << endl;

                break;
        }
    }

    fout1.close();
    fout2.close();

    return 0;
}
