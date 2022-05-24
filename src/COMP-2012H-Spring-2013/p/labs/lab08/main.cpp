#include "ExtMoney.h"
#include <iostream>
using namespace std;

int main()
{
	MoneyType money;
	cout << "initilaized by default constructors" << endl;
	money.Print();
	cout << endl;
	ExtMoneyType extMoney1;
	extMoney1.Print();
	cout << endl;
	cout << "initialized by parameterized constructors" << endl;
	ExtMoneyType extMoney2(3000,88,"forints");
	extMoney2.Print();
	cout << endl;
	cout << "initialized at run time" << endl;
	extMoney1.Initialize(5000,99,"pounds");
	extMoney1.Print();
	cout << endl;
	return 0;
}