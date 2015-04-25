#include<iostream>
#include<map>
#include<string.h>

using namespace std;

int main()
{
	map<string,int> m;
	string s;
	getline(cin,s);
	string temp="",arr[100];
	int count=0;
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==' ' || s[i]=='\0')
		{
			arr[count++]=temp;
			temp="";
		}
		else
		{
			temp+=s[i];
		}
	}
	arr[count++]=temp;
	for(int i=0;i<count;i++)
	{
		if(m[arr[i]]==-1)
		{
			m[arr[i]]=1;
		}
		else
		{
			m[arr[i]]+=1;
		}
	}
	
	map<string,int>::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		cout<<(*it).first<<"  "<<(*it).second<<endl;
	}
	
	return 0;
}
