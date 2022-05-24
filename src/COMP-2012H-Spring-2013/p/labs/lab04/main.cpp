#include "Money.h"

int main()
{
    MoneyType money1;
    MoneyType money2;
    MoneyType money3;
    money1.Initialize(10,59);
    money2.Initialize(20,70);

    cout << "$" << money3.DollarsAre() << "." << money3.CentsAre() << endl;
    money3 = money1.Add(money2);
    money3.Normalize();
    cout << "$" << money3.DollarsAre() << "." << money3.CentsAre() << endl;
    return 0;
}