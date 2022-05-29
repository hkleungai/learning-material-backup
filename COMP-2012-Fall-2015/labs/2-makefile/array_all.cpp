#include <iostream>
#include <stdlib.h>
using namespace std;

const int SIZE = 20;

struct Array
{
  int items[20];
  int size;
};

void ArrayInit(Array& a)
{
  a.size=0;
}

int ArraySum(const Array a)
{
  int sum=0;
  for (int i=0; i<a.size; i++)
    sum+=a.items[i]; 
  return (sum);
}

void ArrayPrint(const Array a)
{ 
  for (int i=0; i<a.size; i++)
     cout << a.items[i] << " ";
  cout << endl;
}

bool ArrayInsert(Array& a, int newItem)
{
  if (a.size<SIZE)
  {
    a.items[a.size]=newItem;
    a.size++;
    return true;
  } 
  return false;
}

/* remove the first occurance of the integer number, newItem, from the array a */
bool ArrayRemove(Array& a, int newItem)
{
  int i=0;
  bool found=false;
  while ((!found)&&(i<a.size))
  {
    if (a.items[i] == newItem)
    {
      found=true; 
    }
    i++;
  }
  if (found)
  {
    for (; i<a.size; i++)
      a.items[i-1] = a.items[i];
    a.items[a.size-1] = 0;
    a.size--;
    return true;
  } 
  return false; 
}

int main(void)
{
  int num=0;
  Array arr;
  ArrayInit(arr);
  cout << "Enter the number of items: ";
  cin >> num;    
  for (int i=0; i<num; i++)
  {
     ArrayInsert(arr, rand()%100+1);
  }

  cout << "Array items: ";
  ArrayPrint(arr);

  cout << "Sum of items: " << ArraySum(arr) << endl;

  cout << "Remove the number: ";
  cin >> num;
       
  if (!ArrayRemove(arr, num))
     cout << "Item " << num << " not found" << endl;

  cout << "Array items: ";
  ArrayPrint(arr);

  return 0;
}
