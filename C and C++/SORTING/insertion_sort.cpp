#include<iostream>
using namespace std;

void insertion_sort(int arr[],int n)
{
	int temp,j;
 	for(int i=2;i<n;i++)
 	{
 		temp=arr[i];
 		j=i;
 		while(arr[j-1]>temp && j>=1 )
 		{
 			arr[j]=arr[j-1];
 			j--;
 		}
 		arr[j]=temp;
 	}
}

int main()
{
	int arr[]={1,2,8,9,3};
	int n=5;
	insertion_sort(arr,n);
	for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	return 0;
}
