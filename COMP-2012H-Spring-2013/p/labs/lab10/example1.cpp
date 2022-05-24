// example.cpp
#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
class Array 
{
	private:
		enum { size = 100};
	    T A[size];
	public:
        T& operator[](int index);
};

template<class T>
T& Array<T>::operator[](int index) 
{
    assert(index >= 0 && index < size);   
    return A[index];
}


int main() 
{
    Array<int> ia;
    Array<float> fa;

    for(int i = 0; i < 20; i++) 
	{
	   ia[i] = i * i;
	   fa[i] = float(i) * 1.414;
	}

    for(int j = 0; j < 20; j++)
	   cout << j << ": " << ia[j] << ", " << fa[j] << endl;

    return 0;
}