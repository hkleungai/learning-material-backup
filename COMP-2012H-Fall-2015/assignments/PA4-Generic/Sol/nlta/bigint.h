#ifndef BIGINT_H_
#define BIGINT_H_



#include <vector>
#include <iostream>
#include <string>



using namespace std;



/**
 * Define a new type name for vector<unsigned short>,
 * which is used as an array of big "digit" of big integer
 */
typedef vector<unsigned short> VDIGITS;



/**
  * @class BigInt
  * @brief This class represents and support calculation of big integers
  */
class BigInt {
    public:
        /**
         * @brief Create a zero integer
         */
        BigInt();

        /**
         * @brief Create an big integer from a string
         * @details Create a big integer from a string, return zero if the string is not a valid integer
         * @param str A string which represent a big integer
         */
        BigInt(const char* str);

        /**
          * @brief Create an big integer from a int variable
          * @param i The int variable that will be transformed to a big integer
         */
        BigInt(int i);

        BigInt(const BigInt& bi);

        ~BigInt();

        /**
          * @brief Create a big integer from a string
          * @details    Create a big integer from a string. The big integer object will represent zero
                        if the string is not valid
          * @param str A string which represent a big integer
          * @return true if the big integer is created successfully, false otherwise
         */
        bool from_string(const char *str);

        /**
         * @brief Convert the big integer its string representation
         * @param str Pointer to the string which will be the big integer representation
         */
        void to_string(char *str) const;

        /**
         * @brief Divide the current big integer by another big integer
         * @param rhs The divisor, must be non-zero
         * @param quo The resulting quotient, always equal to zero in case rhs = 0
         * @param rem The resulting remainder, always equal to zero in case rhs = 0
         * @return true if the division is performed successfully, false if rhs = 0
         */
        bool divide(const BigInt& rhs, BigInt& quo, BigInt& rem) const;

        /**
         * @brief Divide the current big integer by 2
         * @remark This function runs in linear time, faster than the general divide() function
         * @param quo The resulting quotient
         * @param rem The resulting remainder, either 0 or 1
         */
        void divideBy2(BigInt& quo, int& rem) const;



        /*******************************************************************************
         * Region In-class Operator
         * Remark:
         *      The parameter of these operator is ALWAYS on the right hand side (rhs)
         *      of the formulate
         *******************************************************************************/

        BigInt operator + (const BigInt& rhs) const;
        BigInt operator + (const int& rhs) const;

        BigInt operator - (const BigInt& rhs) const;
        BigInt operator - (const int& rhs) const;

        BigInt operator * (const BigInt& rhs) const;
        BigInt operator * (const int& rhs) const;

        /**
         * Division Operator, return ZERO when divided by zero
         * Remark:
         *      The implementation of this operator based on BigInt::divide function
         *      You should check whether you divisor is zero or not before performing this
         *      operator so that the result can be intepreted correctly
         */
        BigInt operator / (const BigInt& rhs) const;
        BigInt operator / (const int& rhs) const;

        /**
         * Remainder Operator, return ZERO when divided by zero
         * Remark:
         *      The implementation of this operator based on BigInt::divide function
         *      You should check whether you divisor is zero or not before performing this
         *      operator so that the result can be intepreted correctly
         */
        BigInt operator % (const BigInt& rhs) const;
        BigInt operator % (const int& rhs) const;

        ///Assign Operator
        BigInt& operator = (const BigInt& rhs);
        BigInt& operator = (const int& rhs);

        ///Prefix Increment/Decrement Operator
        BigInt& operator ++ ();
        BigInt& operator -- ();

        ///Postfix Increment/Decrement Operator
        BigInt operator ++ (int dummy);
        BigInt operator -- (int dummy);

        ///Unary Minus Operator
        BigInt operator - () const;

        bool operator > (const BigInt&) const;
        bool operator > (const int&) const;

        bool operator >= (const BigInt&) const;
        bool operator >= (const int&) const;

        bool operator < (const BigInt&) const;
        bool operator < (const int&) const;

        bool operator <= (const BigInt&) const;
        bool operator <= (const int&) const;

        bool operator == (const BigInt&) const;
        bool operator == (const int&) const;

        bool operator != (const BigInt&) const;
        bool operator != (const int&) const;
        /************************************************************
         * EndRegion In-class Operator
         ***********************************************************/



    private:
        /**
         * Explaination:
                A "digit" of a big integer is not only a single digit, but rather a group of digit
                e.g. 12345678 = 12 * 100^2 + 345 * 100^1 + 678 * 100^0
         */

        ///The number of single digit grouped together into a big "digit"
        const unsigned short UNIT_WIDTH = 4;

        ///The base of the big integer, equal to 10^UNIT_WIDTH
        const unsigned short UNIT = 10000;

        /**
         * The number of digit of big integer (i.e. Size of abs_value[]) below which
         * a classical multiplication will be used instead of Karatsuba algorithm
         * That is, when we calculate lhs*rhs:
         *      If lhs.abs_value.size() < KARATSUBA_THRESHOLD ||
         *          rhs.abs_value.size() < KARATSUBA_THRESHOLD
         * Then the classical multiplication algorithm will be applied
         */
        const unsigned short KARATSUBA_THRESHOLD = 1000;

        ///Represent positive sign
        const char POSITIVE = '+';

        ///Represent negative sign
        const char NEGATIVE = '-';

        /**
         * This arrays store the absolute value of the integer
         * It represent the digits of a big integer in "reversed" order
         * e.g. The number 12345678 will have abs_value = [678, 345, 12]
         */
        VDIGITS abs_value;

        ///The sign of the integer, equal to POSITIVE/NEGATIVE constant
        char sign;

        /**
         * @brief Remove heading zeros in digit array due to calculation process
         * @param b The integer which we want to remove heading zero
         */
        void trimHeadingZero(BigInt& b) const;

        /**
         * @brief Compare the current big integer object with another integer
         * @param rhs The big integer you want to compare
         * @param compareAbsolute   If it is true, the function of compare the absolute value
         *                          of both integers
         * @return  -1 if current integer smaller than rhs
         *           0 if current integer equal to rhs
         *           1 if current integer greater than rhs
         */
        int compare(const BigInt& rhs, bool compareAbsolute = false) const;

        /**
         * @brief Get the subtraction of two absolute value of 2 big integers
         * @details This function calculate |lhs| - |rhs| and store the result
         *          into res
         * @remark  This is a helper function for operator - and it is assumed
                    that |lhs| >= |rhs|
         * @param lhs The minuend
         * @param rhs The subtrahend
         */
        void subtractAbsPositive(const BigInt& lhs, const BigInt& rhs, BigInt& res) const;

        /**
         * @brief Multiple 2 big integer using Karatsuba Algorithm
         * @remark  This is a helper function for operator *
                    Note that this function only calculate the absolute value of
                    the final product. The sign of the result is considered
                    in the implementation of * operator
         * @param lhs,rhs 2 number we want to multiply
         */
        BigInt karatsubaMultiply(const BigInt& lhs, const BigInt& rhs) const;

        /**
         * @brief Extract a non-heading zero digit sub-array from a digit array
         * @param d The digit array we want to extract
         * @param first The starting position of the extraction
         * @param last The ending position of the extraction
         */
        VDIGITS DigitsFromRange(const VDIGITS& d, int first, int last) const;

        /**
         * @brief Calculate UNIT to the power of p
         * @param p The non-negative power
         * @return A big integer that represents UNIT^p
         */
        BigInt powUNIT(int p) const;
};



/**********************************************************************
 * Region Global operator
 * Description:
 *       This region includes the operators involving big integer which
 *       cannot be implemented as in-class members
 **********************************************************************/
BigInt operator + (const int& lhs, const BigInt& rhs);
BigInt operator - (const int& lhs, const BigInt& rhs);
BigInt operator * (const int& lhs, const BigInt& rhs);
BigInt operator / (const int& lhs, const BigInt& rhs);
BigInt operator % (const int& lhs, const BigInt& rhs);

bool operator < (const int& lhs, const BigInt& rhs);
bool operator <= (const int& lhs, const BigInt& rhs);
bool operator > (const int& lhs, const BigInt& rhs);
bool operator >= (const int& lhs, const BigInt& rhs);
bool operator == (const int& lhs, const BigInt& rhs);
bool operator != (const int& lhs, const BigInt& rhs);

///Right bit-shifting Operator
BigInt operator >> (const BigInt& lhs, const BigInt& rhs);
BigInt operator >> (const BigInt& lhs, const int& rhs);

///Left bit-shifting Operator
BigInt operator << (const BigInt& lhs, const BigInt& rhs);
BigInt operator << (const BigInt& lhs, const int& rhs);

///Input-stream Operator
istream& operator >> (istream& in, BigInt& bi);

///Output-stream Operator
ostream& operator << (ostream& out, const BigInt& bi);

/**********************************************************************
 * EndRegion Global operator
 **********************************************************************/



/**********************************************************************
 * Region Global Helper Function
 * Description:
 *      This region includes functions that support BigInt class and
 *      its related operators
 **********************************************************************/
/**
 * @brief Calculate 2 to the power of p
 * @param p The power which 2 will be raised, must be non-negative integer
 * @return  The expect final result if p is a non-negative integer,
 *          zero if p is an invalid negative integer
 * @remark  This function support bit-shifting operator of BigInt
 *          b >> n = b / 2^n
 *          b << n = b * 2^n
 */
BigInt pow2(BigInt p);

/**********************************************************************
 * EndRegion Global operator
 **********************************************************************/

#endif /* BIGINT_H_ */
