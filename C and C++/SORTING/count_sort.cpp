#include<iostream>

using namespace std;


void count_sort(int arr[],int n,int k)
{
	int op[n],temp[k];
	
	for(int i=0;i<k;i++)
	{
		temp[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		temp[arr[i]]+=1;
	}
	for(int i=1;i<k;i++)
	{
		temp[i]+=temp[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		op[temp[arr[i]]]=arr[i];
		temp[arr[i]]-=1;
	} 
	for(int i=0;i<n;i++)
	arr[i]=op[i];
}

int main()
{
	int arr[]={0,1,4,5,2,3};
	int n=6;
	int k=6;
	count_sort(arr,n,k);
	for(int i=0;i<n;i++)cout<<arr[i]<<"  ";
	return 0;
}
