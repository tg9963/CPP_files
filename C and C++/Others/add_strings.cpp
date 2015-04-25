#include<iostream>
#include<string.h>
using namespace std;
string add_s(string s1,string s2)
{
	int len1=s1.size();
	int len2=s2.size();
	if(len1>len2)
	{
		for(int i=len2;i<len1;i++)
		s2='0'+s2;
		len2=len1;
	}
	else if(len2>len1)
	{
		for(int i=len1;i<len2;i++)
		s1='0'+s1;
		len1=len2;
	}
	//cout<<s1<<endl;
//	cout<<s2<<endl;
	if(len2==len1)
	{
		string result="";
		int carry=0;
		//cout<<"hey \n";
		for(int i=len1-1;i>=0;i--)
		{
			int bit1=s1.at(i)-'0';
			int bit2=s2.at(i)-'0';
			int sum=(bit1^bit2^carry)+'0';
			result=(char)sum+result;
			carry=(bit1 & bit2)| (bit1 & carry) | (bit2 & carry);
		}
		if(carry)result='1'+result;
		return result;
	}
}
int main()
{
	string s1;
	string s2;
	cin>>s1;
	cout<<endl;
	cin>>s2;
	cout<<add_s(s1,s2);	
	return 0;
}
