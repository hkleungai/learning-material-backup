#include <stdio.h>

void muchAdo(int x, int y)
{
  printf("entering muchAdo: x=%d, y=%d \n", x, y);
  int z; 
  z=x; x=y; y=z;
  printf("exiting muchAdo: x=%d, y=%d \n", x, y);
}

int main(int argc, char **argv) {
  int a=1, b=2;
  printf("before muchAdo: a=%d, b=%d\n",a,b);
  muchAdo(a,b);
  printf("after muchAdo, a=%d, b=%d\n",a,b);
}
