#include<iostream>

using namespace std;
static int a;
void position(int n)
{
	if((n&(n-1)))return ;
	unsigned int i=1;
	int pos=0;
	
	while(!(i&n))
	{
		i<<=1;
		++pos;
	}
	cout<<"pos: "<<pos;
	return ;
}
int main()
{
	int n;
	cout<<"enter n\n ";
	cin>>n;
	position(n);
	return 0;
}
