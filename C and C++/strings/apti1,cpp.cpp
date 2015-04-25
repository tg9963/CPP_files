#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{
	char *p,*q;
	p=(char *)malloc(25);
	q=(char *)malloc(25);
	strcpy(p,"amazon");
	strcpy(q,"Hyd");
	strcat(p,q);
	printf("%s",p);
	return 0;
}
