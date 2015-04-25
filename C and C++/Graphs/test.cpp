#include<stdio.h>

int main()
{
	int j=2;
	unsigned int i;
	for(i=1<<31;i>=0;i=i/2)
	(i&j)?printf("1"):printf("0");
}
