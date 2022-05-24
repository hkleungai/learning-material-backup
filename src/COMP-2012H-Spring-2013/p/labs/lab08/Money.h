//Money.h is the header file for class MoneyType
//with constructors
class MoneyType
{
public:
	void Initialize(long, long);
	long DollarsAre() const;
	long CentsAre() const;
	void Print() const;
	MoneyType Add(const MoneyType &) const;  
	MoneyType(long, long);           //constructor
	MoneyType();                     //constructor  
private:
	long dollars;
	long cents;
};
