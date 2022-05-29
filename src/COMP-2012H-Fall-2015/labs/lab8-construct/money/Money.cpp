#include "Money.h"

// Post: dollars is set to newDollars; cents is set to newCents.
void MoneyType::Initialize(long newDollars,long newCents)
{
    // Modify this function to be another constructor.
    
    dollars = newDollars;
    cents = newCents;
}

// Post: Class member dollars is returned.
long MoneyType::DollarsAre()
{
    // DO NOT MODIFY THIS FUNCTION
    
    return dollars;
}

// Post: Class member cents is returned.
long MoneyType::CentsAre()
{
    // DO NOT MODIFY THIS FUNCTION
    
    return cents;
}

// Pre: Both objects have been initialized.
// Post: value + self is returned.
MoneyType MoneyType::Add(const MoneyType& value)
{
    // DO NOT MODIFY THIS FUNCTION
    
    MoneyType result;
    result.cents = cents+value.cents;
    result.dollars = dollars+value.dollars;
    return result;
}

void MoneyType::Normalize()
{
    // Implement this member function
    // Normalize the cents amount to be between 0 and 99 and adjust the dollar amount accordingly.
    
}
