#include<iostream>
#include<stdlib.h>
using namespace std;

int find_partition(int arr[],int low,int high)
{
	int pivoit=arr[low];
	int temp,left=low,right=high;
	while(left<right)
	{
		while(arr[left]<=pivoit)
		{
			left++;
		}
		while(arr[right]>pivoit)
		{
			right--;
		}
		if(left<right)
		{
			temp=arr[right];
			arr[right]=arr[left];
			arr[left]=temp;
		}
	}
	arr[low]=arr[right];
	arr[right]=pivoit;
	return right;
}

void quick_sort(int arr[],int low,int high)
{
	if(high>low)
	{
		int part_index=find_partition(arr,low,high);
		quick_sort(arr,low,part_index-1);
		quick_sort(arr,part_index+1,high);
	}
}

int main()
{
	int arr[]={1,5,4,2,6,9};
	int n=sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr,0,n-1);
 	for(int i=0;i<n;i++)cout<<arr[i]<<"  ";
	return 0;
}
