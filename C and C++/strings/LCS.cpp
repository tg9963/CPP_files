#include<iostream>
#include<string.h>

using namespace std;
int maxi(int a,int b)
{
	return (a>=b ?a:b);
}
int lcs(char a[],char b[])
{
	int m,n;
	m=strlen(a);
	n=strlen(b);
	int array[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)array[i][j]=0;
			else if(a[i]==b[j])array[i][j]=array[i-1][j-1]+1;
			else array[i][j]=maxi(array[i-1][j],array[i][j-1]);
		}
	}
	//printf("%d",array[m][n]);
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)printf("%d ",array[i][j]);
	printf("\n");
	}
	int index=array[m][n];
	int i=m,j=n;
	int p=0;
	char st[index+1];
	st[index]='\0';
	int count=0;
	while( i>0 && j>0)
	{
		 if(a[i-1]==b[j-1])
		 {
		 	//printf("%c",a[i-1]);
		 	st[index-1]=a[i-1];
		 	i--;j--;index--;
		 }
		 else if(array[i-1][j]>array[i][j-1])
		 i--;
		 else
		 j--;
	}	
	printf(" hey %s",st);
	return array[m][n];
}
int main()
{
	char a[]="GOPINATH";
	char b[]="GOPNAT";
	printf(" ",lcs(a,b));
	return 0;
}
