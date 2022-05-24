#include "Money.h"
#include <iostream>
using namespace std;

void MoneyType::Initialize(long newDollars,long newCents)
// Post: dollars is set to newDollars; cents is set to newCents.
{
    dollars = newDollars;
    cents   = newCents;
}

long MoneyType::DollarsAre() const
// Post: Class member dollars is returned.
{
    return dollars;
}

long MoneyType::CentsAre() const
// Post: Class member Cents is returned.
{
    return cents;
}

void MoneyType::Print() const
// Post: print the member dollars and cents.
{
	cout << dollars << " " << cents << " ";
}

MoneyType MoneyType::Add(const MoneyType &value) const
// Pre: Both operands have been initialized.
// Post: value + self is returned.
{
    MoneyType result;
    result.cents   = cents+value.cents;
    result.dollars = dollars+value.dollars;
    return result;
}

MoneyType::MoneyType(long newDollars, long newCents) 
//constructor
{
	dollars = newDollars;
	cents = newCents;
}

MoneyType::MoneyType()                 
//default constructor  
{
	dollars = 0;
	cents = 0;
}
