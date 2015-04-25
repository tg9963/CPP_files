#include<map>
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int arr[]={1,2,3,3,4,4,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	map<int,int> hash_table;
	
	for(int i=0;i<10;i++)
	{
		hash_table[i] =-1;
	}
	for(int i=0;i<n;i++)
	{
		hash_table[arr[i]]++;
	}
	map<int,int>::iterator i;
	for(i=hash_table.begin();i!=hash_table.end();i++)
	{
		if((*i).second > 0)
		{
			cout<<" First repeating is "<<(*i).first;
			return 0;
		}
	}
}
