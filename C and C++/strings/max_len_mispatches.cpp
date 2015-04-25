#include<iostream>
#include<string.h>
using namespace std;

int get_mismatches(string s1,string s2,int n,int len)
    {
    int i=0,j=0,x=0;
    int res=0;
    int max_res=res;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		for(int x=0;res<=n;x++)
    		{
    			if(s1[i+x]!=s2[j+x])
    			{
    				res++;
    			}
    			
    		}
			if(res >max_res)
			{
				
			} 
    	}
    }
    
    return max_res;
}


int main()
    {
    int test;
    cin>>test;
    while(test--)
        {
        string s1;
        string s2;
        int len;
        cin>>len;
        cin>>s1>>s2;
        int n1=s1.size(); 
        cout<<get_mismatches(s1,s2,n1,len)<<endl;
    }
    return 0;
}
