#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

#include "bigint.h"
#include "mathtest.h"

using namespace std;

bool test_add(int a, int b) {
    int expected = a + b;
    BigInt p = BigInt(a);
    BigInt q = BigInt(b);
    BigInt actual = p + q;
    return expected == actual;
}

/**
 * BigInt + int
 */
bool test_add2(int a, int b) {
    int expected = a + b;
    BigInt p = BigInt(a);
    BigInt actual = p + b;
    return expected == actual;
}

/**
 * int + BitInt
 */
bool test_add3(int a, int b) {
    int expected = a + b;
    BigInt q = BigInt(b);
    BigInt actual = a + q;
    return expected == actual;
}

/**
 * BigInt - BigInt
 */
bool test_subtract(int a, int b) {
    int expected = a - b;
    BigInt p = BigInt(a);
    BigInt q = BigInt(b);
    BigInt actual = p - q;
    return expected == actual;
}

/**
 * BigInt - int
 */
bool test_subtract2(int a, int b) {
    int expected = a - b;
    BigInt p = BigInt(a);
    BigInt actual = p - b;
    return expected == actual;
}

/**
 * int - BitInt
 */
bool test_subtract3(int a, int b) {
    int expected = a - b;
    BigInt q = BigInt(b);
    BigInt actual = a - q;
    return expected == actual;
}

/**
 * BigInt * BigInt
 */
bool test_multiply(int a, int b) {
    int expected = a * b;
    BigInt p = BigInt(a);
    BigInt q = BigInt(b);
    BigInt actual = p * q;

    if (a == 46337 && b == 46345) {
        cout << a << endl;
        cout << b << endl;
        cout << expected << endl;
        cout << actual << endl;
    }

    return expected == actual;
}

/**
 * BigInt * int
 */
bool test_multiply2(int a, int b) {
    int expected = a * b;
    BigInt p = BigInt(a);
    BigInt actual = p * b;
    return expected == actual;
}

/**
 * int * BitInt
 */
bool test_multiply3(int a, int b) {
    int expected = a * b;
    BigInt q = BigInt(b);
    BigInt actual = a * q;
    return expected == actual;
}

/**
 * BigInt / BigInt
 */
bool test_divide(int a, int b) {
    BigInt actual;
    BigInt p = BigInt(a);
    BigInt q = BigInt(b);

    try {
        actual = p / q;
    } catch (const domain_error& e) {
        if (b == 0) {
            return true;
        }
    }

    if (b == 0) {
        return false;
    }

    int expected = a / b;
    return expected == actual;
}

/**
 * BigInt / int
 */

bool test_divide2(int a, int b) {
    BigInt actual;
    BigInt p = BigInt(a);

    try {
        actual = p / b;
    } catch (const domain_error& e) {
        if (b == 0) {
            return true;
        }
    }

    if (b == 0) {
        return false;
    }

    int expected = a / b;
    return expected == actual;
}

/**
 * int / BitInt
 */
bool test_divide3(int a, int b) {
    BigInt actual;
    BigInt q = BigInt(b);

    try {
        actual = a / q;
    } catch (const domain_error& e) {
        if (b == 0) {
            return true;
        }
    }

    if (b == 0) {
        return false;
    }

    int expected = a / b;
    return expected == actual;
}

/**
 * BigInt % BigInt
 */
bool test_mod(int a, int b) {
    BigInt actual;
    BigInt p = BigInt(a);
    BigInt q = BigInt(b);

    try {
        actual = p % q;
    } catch (const domain_error& e) {
        if (b == 0) {
            return true;
        }
    }

    if (b == 0) {
        return false;
    }

    int expected = a % b;
    return expected == actual;
}

/**
 * BigInt % int
 */

bool test_mod2(int a, int b) {
    BigInt actual;
    BigInt p = BigInt(a);

    try {
        actual = p % b;
    } catch (const domain_error& e) {
        if (b == 0) {
            return true;
        }
    }

    if (b == 0) {
        return false;
    }

    int expected = a % b;
    return expected == actual;
}

/**
 * int % BitInt
 */
bool test_mod3(int a, int b) {
    BigInt actual;
    BigInt q = BigInt(b);

    try {
        actual = a % q;
    } catch (const domain_error& e) {
        if (b == 0) {
            return true;
        }
    }

    if (b == 0) {
        return false;
    }

    int expected = a % b;
    return expected == actual;
}

/**
 * BigInt < BigInt
 */
bool test_lt(int a, int b) {
    bool expected = a < b;
    BigInt p = BigInt(a);
    BigInt q = BigInt(b);
    bool actual = p < q;
    return expected == actual;
}

/**
 * BigInt < int
 */
bool test_lt2(int a, int b) {
    bool expected = a < b;
    BigInt p = BigInt(a);
    bool actual = p < b;
    return expected == actual;
}

/**
 * int < BigInt
 */
bool test_lt3(int a, int b) {
    bool expected = a < b;
    BigInt q = BigInt(b);
    bool actual = a < q;
    return expected == actual;
}

/**
 * BigInt <= BigInt
 */
bool test_le(int a, int b) {
    bool expected = a <= b;
    BigInt p = BigInt(a);
    BigInt q = BigInt(b);
    bool actual = p <= q;
    return expected == actual;
}

/**
 * BigInt <= int
 */
bool test_le2(int a, int b) {
    bool expected = a <= b;
    BigInt p = BigInt(a);
    bool actual = p <= b;
    return expected == actual;
}

/**
 * int <= BigInt
 */
bool test_le3(int a, int b) {
    bool expected = a <= b;
    BigInt q = BigInt(b);
    bool actual = a <= q;
    return expected == actual;
}

/**
 * BigInt == BigInt
 */
bool test_equal(int a, int b) {
    bool expected = a == b;
    BigInt p = BigInt(a);
    BigInt q = BigInt(b);
    bool actual = p == q;
    return expected == actual;
}

/**
 * BigInt == int
 */
bool test_equal2(int a, int b) {
    bool expected = a == b;
    BigInt p = BigInt(a);
    bool actual = p == b;
    return expected == actual;
}

/**
 * int == BigInt
 */
bool test_equal3(int a, int b) {
    bool expected = a == b;
    BigInt q = BigInt(b);
    bool actual = a == q;
    return expected == actual;
}

/**
 * BigInt >= BigInt
 */
bool test_ge(int a, int b) {
    bool expected = a >= b;
    BigInt p = BigInt(a);
    BigInt q = BigInt(b);
    bool actual = p >= q;
    return expected == actual;
}

/**
 * BigInt >= int
 */
bool test_ge2(int a, int b) {
    bool expected = a >= b;
    BigInt p = BigInt(a);
    bool actual = p >= b;
    return expected == actual;
}

/**
 * int >= BigInt
 */
bool test_ge3(int a, int b) {
    bool expected = a >= b;
    BigInt q = BigInt(b);
    bool actual = a >= q;
    return expected == actual;
}

/**
 * BigInt > BigInt
 */
bool test_gt(int a, int b) {
    bool expected = a > b;
    BigInt p = BigInt(a);
    BigInt q = BigInt(b);
    bool actual = p > q;
    return expected == actual;
}

/**
 * BigInt > int
 */
bool test_gt2(int a, int b) {
    bool expected = a > b;
    BigInt p = BigInt(a);
    bool actual = p > b;
    return expected == actual;
}

/**
 * int > BigInt
 */
bool test_gt3(int a, int b) {
    bool expected = a > b;
    BigInt q = BigInt(b);
    bool actual = a > q;
    return expected == actual;
}

/**
 * BigInt != BigInt
 */
bool test_not_equal(int a, int b) {
    bool expected = a != b;
    BigInt p = BigInt(a);
    BigInt q = BigInt(b);
    bool actual = p != q;
    return expected == actual;
}

/**
 * BigInt != int
 */
bool test_not_equal2(int a, int b) {
    bool expected = a != b;
    BigInt p = BigInt(a);
    bool actual = p != b;
    return expected == actual;
}

/**
 * int != BigInt
 */
bool test_not_equal3(int a, int b) {
    bool expected = a != b;
    BigInt q = BigInt(b);
    bool actual = a != q;
    return expected == actual;
}

bool test_increment_prefix(int n) {
    int expected = n + 1;
    BigInt bi = n;
    BigInt actual = ++bi;
    return expected == actual;
}

bool test_increment_postfix(int n) {
    int expected = n;
    BigInt bi = n;
    BigInt actual = bi++;
    return expected == actual;
}

bool test_decrement_prefix(int n) {
    int expected = n - 1;
    BigInt bi = n;
    BigInt actual = --bi;
    return expected == actual;
}

bool test_decrement_postfix(int n) {
    int expected = n;
    BigInt bi = n;
    BigInt actual = bi--;
    return expected == actual;
}

bool test_unary_plus(int n) {
    int expected = n;
    BigInt bi = n;
    BigInt actual = +bi;
    return expected == actual;
}

bool test_unary_minus(int n) {
    int expected = -n;
    BigInt bi = n;
    BigInt actual = -bi;
    return expected == actual;
}

void test_runner(bool (*func)()) {
    if ((*func)()) {
        return;
    }

    ostringstream os;
    os << "Runner failed";
    throw domain_error(os.str());
}

void test_runner(bool (*func)(int), int i) {
    if ((*func)(i)) {
        return;
    }

    ostringstream os;
    os << "Runner failed at i=" << i;
    throw domain_error(os.str());
}

void test_runner(bool (*func)(int, int), int i, int j) {
    if ((*func)(i, j)) {
        return;
    }

    ostringstream os;
    os << "Runner failed at i=" << i << ", j=" << j;
    throw domain_error(os.str());
}

void test_looper_range(bool (*func)(int, int), int h, int k, int delta) {

    for (int i = h - delta; i <= h + delta; ++i) {
        for (int j = k - delta; j <= k + delta; ++j) {
            test_runner(func, i, j);
        }
    }
}

void test_lopper(bool (*func)(int, int)) {
    int delta = 5;
    int k0 = 0;
    int k1 = 100;
    int k2 = k1 * 100;
    int k3 = 46335;

    // degree 0 play with degree 0
    test_looper_range(func, k0, k0, delta);

    // degree 1 and degree 1
    test_looper_range(func, k1, k1, delta);
    test_looper_range(func, k1, -k1, delta);
    test_looper_range(func, -k1, k1, delta);
    test_looper_range(func, -k1, -k1, delta);

    // degree 1 and degree 0
    test_looper_range(func, k1, k0, delta);
    test_looper_range(func, k1, -k0, delta);
    test_looper_range(func, -k1, k0, delta);
    test_looper_range(func, -k1, -k0, delta);

    // degree 2 and degree 2
    test_looper_range(func, k2, k2, delta);
    test_looper_range(func, k2, -k2, delta);
    test_looper_range(func, -k2, k2, delta);
    test_looper_range(func, -k2, -k2, delta);

    // degree 2 and degree 1
    test_looper_range(func, k2, k1, delta);
    test_looper_range(func, k2, -k1, delta);
    test_looper_range(func, -k2, k1, delta);
    test_looper_range(func, -k2, -k1, delta);
    test_looper_range(func, k1, k2, delta);
    test_looper_range(func, k1, -k2, delta);
    test_looper_range(func, -k1, k2, delta);
    test_looper_range(func, -k1, -k2, delta);

    // degree 2 and degree 0
    test_looper_range(func, k2, k0, delta);
    test_looper_range(func, k2, -k0, delta);
    test_looper_range(func, -k2, k0, delta);
    test_looper_range(func, -k2, -k0, delta);

    // degree 3 and degree 3
    test_looper_range(func, k3, k3, delta);
    test_looper_range(func, k3, -k3, delta);
    test_looper_range(func, -k3, k3, delta);
    test_looper_range(func, -k3, -k3, delta);

    // degree 3 and degree 2
    test_looper_range(func, k3, k2, delta);
    test_looper_range(func, k3, -k2, delta);
    test_looper_range(func, -k3, k2, delta);
    test_looper_range(func, -k3, -k2, delta);
    test_looper_range(func, k2, k3, delta);
    test_looper_range(func, k2, -k3, delta);
    test_looper_range(func, -k2, k3, delta);
    test_looper_range(func, -k2, -k3, delta);

    // degree 3 and degree 1
    test_looper_range(func, k3, k1, delta);
    test_looper_range(func, k3, -k1, delta);
    test_looper_range(func, -k3, k1, delta);
    test_looper_range(func, -k3, -k1, delta);
    test_looper_range(func, k1, k3, delta);
    test_looper_range(func, k1, -k3, delta);
    test_looper_range(func, -k1, k3, delta);
    test_looper_range(func, -k1, -k3, delta);

    // degree 3 and degree 0
    test_looper_range(func, k3, k0, delta);
    test_looper_range(func, k3, -k0, delta);
    test_looper_range(func, -k3, k0, delta);
    test_looper_range(func, -k3, -k0, delta);

}

void test_arithmetic() {
    bool (*test_functions[])(int, int) = {
        //  0th
            &test_add,
            &test_add2,
            &test_add3,
            // 3th
            &test_subtract,
            &test_subtract2,
            &test_subtract3,
            // 6th
            &test_multiply,
            &test_multiply2,
            &test_multiply3,
            // 9th
            &test_divide,
            &test_divide2,
            &test_divide3,
            // 12th
            &test_mod,
            &test_mod2,
            &test_mod3,
        };

    int func_count = sizeof(test_functions) / sizeof(void (*));

    for (int i = 0; i < func_count; i++) {
        try {
            test_lopper(test_functions[i]);
        } catch (const exception& ex) {
            ostringstream os;
            os << ex.what() << " when testing the " << i << "th arithmetic test";
            cerr << os.str();
            throw domain_error(os.str());
        }
    }
}

void test_binary() {
    bool (*test_functions[])(int, int) = {
        //  0th
            &test_lt,
            &test_lt2,
            &test_lt3,
            // 3th
            &test_le,
            &test_le2,
            &test_le3,
            // 6th
            &test_equal,
            &test_equal2,
            &test_equal3,
            // 9th
            &test_not_equal,
            &test_not_equal2,
            &test_not_equal3,
            // 12th
            &test_ge,
            &test_ge2,
            &test_ge3,
            // 15th
            &test_gt,
            &test_gt2,
            &test_gt3,
        };

    int func_count = sizeof(test_functions) / sizeof(void (*));

    int a = 1083216;
    int b = 324032;

    for (int i = 0; i < func_count; i++) {
        try {
            test_runner(test_functions[i], 0, 0);
            test_runner(test_functions[i], 0, a);
            test_runner(test_functions[i], 0, -a);
            test_runner(test_functions[i], a, 0);
            test_runner(test_functions[i], -a, 0);

            test_runner(test_functions[i], a, a);
            test_runner(test_functions[i], a, -a);
            test_runner(test_functions[i], -a, a);
            test_runner(test_functions[i], -a, -a);

            test_runner(test_functions[i], a, b);
            test_runner(test_functions[i], a, -b);
            test_runner(test_functions[i], -a, b);
            test_runner(test_functions[i], -a, -b);
            test_runner(test_functions[i], b, a);
            test_runner(test_functions[i], b, -a);
            test_runner(test_functions[i], -b, a);
            test_runner(test_functions[i], -b, -a);
        } catch (const exception& ex) {
            ostringstream os;
            os << ex.what() << " when testing the " << i << "th relational test";
            cerr << os.str();
            throw domain_error(os.str());
        }
    }
}

void test_unary() {
    bool (*test_functions[])(int) = {
        //  0th
            &test_increment_prefix,
            &test_increment_postfix,
            &test_decrement_prefix,
            &test_decrement_postfix,
        };

    int func_count = sizeof(test_functions) / sizeof(void (*));

    int a = 51;

    for (int i = 0; i < func_count; i++) {
        try {
            test_runner(test_functions[i], 0);
            test_runner(test_functions[i], a);
            test_runner(test_functions[i], -a);
        } catch (const exception& ex) {
            ostringstream os;
            os << ex.what() << " when testing the " << i << "th relational test";
            cerr << os.str();
            throw domain_error(os.str());
        }
    }
}

void test_stream() {
    stringstream ss;

    int i = -23490923;

    BigInt bi1 = i;
    BigInt bi2;
    ss << bi1;
    ss >> bi2;

    if (bi1 != bi2) {
        throw domain_error("stream test failed");
    }

}

int main() {
    test_stream();
    test_arithmetic();
    test_binary();
    test_unary();

    cout << "Every tests are finished!" << endl;
}
