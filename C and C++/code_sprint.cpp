#include<iostream>

using namespace std;

int main()
{
	int test;
	cin>>test;
	int count=0;
	while(test--)
	{
		int n1;
		int n2;
		cin>>n1>>n2;
		if(n2-n1>=2)
		{
			count++;
		} 
		
	}
	cout<<count<<endl;
	return 0;
}
