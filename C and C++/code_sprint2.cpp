#include<iostream>

using namespace std;

int find_set(int parent[],int src)
{
	if(parent[src]==-1)return src;
	else return find_set(parent,parent[src]);
}
void unions(int parent[],int x,int y)
{
	int x_set=find_set(parent,x);
	int y_set=find_set(parent,y);
	parent[x_set]=y_set;
}


int main()
{
	int n,m;
	cin>>n>>m;
	int arr[n],parent[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		parent[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		int j=find_set(parent,i);
		int p=find_set(parent,i+1);
		
	}
	return 0;
}
