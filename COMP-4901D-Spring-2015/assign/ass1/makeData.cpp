#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
  int N1 = 300000;
  int N2 = 400000;

  vector<int> key1;
  vector<int> key2;
  vector<float> value1;
  vector<float> value2;

  for(int i = 0; i < N1; ++i)
  {
	key1.push_back(i);
	value1.push_back(i * 1.0);
  }

  for(int i = 0; i < N2; ++i)
  {
	key2.push_back(i);
	value2.push_back(i * 1.0);
  }
 
  random_shuffle(key1.begin(),key1.end());
  random_shuffle(key2.begin(),key2.end());
  random_shuffle(value1.begin(),value1.end());
  random_shuffle(value2.begin(),value2.end());
  
  freopen("in.txt","w",stdout);
  printf("%d %d\n",N1,N2);
  for(int i = 0; i < N1; ++i)
	printf("%d %f\n",key1[i],value1[i]);
  printf("\n\n");
  for(int i = 0; i < N2; ++i)
	printf("%d %f\n",key2[i],value2[i]);
  fclose(stdout);
  return 0;
}
