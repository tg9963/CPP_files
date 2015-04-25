#include<iostream>

using namespace std;

int make_change(int change[],int num_denom,int n);
int minimum(int a,int b)
{
	return (a<b?a:b);
}

int make_change(int change[],int num_denom,int n)
{
	int table[n+1];
	for(int i=0;i<=n;i++)
	{
		table[i]=0;
	}
	table[0]=1;
	for(int i=0;i<num_denom;i++)
	{
		for(int j=change[i];j<=n;j++)
		{
			table[j] +=table[j-change[i]];
		}
	}
	return table[n];
}


int main()
{
	int n;
	cin>>n;
	int change[]={1,2,5};
	int num_denom=3;
	cout<<make_change(change,num_denom,n);
	return 0;
}
