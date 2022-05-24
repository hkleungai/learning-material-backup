//This is the header file for class ExtMoneyType
#include "Money.h"
#include <string>
using namespace std;

class ExtMoneyType: public MoneyType
{
public:
	void Print() const;
	string CurrencyIs() const;
	void Initialize(long, long, string);
	ExtMoneyType();
	ExtMoneyType(long, long, const string);
private:
	string currency;
};
