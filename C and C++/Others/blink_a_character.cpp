#include<iostream>
#include<time.h> 
using namespace std;

int main()
{
	char ch;
	cin>>ch;
	int count=0; 
	while(1)
	{
		if(count%10000 == 0)
		{
			printf("%c \r",ch);
			printf("\t\t");
		} 
		count++; 
	}
	return 0;
}
