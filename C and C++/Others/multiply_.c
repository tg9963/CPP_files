#include <stdio.h>
 
int multiplyWith3Point5(int x)
{
	//printf("%d ",(x<<2));
//	/	printf("%d ",x>>1);
  return ((x<<3) - x)>>1;
}    
 
/* Driver program to test above functions*/
int main()
{
  int x = 15; 
  printf("%d", multiplyWith3Point5(x));
  return 0;
}
