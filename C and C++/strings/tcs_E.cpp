#include<iostream>
using namespace std;

int find(int parent[], int i)
{
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[yset] = xset;
}

void update(int parent[],int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=find(parent,i);
	}
}


void fun(int parent[],int n)
{
	char ch;
		cin>>ch;
		if(ch=='C')
		{
			int x;
			int y;
			cin>>x>>y;
		x = find(parent,x-1);
         y = find(parent,y-1);

        if (x != y)
        {
        Union(parent,x,y);	
        update(parent,n);
		}
		fun(parent,n);
		}
		else if(ch=='Q')
		{
			int x,y;
			cin>>x>>y;
			int count=0;
			int count_arr[n];
			for(int i=0;i<n;i++)
			{
				count_arr[i]=0;
				cout<<parent[i]<<"  ";
			}
			cout<<endl;
			for(int i=0;i<n;i++)
			{
				count_arr[parent[i]]+=1;
			}
			for(int i=0;i<n;i++)
			{
				if(count_arr[i]>1)
				{
					count++;
				}
			}
			cout<<count<<endl;
			fun(parent,n);
		}
		else if(ch=='-')
		{
		 return ;
		}
}

int main()
{
	long int n;
	cin>>n;
	int parent[n];
	for(int i=0;i<n;i++)parent[i]=i;
	fun(parent,n);	
}
