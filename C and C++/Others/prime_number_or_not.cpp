#include<iostream>

using namespace std;

int prime_or_not(int a)
{
	if(a==2 || a==3 )return 1;
	if(a%2==0 || a%3==0 )return 0;
	
	for(int i=5;i*i <= a; i+=2)
	{
		if(a%i==0)
		return 0;
	}
	
	return 1;
}

int main()
{
	int a=21;
	cout<<prime_or_not(a);
	return 0;
}
