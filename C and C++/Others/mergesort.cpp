#include<iostream>
using namespace std;
void merge(int array[],int temp[],int low,int mid,int high)
{ 
	int left_end=mid-1;
	int right_end=high;
	int left=low,right=mid;
	while(left<=left_end && right<=right_end)
	{
		if(array[left]<)
	}
}
void mergesort(int array[],int temp[],int low,int high)
{
	if(high>low)
	{
		int mid=(low+high)/2;
		mergesort(array,temp,low,mid);
		mergesort(array,temp,mid+1,high);
		merge(array,temp,low,mid,high);
	}
}
int main()
{
	int array[7],temp[7];
	for(int i=0;i<7;i++)
	cin>>array[i];
	mergesort(array,temp,0,6);
	for(int i=0;i<7;i++)
	cout<<temp[i]<<"->";
	return 0;
}
