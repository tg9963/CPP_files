#include<iostream>
using namespace std;

int find_pos(int n)
{
	if(n==0)return 0;
	static int arr[10000];
	 arr[0]=1;
	 arr[1]=1;
	 arr[2]=1;	
	if(n>0 && n<=3)return 1;
	if(arr[n]!=0)return arr[n];
	
	if(n-3>0)
	{
	   arr[n]=(!find_pos(n-1)|| !find_pos(n-2)|| !find_pos(n-3));
	   return arr[n];
	}	
	return 0;
}


int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		if(find_pos(n))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
