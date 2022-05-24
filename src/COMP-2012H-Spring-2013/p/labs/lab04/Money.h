#include <iostream>
using namespace std;

class MoneyType
{
public:
    void Initialize(long,long);
    long DollarsAre();
    long CentsAre();
    MoneyType Add(const MoneyType &);
    void Normalize();
private:
    long dollars;
    long cents;
};