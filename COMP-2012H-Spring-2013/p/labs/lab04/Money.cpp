#include "Money.h"

void MoneyType::Initialize(long newDollars,long newCents)
// Post: dollars is set to newDollars; cents is set to newCents.
{
    dollars = newDollars;
    cents   = newCents;
}

long MoneyType::DollarsAre()
// Post: Class member dollars is returned.
{
    return dollars;
}

long MoneyType::CentsAre()
// Post: Class member Cents is returned.
{
    return cents;
}

MoneyType MoneyType::Add(const MoneyType &value)
// Pre: Both operands have been initialized.
// Post: value + self is returned.
{
    MoneyType result;
    result.cents   = cents+value.cents;
    result.dollars = dollars+value.dollars;
    return result;
}

void MoneyType::Normalize()
{
    // To implement this member function 
    // To normalize the cents value the cents to between 0 and 99 and adjusts the dollar amount accordingly.
}
