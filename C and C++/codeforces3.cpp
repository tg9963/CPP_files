#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int ar[m];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	int max_sum=-10000;
	int over[n];
	int count=0;
	for(int j=0;j<n-m+1;j++)
	{
		int sum=0;
		for(int k=j;k<j+m-1;k++)
		{
			for(int p=0;p<2;p++)
			{
				sum+=ar[k+p];
			}
			over[count++]=sum;
		}
	}
	int sum=0;
	for(int i=0;i<count;i++)
	{
		for(int j=0;j<m;j++)
		{
			sum+=over[j];
		}
		if(sum>max_sum)
		{
			max_sum=sum;
		}
	}
	cout<<max_sum;
	return 0;
}
