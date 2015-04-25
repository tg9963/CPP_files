#include<iostream>
using namespace std;

int main()
{
	
	int a[]={1,9,3,4};
	int *p=a;
	int b=*p++;
	cout<<*p;
	return 0;
}
