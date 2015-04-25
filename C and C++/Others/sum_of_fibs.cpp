#include<iostream>
using namespace std;

int find_all_fibs(int arr[],int *count,int n)
{
	//int arr[1000];
	arr[0]=1;
	arr[1]=1;
	*count=1;
	for(int i=1;;i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
		if(arr[i]>n)
		{
			arr[i]=0;
			return 0;
		}
		(*count)++;
	}
	return 0;
}

int print_numbers(int arr[],int count,int pos,int sum)
{
	if(pos>count)
	{
		return 0;
	}
	if(arr[pos]==sum)
	{
		cout<<arr[pos]<<" ";
		return 1;
	}
	int a=print_numbers(arr,count,pos+2,sum-arr[pos]);
	if(a==1)
	{
		cout<<arr[pos]<<" ";
	}
	int b=print_numbers(arr,count,pos+1,sum);
	return a||b;
}

int main()
{
	int n;
	cin>>n;
	int arr[1000];
	for(int i=0;i<1000;i++)arr[i]=0;
	int count;
	find_all_fibs(arr,&count,n);
	if(print_numbers(arr,count,0,n))
	{
		//cout<<"possible";
	}
	else
	{
		//cout<<" Not possible ";
	}
	return 0;
}
