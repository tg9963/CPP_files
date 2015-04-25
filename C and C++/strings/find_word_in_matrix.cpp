#include "iostream"
using namespace std;
#include "cstring"
 
int isWordExistInMatrix(char arr[][4],int n,int m,char word[])
{
    char min='z',max='a';
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(min>arr[i][j]) min=arr[i][j];
        if(max<arr[i][j]) max=arr[i][j];
    }
 
    bool path[max+min-1][max+min-1];
 
    //index of path array is defined as (arrayElement-min)
 
     for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        //checking forward movement
 
        if(j+1<m)
        {
           path[arr[i][j]-min][arr[i][j+1]-min]=true;
        }
 
        //checking for backward movement
 
        if(j-1>=0)
        {
            path[arr[i][j]-min][arr[i][j-1]-min]=true;
        }
 
        //checking for downward path
        if(i+1<n)
        {
            path[arr[i][j]-min][arr[i][i+1]-min]=true;
        }
        //checking for upward path
        if(i-1>=0)
        {
            path[arr[i][j]-min][arr[i][i-1]-min]=true;
        }
        //right down diagonal
        if(i+1<n&&j+1<m )
        {
            path[arr[i][j]-min][arr[i+1][j+1]-min]=true;
        }
        //right upper
        if(i-1>=0 && j+1<m)
        {
            path[arr[i][j]-min][arr[i-1][j+1]-min]=true;
        }
        //left upper
        if(j-1>=0 && i-1>=0)
        {
            path[arr[i][j]-min][arr[i-1][j-1]-min]=true;
        }
        //left down
        if(j-1>=0 && i+1<n)
        {
            path[arr[i][j]-min][arr[i+1][j-1]-min]=true;
        }
    }
    int count=0;
    for(int i=0;i<strlen(word)-1;i++)
    {
        //cout<<word[i]-min<<endl;
       if(path[word[i]-min][word[i+1]-min]) count++;
    }
   // cout<<count<<endl;
    if(count==strlen(word)-1) cout<<"given word exist in matrix\n";
    else cout<<"given word NOT exist in matrix\n";
}
int main()
{
char a[][4]={'h','b','c','d','e','e','g','h','l','l','k','l','m','o','f','p'};
    isWordExistInMatrix(a,4,4,"hello");
    isWordExistInMatrix(a,4,4,"hglfo");
    isWordExistInMatrix(a,4,4,"fjwrfjr");
}
