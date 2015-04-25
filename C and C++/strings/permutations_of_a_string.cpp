#include<iostream>
#include<string.h>

using namespace std;


void swaps(char *a,char *b)
{
	char temp;
	temp=*b;
	(*b )=(*a);
	*a=temp; 
} 
void permute(char *a,int start,int end)
{
	if(start==end)
	{
		printf("%s\n",a);
	}
	else
	{
		for(int j=start;j<=end;j++)
		{
			if(a[start]==a[j] && start!=j)
			continue;
			swaps((a+start),(a+j));
			permute(a,start+1,end);
			swaps((a+start),(a+j));
		}
	}
}

int main()
{
	char a[]="saa";
	permute(a,0,2);
	return 0;
}
