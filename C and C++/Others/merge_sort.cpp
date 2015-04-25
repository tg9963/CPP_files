#include<iostream>
#include<limits>
#include<stdlib.h>
using namespace std;

void merge_(int arr[],int low,int mid,int high)
{
	int *left,*right;
	int l_size=mid-low+1;
	int r_size=high-mid;
	left=(int *)malloc(l_size * sizeof(int));
	right=(int *)malloc(r_size * sizeof(int));
	int l_count=0,r_count=0;
	
	for(int i=low;i<=mid;i++)
	{
		left[l_count]=arr[i];
		l_count++; 
	}
	left[l_count]=INT_MAX;
	for(int i=mid+1;i<=high;i++)
	{
		right[r_count]=arr[i];
		r_count++;
	}
	
	right[r_count]=INT_MAX;
	l_count=0,r_count=0;
	for(int k=low;k<=high;)
	{
		if(left[l_count]<right[r_count])
		{
			arr[k]=left[l_count];
			k++;
			l_count++;
		}
		else
		{
			arr[k]=right[r_count];
			k++;
			r_count++;
		}
	}
}

void merge_sort(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid=(high+low)/2;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);
	    merge_(arr,low,mid,high);
	}
}

int main()
{
	int arr[]= {13, 2, 69, 6, 1000, 32, 75, 15, 6, 29, 531};
	int n=sizeof(arr)/sizeof(arr[0]);
	merge_sort(arr,0,n-1);
	for(int i=0;i<n;i++)cout<<arr[i]<<"  ";
	return 0;
}
