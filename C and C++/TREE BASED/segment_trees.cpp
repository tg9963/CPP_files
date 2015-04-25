#include<iostream>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;
int get_sum_in_range(int *s,int qs,int qe,int start,int end,int index)
{
	if(qs<=start && qe>=end)return s[index];
	if(end<qs || start>qe )return 0;
	int mid=start+(end-start)/2;
	return (get_sum_in_range(s,qs,qe,start,mid,2*index+1)+get_sum_in_range(s,qs,qe,mid+1,end,2*index+2));
}
int get_sum(int *s,int qs,int qe,int start,int end)
{
	if(qs>qe)return 0;
	if(qs<start || qe>end)return 0;
	return get_sum_in_range(s,qs,qe,start,end,0);
}
int construct(vector<int> a,int start,int end,int* s,int pnt)
{
	if(start==end)
	{
		s[pnt]=a[start];
		return a[start];
	}
	else
	{
		int mid=start+(end-start)/2;
		s[pnt]=construct(a,start,mid,s,2*pnt+1)+construct(a,mid+1,end,s,2*pnt+2);
		return s[pnt];
	}
} 

void print_tree(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"->";
	}
	cout<<endl;
}
int* construct_tree(vector<int> a)
{
	int n;
	n=a.size();
	int h=(int)(ceil(log2(n)));
	int size=2*(int)pow(2,h)-1;
	//cout<<"\nsize"<<size<<endl;
	int *s=new int[size];
	construct(a,0,n-1,s,0);
	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<"index "<<i<<"\n";
	}
	return s;
}
int main()
{
	vector<int> a;
	cout<<"enter n";
	int n;
	cin>>n;
	int temp;
	cout<<"enter values";
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	int *s=construct_tree(a);
	print_tree(s,n);
	cout<<"\n enter qs and qe";
	int qs,qe;
	cin>>qs;
	cin>>qe;
	cout<<get_sum(s,qs,qe,0,n-1);
	return 0;
}
