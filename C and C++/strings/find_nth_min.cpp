#include<iostream>
#include<limits>

using namespace std;

int find_mth_small(int arr[],int n,int m)
{
	int min[n];
	for(int i=0;i<n;i++)
	{
		min[i]=0;
	}
	int count=1;
for(int j=0;j<n;j++)
{
	int min_ele=INT_MAX;
	int min_ele_index=-1;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]<min_ele && min[i]==0)
		{
				min_ele=arr[i];
				min_ele_index=i;
		}
	}
		min[min_ele_index]=count++;
		if(count==m)
		{
			for(int i=0;i<n;i++)
			cout<<min[i]<<" ";
			cout<<endl;
			return arr[min_ele_index];
		}
}
	return 0;
}



int main()
{
	int arr[]={15,4,3,8,6,5,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int m;
	cin>>m;
	cout<<find_mth_small(arr,n,m);
}
