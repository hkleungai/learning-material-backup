/*
 * bigint.h
 */

#ifndef BIGINT_H_
#define BIGINT_H_

#include <vector>

using namespace std;

class BigInt {

public:
	BigInt();
	BigInt(const char *str);
	BigInt(int i);
	BigInt(const BigInt &bi);
	~BigInt();

	/* #### You need to implement from_string(const char*) and to_string(char*) methods. #### */
	/**
	 * Method: void from_string(const char *str)
	 * Description:
	 * 		from_string method will read the number from str.
	 * 		If str is valid, it will be parsed and stored into sign and storage, and then return true. Otherwise, false will be returned.
	 */
	bool from_string(const char *str);

	/**
	 * Method: void to_string(const char *str)
	 * Description:
	 * 		to_string method will output the current number to str.
	 */
	void to_string(char *str);

	/* #### Please add your overloading methods below. #### */

private:
	vector<unsigned short> abs_value;
	char sign;

};

#endif /* BIGINT_H_ */
