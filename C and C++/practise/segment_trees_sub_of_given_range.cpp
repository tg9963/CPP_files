#include<iostream>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;
int constructs(vector<int> a,int start,int end,int *s,int index)
{
	if(start==end)
	{
		s[index]=a[start];
		return a[start];
	}
	int mid=start+(end-start)/2;
	s[index]=constructs(a,start,mid,s,2*index+1)-constructs(a,mid+1,end,s,2*index+2);
	return s[index];	
}
int* construct_tree(vector<int> a)
{
	int n=a.size();
	int h=(int)(ceil(log2(n)));
	int size=2*(int)pow(2,h)-1;
	int *s=new int[size];
	constructs(a,0,n-1,s,0);
	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<"  ";
	}
	return s;
}
int sub_of_range(int *s,int qs,int qe,int start,int end,int index)
{
	if(qs<=start && qe>=end)return s[index];
	if(end<qe || start >qs )return 0;
	int mid=start+(end-start)/2;
	return (sub_of_range(s,qs,qe,start,mid,2*index+1)-sub_of_range(s,qs,qe,mid+1,end,2*index+2));
}
int querry(int* s,int qs,int qe,int start,int end,int index)
{
	if(qs<start || qs>qe || qe>end)return 0;
	return sub_of_range(s,qs,qe,start,end,index);
}
int main()
{
	vector<int> a;
	int n;
	cout<<"enter n: ";
	cin>>n;
	cout<<"\nenter the values ";
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	int *s=construct_tree(a);
	cout<<"enter qs and qe";
	int qs,qe;
	cin>>qs;
	cin>>qe;
	cout<<querry(s,qs,qe,0,n-1,0);	
}
