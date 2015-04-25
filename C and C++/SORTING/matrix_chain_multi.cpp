#include<iostream>
#include<stdlib.h>

using namespace std;

void MCM(int p[],int n)
{
	int c[n][n],s[n][n];
	for(int i=1;i<n;i++)
	{
		c[i][i]=0;
	}
	for(int l=2;l<n;l++)
	{
		for(int i=1;i<n-l;i++)
		{
			int j=i+l;
			for(int k=i;k<j-1;k++)
			{
				int q=c[i][k]+c[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<c[i][j])
				{
					c[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	
	cout<<c[n][n];
	/*
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
}

int main()
{
	int p[]={1,2,3,4,5};
	int n=4;
	MCM(p,n);
	return 0;
}
