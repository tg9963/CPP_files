#include<iostream>
using namespace std;

int find_val(char array[],char ops[],int n1,int n2)
{
	
}

int main()
{
	int n,n2;
	cout<<"Enter n: ";
	cin>>n;
	cout<<"\n enter array: ";
	char array[n];
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	cout<<"\n enter number of operators: ";
	cin>>n2;
	cout<<"\n enter operators: ";
	char ops[n2];
	for(int i=0;i<n;i++)
	{
		cin>>ops[i];
	}
	cout<<find_val(array,ops,n1,n2);
}
