#include<iostream>
using namespace std;
int compare_s(string s1,string s2)
{
	int i;
	 for(i=0;s1[i]&& s2[i];i++)
	 {
	 	if(s1.at(i)==s2.at(i) || s1.at(i)^32==s2.at(i))continue;
	 	else break;
	 }
	 //cout<<"i "<<i;
	 i=i-1;
	 if(s1.at(i)==s2.at(i))return 0;
	 if((s1.at(i)|32) < (s2.at(i)|32))return -1;
	 return 1;
}

int main()
{
	string s1;
	string s2;
	cin>>s1;
	cout<<endl;
	cin>>s2;
	cout<<compare_s(s1,s2);
	return 0;
}
