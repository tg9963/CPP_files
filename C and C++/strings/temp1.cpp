#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

int main()
{
	string line;
	fstream f("test.txt");
	ofstream p("sample.txt");
	if(f.is_open() && p.is_open())
	{
		while(getline(f,line))
		{
			cout<<line<<endl;
			p<<line;
		}
	}
	return 0;
}
