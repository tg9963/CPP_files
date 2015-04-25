#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int arr[]={15,2,6,8,9,4};
	vector<int> a(arr,arr+5);
	make_heap(a.begin(),a.end());
    vector<int>::iterator it;
    for(it=a.begin();it!=a.end();it++)
    {
    	cout<<*it<<" ";
    }
	return 0;
}
