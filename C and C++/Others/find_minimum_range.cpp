#include<iostream>
#include<stdlib.h>
#include<limits>
#include<algorithm>
#include<stack>
using namespace std;

struct node
{
	int data;
	int i;
};

void find_minimum_range(struct node arr[],int n,int k)
{
	int i=0;
	int range;
	int min_range=INT_MAX;
	int op[3];
	for(int i=0;i<n;i++)
	{
		
	}
}

int comp(const void* a,const void *b)
{
	return ( (*(struct node*)a).data - (*(struct node*)b).data);
}

int main()
{
	struct node arr1[]={ {-1,1}, {4,-1},{7,1} };
	struct node arr2[]={ {5,2},{9,2}, {15,2}, {23,2}};
	struct node arr3[]={ {8,3},{24,3},{29,3},{25,3},{31,3}};
	int k=3;
	int n1=sizeof(arr1)/sizeof(arr1[0]);
	int n2=sizeof(arr2)/sizeof(arr2[0]);
	int n3=sizeof(arr3)/sizeof(arr3[0]);
	int n=n1+n2+n3;
	struct node arr[n];
	int count=0;
	for(int i=0;i<n1;i++)
	{
		arr[count++]=arr1[i];
	}
	for(int i=0;i<n2;i++)
	{
		arr[count++]=arr2[i];
	}
	for(int i=0;i<n3;i++)
	{
		arr[count++]=arr3[i];
	}
	qsort(arr,n,sizeof(arr[0]),comp);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i].data<<" ";
	}
	find_minimum_range(arr,n,k);
}
