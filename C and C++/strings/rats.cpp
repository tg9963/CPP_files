#include<iostream>

using namespace std;

int find_no(char arr[][350],int n)
{
	int row[]={0,0,-1,1};
	int col[]={-1,1,0,0};
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int p=0;p<4;p++)
			{
				for(int q=0;q<4;q++)
				{
					if(is_safe(i+row[i]))
				}
			}
		}
	}
}


int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		char arr[n][350];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>arr[i][j];
			}
		}
		cout<<find_no(arr,n);
	}
}
