#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	string s1="hello is this gopi ";
	string s2=" is ";
	int n=s1.size();
	int m=s2.size();
	int i,j,count=0;
	for(i=0;i<n-m;i++)
	{
		count=0;
		for(j=0;j<m;j++)
		{
			if(s1[i+j]!=s2[j])
			break;
			
			count++;
		}
		if(count==m)
		{
			cout<<" Found at "<<i<<endl;
		}
	}
	return 0;
}
