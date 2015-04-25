#include<iostream>
using namespace std;

void selection_sort(int arr[],int n)
{
	int min,temp;
	for(int i=0;i<n;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			min=j;
		}
		if(min!=i)
		{
			temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
		}
	}
}

int main()
{
	int arr[]={1,2,8,9,3};
	int n=5;
	selection_sort(arr,n);
	for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	return 0;
}
