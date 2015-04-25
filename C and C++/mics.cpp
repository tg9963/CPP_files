#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;


int comp(const void* a,const void* b)
{
	return (((int*)a)-((int*)b));
}


int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		int ar1[n];
		int ar2[m];
		for(int i=0;i<n;i++)
		{
			cin>>ar1[i];
		}
		for(int i=0;i<m;i++)
		{
			cin>>ar2[i];
		}
		sort(ar1,ar1+n);
		sort(ar2,ar2+m);
		int i=0,j=0;
		int max_diff=-100000000;
		while(i<n)
		{
			int diff=abs(ar1[i]-ar2[i]);
			if(diff>max_diff)
			{
				max_diff=diff;
			}
			i++;
		}
		cout<<max_diff;
		
	}
}
