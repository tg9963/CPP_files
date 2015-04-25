#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int rows;
	cout<<"enter Total rows: ";
	cin>>rows;
	cout<<" enter row and col: ";
	int q_row,q_col;
	cin>>q_row;
	cin>>q_col;
	if(q_row>rows) return 0;
	for(int i=0;i<rows;i++)
	{
		q_row--;
		if(q_row==0)
		{
			int val=1;
		  for(int k=0;k<=i;k++)
		{
			q_col--;
			if(q_col==0)
			 cout<<val;
			val=val*(i-k)/(k+1);
		}
		cout<<endl; 
		}
		
	}
	return 0;
}
