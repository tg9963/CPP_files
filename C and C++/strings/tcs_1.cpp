#include<iostream>
#include<string.h>
using namespace std;

int min_ops(string s)
{
	int values[26];
	for(int i=0;i<26;i++)values[i]=0;
	
	for(int i=0;i<s.size();i++)
	{
		values[s[i]-97]+=1;
	}
	int count=0;
	for(int i=0;i<s.size();i++)
	{
		if(values[s[i]-97]!=-1)
		{
		int n=s[i]-96;
		if(values[s[i]-97]<n)
		{
			count+=n-values[s[i]-97];
		}
		else if(values[s[i]-97]>n)
		{
			count+=values[s[i]-97]-n;
		}
		
		values[s[i]-97]=-1;
		
		}
	}
	return count;
}


int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		string s;
		cin>>s;
		cout<<min_ops(s);
	}
}
