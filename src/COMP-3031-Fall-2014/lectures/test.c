#include <stdio.h>
int x=1;
void test();

int main(int argc, char **argv) {
int x=2;
  {
    int x =3; 
    printf("in x=3 scope, before the first test: x = %d\n",x);  
    test();
    printf("in x=3 scope, after the first test: x = %d\n",x);  
  }
  printf("in x=2 scope, before the second test: x = %d\n", x);
  test();  
  printf("in x=2 scope, after the second test: x = %d\n",x); 
}

void test() {
  printf("in test: x = %d\n",x);
}
