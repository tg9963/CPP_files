#include <stdio.h>
int fun(int i)
{
	int a=5;
	int b=i;
	b=a>b?return(a):return(b);
}
int main()
{
int i=5;
printf("%d",fun(i));
   return 0;
}
