#include<stdio.h>

void print_sub(char arr[],int n1,int n2)
{
	static int i;
	if(arr[i]=='\0')return ;
	i++;
	if(i>=n1 && i<=n2)
	{
		printf("%c",arr[i]);
	}
	print_sub(arr,n1,n2);
}

int main()
{
	char arr[]="geeksforgeeks";
	print_sub(arr,1,3);
}
