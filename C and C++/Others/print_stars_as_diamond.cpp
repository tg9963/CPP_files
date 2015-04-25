#include<iostream>
using namespace std;

void print_diamond(int n)
{
	int j;
	int half=n/2;
	for(int i=0;i<n;i++)
	{
		for( j=0;j<(n-i);j++)
		{
			cout<<" ";
		}
		
		for(int k=j;k<=n;k++)
		cout<<" * ";
		
		cout<<endl;
	}
	
	for(int i=0;i<n;i++)
	{
		for( j=0;j<(i);j++)
		{
			cout<<" ";
		}
		
		for(int k=j;k<=n;k++)
		cout<<" * ";
		
		cout<<endl;
	}
	 
		cout<<endl;
}




int main()
{
	int n;
	cin>>n;
	print_diamond(n);
	return 0;
}
