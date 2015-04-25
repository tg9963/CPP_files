#include<iostream>
#include<string.h>

using namespace std;

int get_number(string s)
    {
    if(s.size()==0 || s.size()%2==1)return -1;
    int has1[256];
     string s1=s.substr(0,(s.size() / 2));
    
    string s2=s.substr((s.size() / 2), s.size());
	for(int i=0;i<256;i++)
        has1[i]=0;
        
    for(int i=0;i<s1.size();i++)
        has1[s1[i]]+=1;
    int count=0;
    for(int i=0;i<s2.size();i++)
        {     	
        if(has1[s2[i]]==0)
		{
			count++;
		}
		else
		{
			has1[s2[i]]-=1;
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
        string ip;
        cin>>ip; 
        cout<<get_number(ip)<<endl;
    }
    return 0;
}
