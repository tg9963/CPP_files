#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std;


int main()
{
	int arr[]={-1,0,0,1,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int op[n]; 
	if(arr[0]!=-1)return 0;
	queue<int> q;
	q.push(0);
	q.push(-1); 
	int count=0;
	stack<int> st; 
	while(!q.empty() || count==n)
	{ 
		int curr_parent=q.front();
		st.push(curr_parent);
		q.pop();
		if(curr_parent==-1)
		{
			if(!q.empty())
			q.push(-1);
		}
		else
		{ 	 
		int j=curr_parent; 
		if(2*j + 2 < n)
		q.push(2*j + 2);
		if(2*j + 1 < n)
		q.push(2*j + 1);
		} 
	}
	st.pop();
	while(!st.empty())
	{
		if(st.top()==-1)
		{
			cout<<endl;
			st.pop();
		}
		else
		{
			cout<<st.top()<<" ";
			st.pop();
		}
	} 
	return 0;
}
