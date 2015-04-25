#include<iostream>
#include<string.h>
using namespace std;

int find_pos(string s,char ch,int start)
{
	int res=-1;
	int n=s.size();
	for(int i=start;i<n;i++)
	{
		if(s[i]==ch)return i;
	}
	return res;
}

int get_mismatches(string s1,string s2,int n,int len)
    {
    int i=0,j=0,x=0;
    int res=0;
    int max_len=0;
    for(i=0;i<n;i++)
        {
        	for(int k=0;k<n;k++)
        	{ 
        j=find_pos(s2,s1[i],j);
        if(j==-1)
            {
            	j=0;
            continue;
        }
        int x=1,y=1;
        int count=0;
        int temp_x=x,temp_y=y;
        while(1)
            {
            if(i-x>=0 && j-x>=0 && s1[i-x]!=s2[j-x])
                {
                count++;
                 temp_x=x;
            }
            if(i+y<n && j+y<n && s1[i+y]!=s2[j+y])
                {
                count++;
                 temp_y=y;
            }
            x++;
            y++;
            if(count>=len || i+y>n || i-x<0 )break; 
        }
        if(temp_x+temp_y >max_len)
            {
            max_len=temp_x+temp_y;
        }
    	}
        
    }
    return max_len;
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
