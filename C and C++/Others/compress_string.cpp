#include<iostream>
#include<stdio.h>
#include<string.h>
#include<sstream>
using namespace std;
string convert(string s)
{ 
	int i;
	int n=s.size();
	int count=0;
	string temp;
	for(i=0;i<n;i++)
	{
		if(s[i] !=s[i+1])
		{
			if(count!=0)
			{
			stringstream ss;
			ss<<count+1;
			string t=ss.str();
			temp+=s[i]+t;
			}
			else temp+=s[i];
			count=0;
		}
		else
		{
			count++;
		}
	}
	if(s.size()>temp.size())return temp;
	return s;
}
int main()
{
	string s;
	cin>>s;
	s=convert(s);
	cout<<s;
	return 0;
}
