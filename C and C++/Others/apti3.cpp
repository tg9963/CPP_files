#include<iostream>
using namespace std;

int main()
{
	int c=0;
	int arr[8][10];
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<8;j++)
		{
			arr[j][i]=c++;
		}
	}
	printf("%d ",arr[0][2]);
	//printf("%d %d %d",c,c<<2,c>>2);
	return 0;
}
