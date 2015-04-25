#include<iostream>
using namespace std;
int swap_bits(int n)
{
	unsigned int odd=n & 0x555555;
	unsigned int even=n & 0xAAAAAA;
	even >>=1;
	odd <<=1;
	return (even | odd); 
}
int main()
{
	int n;
	cout<<"enter a number \n";
	cin>>n;
	cout<<"after swapping: \n"<<swap_bits(n);
	return 0;
}
