#include<set>
#include<iostream>

using namespace std;
int main()
{
	int arr[]={1,2,3,4};
	
	set<int> a(arr,arr+1);
	set<int>::iterator i;
	for(i=a.begin();i!=a.end();i++)
	{
		cout<<a;
	}
	
	return 0;
}
