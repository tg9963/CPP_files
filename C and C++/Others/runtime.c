#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p;
	int a;
	printf("\n enter ");
	scanf("%d",&a);
	p=(int *)malloc(a);
	printf("%u",&p);
	return 0;
}
