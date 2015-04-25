#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	string s;
	getline(cin,s);
	int i,j;
	cin>>i>>j;
	cout<<s.substr(4,8);
	return 0;
}
