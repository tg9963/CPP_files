#include<iostream>

using namespace std;

int main()
{
 		int n;
		int m,k;
		cin>>n>>m>>k;
		int ar2[m];
		for(int i=0;i<=m;i++)
		{
			cin>>ar2[i];
		}
		int act=ar2[m];
		int total=0;
		for(int i=0;i<=m;i++)
		{
			int count=0;
			for(int j=0;j<n;j++)
			{
				if((act>>j & 1) != (ar2[i]>>j & 1 ))
				{
					count++;
				}
				if(count>k)
				{
					break;
				}
			}
			if(count<k)
			{
				total++;
			}
		}
		cout<<total<<endl;
}
