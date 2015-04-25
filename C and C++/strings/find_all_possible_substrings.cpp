#include<iostream>
#include<string.h>
#include<map>
using namespace std;

void print_string(char arr[],int i,int j,int n,map<char*,char*>& m)
{
	char temp[j-i];
	int count=0;
	for(int k=i;k<=j;k++)
	{
		temp[count++]=arr[k];
		//cout<<arr[k];
	}
	m[temp]=temp;
	cout<<m[temp]<<endl;
	//cout<<endl;
}

void find_substrings(char arr[],int n)
{
	map<char*,char*> m;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			print_string(arr,i,j,n,m);
		}
	}
	map<char*,char*>::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		cout<<(it)->second;
	}
	
}

int main()
{
	char arr[]="HelHel";
	int n=5;
	find_substrings(arr,n);
	return 0;
}
