#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
	stack<int> a;
	a.push(5);
	cout<<a.top()<<endl;
	a.pop();
	cout<<a.empty();
	queue<int> q;
	return 0;
}
