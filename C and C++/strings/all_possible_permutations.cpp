#include<iostream>
#include<map>
#include<string.h>

using namespace std;
map<string,int> m;

string swaps(string s,int i,int j)
{
	if(i==j)return s;
	string res="";
	int siz=s.size();
	int n1=j-i-1;
	res=s.substr(0,i)+s[j]+s.substr(i+1,j-i-1)+s[i]+s.substr(j+1,siz-j);
	return res;
}


void find_perm(string s,int pos,int n)
{
	if(pos==n-1)
	{
		if(m[s]==-1)
		{
			m[s]=1;
		}
		else
		{
			m[s]+=1;
		}
		return ;
	}
	for(int i=pos;i<n;i++)
	{
		s=swaps(s,pos,i); 
		find_perm(s,pos+1,n);
		s=swaps(s,pos,i);	
	}
}

int main()
{
	string s;
	cin>>s;
	find_perm(s,0,s.size());
	map<string,int>::iterator it;
	int count=0;
	for(it=m.begin();it!=m.end();it++)
	{
		cout<<(*it).first<<endl;
		count++;
	}
	cout<<endl<<count;
	return 0;
}
