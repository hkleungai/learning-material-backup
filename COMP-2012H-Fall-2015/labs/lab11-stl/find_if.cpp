#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int f(int x) { return - x * x + 40 * x + 22; }

template<typename T>
void my_initialization(T& x)
{
	const int N = 50;
	for (int j = 0; j < N; j++)
		x.push_back(f(j));
}

/*
bool greater_than_350(int value)
{
	return value > 350;
}
*/

class Greater_Than
{
public:
	Greater_Than(int a) : limit(a) { }
	bool operator()(int value) { return value > limit; }
private:
	int limit;
};

int main()
{
	vector<int> x;

	my_initialization(x);
	vector<int>::iterator p = find_if(x.begin(), x.end(), Greater_Than(350));

	if (p != x.end())
	{
		cout << "Found element: " << *p << endl;
	}

	return 0;
}

