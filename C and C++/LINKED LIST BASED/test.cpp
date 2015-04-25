#include<iostream>
using namespace std;
void fun(int b);
void fun(int b=7)
{
	cout<<b;
	//return 1;
}
int main()
{
	int a=5;
	fun(a);
	return 0;
}

