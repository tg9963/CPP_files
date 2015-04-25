#include<iostream>
#include<stdlib.h>

using namespace std;

void bubble_sort(int arr[],int n)
{
	int temp;
	
	for(int j=n-1;j>=0;j--)
	{
		for(int i=0;i<j;i++)
		{
			if(arr[i]>arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
	}
}

int main()
{
	int arr[]={1,9,5,3,2,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,n);
	for(int i=0;i<n;i++)cout<<arr[i]<<"  ";
	return 0;	
}
