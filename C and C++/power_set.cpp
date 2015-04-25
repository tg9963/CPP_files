#include<iostream>

using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		long n;
		cin>>n;
		n=n+1;
		long res=1;
		for(int i=1;i<=n;i++)
		{
			res*=i;
		}
		cout<<res<<endl;
	}
}
