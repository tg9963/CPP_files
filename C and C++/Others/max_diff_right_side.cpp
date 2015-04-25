#include<iostream>
using namespace std;

int find_max_diff(int arr[],int n)
{
	int diff=arr[1]-arr[0];
	int curr_sum=diff;
	int max_diff=diff;
	for(int i=1;i<n-1;i++)
	{
		diff=arr[i+1]-arr[i];
		if(curr_sum<0)
		{
			curr_sum=diff;
		}
		else
		{
			curr_sum +=diff;
		}
		
		if(curr_sum > max_sum )
		{
			max_sum=curr_sum;
		}
	}
	return max_sum;
}

int main()
{
	int arr[]={80,2,6,3,100};
	int n=5;
	cout<<find_max_diff(arr,n);
}
