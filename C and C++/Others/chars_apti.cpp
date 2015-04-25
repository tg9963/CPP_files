#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main()
{
	char *p,*q;
	p=(char *)malloc(25);
	q=(char *)malloc(25);
	strcpy(p,"hello");
	strcpy(q,"Hel");
	strcat(p,q);
	int x=10;
	if(x && !(x & (x-1)) ==1)
	{
		cout<<x;
	}
	else
	{
		cout<<"hey";
	}
	//cout<<p;
}
