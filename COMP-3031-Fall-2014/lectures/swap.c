#include <stdio.h>

void swap(int *px, int *py)
{
  printf("entering swap: *px=%d, *py=%d \n", *px, *py);
  int z; 
  z=*px; *px=*py; *py=z;
  printf("exiting swap: *px=%d, *py=%d \n", *px, *py);
}

int main(int argc, char **argv) {
  int a=1, b=2;
  printf("before swap: a=%d, b=%d\n",a,b);
  swap(&a,&b);
  printf("after swap, a=%d, b=%d\n",a,b);
}
