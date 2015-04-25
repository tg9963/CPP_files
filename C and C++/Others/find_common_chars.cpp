#include<iostream>
#include<string.h>
using namespace std;

int main()
    {
    int n;
    cin>>n;
    int flag[n][256];
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<256;j++)
            {
            flag[i][j]=0;
        }
    }
    int count=0;
    while(n--)
        {
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
            {
            flag[count][s[i]]+=1;
            cout<<flag[count][s[i]]<<" ";
        }
        count++;
    }
    count=0;
    int temp_count=0;
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<256;j++)
            {
            cout<<flag[i][j]<<" ";
        }
        cout<<endl;
    }
    /*
    for(int j=0;j<256;j++)
        { 
    for(int i=0;i<n;i++)
        {
        cout<<flag[i][j]<<" ";
        if(flag[i][j])
            temp_count++;
    }
        cout<<endl;
        if(temp_count==n-1)count++;
    }
   // cout<<count;
   */
    return 0;
}
