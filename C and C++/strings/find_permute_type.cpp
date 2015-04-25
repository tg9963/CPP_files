#include<iostream>
#include<string.h>
using namespace std;

void permute(char arr[],int n)
{
	char temp[n];
	char temp2[n];
	strcpy(temp,arr);
	int i=0;
	for(int i=0;i<n;i++)
	{
		strcpy(temp2,arr);
		for(int j=i;j<n;j++)
		{
			arr[j]+=32;
			cout<<arr<<endl;
		}
		strcpy(arr,temp2);
		for(int k=(n-2);k>i;k--)
		{
			arr[k]+=32;
			cout<<arr<<endl;
		}
	strcpy(arr,temp);
	}
}


int main()
{
	char arr[]="THE";
	int n=strlen(arr);
	permute(arr,n);
	return 0;
}
