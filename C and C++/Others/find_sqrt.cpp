#include<iostream>

using namespace std;

int find_sqrt1(int n)
{
	float x=n;
	float y=1;
	float e=0.00001;
	while(x-y > e)
	{
		x=(x+y)/2;
		y=n/x;
	}
	return x;
}
int find_sqrt2(int n)
{
	int flag=1;
	int odd=1;
	int count=0;
	while(flag)
	{
		count++;
		if(n-odd == 0)
		{
			flag=0;
		}
		else
		{
			n=n-odd;
			odd +=2;
		}
	}
	return count;
}
int main()
{
	int n=256;
	cout<<find_sqrt1(n);
	cout<<endl;
	cout<<find_sqrt2(n); // only for perfect squares
	return 0;
}
