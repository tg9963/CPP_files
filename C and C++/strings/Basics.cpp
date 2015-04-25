#include<iostream>
#include<string.h>
#include<sstream> 
using namespace std;

int main()
{
	char s[]="Hello";
	//s+="a";
	char s2[]="el";
	cout<<strstr(s,s2);
	stringstream a;
	int b=134;
	a<<b;
	string s3=a.str();
	a>>s3;
	cout<<s3;
	cout<<a.str();
//	cout<<s3;
	return 0;
}

