#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int row[]={0,0,-1,1};
int col[]={-1,1,0,0};

int is_safe(int i,int j,int p,int q,int b)
{
	if((i+row[p]>=0 && i+row[p]<b) && (j+col[q]>=0 && j+col[q]<b))return 1;
	
	return 0;
}
int t_i,t_j;

int find_now(char mat[][5],int i,int j,int b,string s2,int pos)
{
	if(pos==s2.size())
	{
		cout<<"Found at "<<t_i<<" "<<t_j;
		cout<<" End at "<<i<<" "<<j<<endl;
		return 1;
	}
	for(int p=0;p<4;p++)
	{
		for(int q=0;q<4;q++)
		{
			if(is_safe(i,j,p,q,b) && mat[i+row[p]][j+col[q]]==s2[pos])
			{
				int val=find_now(mat,i+row[p],j+col[q],b,s2,pos+1);
				if(val==1)
				{	
				 	//return 1;
				}
			}
		}
	}
	return 0;
}



void find_all_possible(char mat[][5],int b,string s2)
{
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<b;j++)
		{
		 if(mat[i][j]==s2[0])	
		 {
		 	t_i=i;
			 t_j=j;
		 	if(find_now(mat,i,j,b,s2,1))
		 	{
				//cout<<"Found at "<<i<<" "<<j<<endl;
		 	}
		 }
		}
	}
}

void find_pos(string s1,string s2)
{
	int n=s1.size();
	float a=sqrt(n)+0.5;
	int b=a;
	char mat[b][5];
	for(int i=0;i<b;i++)for(int j=0;j<b;j++)mat[i][j]='\0';
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<b;j++)
		{
			if(i*b+j < n)
			mat[i][j]=s1[i*b+j];
		}	
	}
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<b;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;	
	}
	
	find_all_possible(mat,b,s2);
}


int main()
{
	string s1;
	cout<<"Enter a string: ";
	cin>>s1;
	cout<<"\nEnter a substring ";
	string s2;
	cin>>s2;
	find_pos(s1,s2);
	return 0;
}
