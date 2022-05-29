// DO NOT MODIFY THIS FILE

#include "Money.h"

int main(int argc, char *argv[])
{
    MoneyType money1 = MoneyType(10,59);
    MoneyType money2 = MoneyType(20,70);
    MoneyType money3;

    cout << "money3 initialized:" << endl;
    cout << "money3: $" << money3.DollarsAre() << "." << money3.CentsAre() << endl;
    money3 = money1.Add(money2);
    cout << "Before normalization:" << endl;
    cout << "money3: $" << money3.DollarsAre() << "." << money3.CentsAre() << endl;
    money3.Normalize();
    cout << "After normalization:" << endl;
    cout << "money3: $" << money3.DollarsAre() << "." << money3.CentsAre() << endl;
    return 0;
}