#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char a[100][100];//character 2d matrix
int n,m;// n rows and m columns of character matrix
int visited[100][100];//visited 2d array for DFS

// issafe function for checking boundary conditions in DFS
bool issafe(int i,int j)
{
	if(i<n&&j<m&&i>=0&&j>=0)
	{
		return true;
	}
	return false;
}

int row[8]={-1,-1,0,1,1,1,0,-1};
int col[8]={0,-1,-1,-1,0,1,1,1};

//DFS function
bool dfs(int si,int sj,char str[],int cnt,int len)
{
	int k,ni,nj;
	for(k=0;k<8;++k)
	{
		ni=si+row[k];
		nj=sj+col[k];
		
		if(issafe(ni,nj)&&visited[ni][nj]!=1&&a[ni][nj]==str[cnt])
		{
			
			if(cnt==len-1)// count equals for string end that means we have found the word
			{
				return true;
			}
			visited[ni][nj]=1;
			if(dfs(ni,nj,str,cnt+1,len))
			{
				return true;
			}
			else
			{
				visited[ni][nj]=0;
				continue;
			}
		}
	}
	return false;
	
}
//dfs utility function 
bool dfsutil(char str[])
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(a[i][j]==str[0])
			{
			
				visited[i][j]=1;
				int len=strlen(str);
				if(dfs(i,j,str,1,len))//if str[0] matches with a[i][j] then call DFS
				{
					visited[i][j]=0;
					return true;
				}
				else
				{
					visited[i][j]=0;
					continue;
				}
				
			}
			visited[i][j]=0;
		}
	}
	return false;
}
int main()
{
	int words,i,j;
	char w[100][100];
	scanf("%d %d",&n,&m);
	getchar();
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			scanf("%c",&a[i][j]);//input 2d character array
			visited[i][j]=0;
		}
		getchar();
	}
	/*
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
	
			printf("%c",a[i][j]);
		}
	
	}
	/*
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
	
			visited[i][j]=0;
		}
	
	}
	*/
	
	scanf("%d",&words);//input no. of words
	
	for(i=0;i<words;++i)
	scanf("%s",w[i]);
	
	char str[100];
	for(i=0;i<words;++i)
	{
		strcpy(str,w[i]);
		if(dfsutil(str))//true if we have found the word
		{
			
			printf("%s is present in given matrix\n",str);
			
			
			}
		else
		{
			printf("%s is not present in given matrix\n",str);
			}
		
		}
	return 0;
}

