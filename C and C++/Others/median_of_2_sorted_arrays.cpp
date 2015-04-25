#include<iostream>
using namespace std;


//O(n) use merge sort method
void find_median1(int arr1[],int arr2[],int n)
{
	int i=0,j=0;
	int m1=-1,m2=-1;
	for(int count=0;count<=n;count++)
	{
		if(i==n)
		{
			m1=m2;
			m2=arr2[i];
		}
		else if(j==n)
		{
			m1=m2;
			m2=arr1[i];
		}
		if(arr1[i]<arr2[j])
		{
			m1=m2;
			m2=arr1[i];
			i++;
		}
		else
		{
			m1=m2;
			m2=arr2[j];
			j++;
		}
	}
	cout<<"median: "<<(m1+m2)/2;
}

/*
void find_median2(int arr1[],int arr2[],int low,int high)
{
	int n=high-low;
	if(n==2)
	{
		//cout<<arr1[1]<<" "<<arr2[1]<<endl;
		int median=(max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;
		cout<<"median: "<<median;
		return ;
	}
	int mid=low+(high - low )/2;
	int m1=arr1[mid];
	int m2=arr2[mid];
	if(m1==m2)
	{
		cout<<"median: "<<m1;
		return;
	}
	else if(m1 > m2 )
	{
		if(n%2==0)
	}
	else
	{
		
	}
}
*/
int main()
{
	int arr1[]={1,2,3,4,5};
	int arr2[]={3,4,5,6,7};
	int n=5;
	find_median1(arr1,arr2,n);
	cout<<endl;
	find_median2(arr1,arr2,0,n-1);
	return 0;
}
