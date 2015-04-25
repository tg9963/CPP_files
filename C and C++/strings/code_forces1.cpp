#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	char arr[n];
	int prev=-1,res=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		int curr=arr[i]-48;
		if(prev==-1)
		{
			prev=curr;
			continue;
		}
		else
		{
			if(prev+curr>0)
			{
				carry=1;
			}
		}
	}
	
	
}
