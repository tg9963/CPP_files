#include<iostream>
#include<string.h>
using namespace std;
static int count=0;
static int size=0;
//recursive function to print the string in dancing format
//flag-1 uppercase
//flag-0 lowercase
//flag-2 all the other characters including special characters
void rec_check(string s,int flag)
{
	 
	count++;
	char temp=' ';
	if (count==size+1)return ;
	if(flag==2) //a special character case
	{ 
		printf("%c",s[0]);
		//get the remaining string and check the first character 
		s=s.substr(1,s.size());
		if(s[0]<=90 && s[0]>=65)flag=1;
		else if(s[0]<=122 && s[0]>=97)flag=0;
		else flag=2;
		return	rec_check(s,flag);
	}
	if(flag==1) // a uppercase case
	{
		printf("%c",s[0]);
		//get the remaining string and check the first character
		s=s.substr(1,s.size());
		if(s[0]<=90 && s[0]>=65) //if the first char in this new string is a upper case then modify it because the previous char is a uppercase  (flag-1)
		{
			temp=s[0];
			temp=temp+32;
			flag=0; //change the flag as it is a lowercase now
			s=temp+s.substr(1,s.size());
			return 	rec_check(s,flag);
		}
		else if(s[0]<=122 && s[0]>=97) //no modification required because the previous char is a uppercase  (flag-1)
		{ 
			flag=0; //change the flag as it is a lowercase now
			return 	rec_check(s,flag);	
		}
		else flag=2; // in all other special characters flag=2 
		return 	rec_check(s,flag); // call the recursive function for the remaining string with a flag
	}
	else //a lowercase case 
	{
		printf("%c",s[0]);
		//get the remaining string and check the first character
		s=s.substr(1,s.size());
		if(s[0]<=90 && s[0]>=65)//no modification required because the previous char is a uppercase  (flag-0)
		{
			flag=1; //change the flag as it is a uppercase now
			return 	rec_check(s,flag);	
		}
		else if(s[0]<=122 && s[0]>=97)//if the first char in this new string is a lowercase then modify it because the previous char is a lowercase  (flag-0)
		{
			temp=s[0];
			temp=temp-32;
			flag=1; //change the flag as it is a uppercase now
			s=temp+s.substr(1,s.size());
			return 	rec_check(s,flag);	
		}
		else flag=2;  // in all other special characters flag = 2
		return 	rec_check(s,flag);
	}
}
//check the first character and pass the flag accordingly to a recurssive function
//if the first character is a upper case then the next one must be a lowercase and vice versa 
void dancing(string s)
{
	
	int flag=0;
	if(s[0]<=90 && s[0]>=65)flag=1;
	else if(s[0]<=122 && s[0]>=97)flag=0;
	else flag=2;
	size=s.size();
	rec_check(s,flag);
	count=0;
}
//main function to accept a string and print the string in a Dancing format
int main()
{
	string s="geeksforgeeks"; 
	/*
	always the first char remains same
	here the first char is a lowercase so in the output second char must be a uppercase 
	so output must be "gEeKsFoRgEeKs"
	*/
	dancing(s);
	s="GeeksForGeeks";
	/*
	here the first char is a uppercase so in the output second char must be a lowercase 
	so output must be "GeEkSfOrGeEkS"
	*/
	cout<<endl;
	dancing(s);
	s="gEeksForGeeks";
	/*
	here the first char is a lowercase so in the output second char must be a uppercase 
	so output must be "gEeKsFoRgEeKs"
	*/
	cout<<endl;
	dancing(s);
	return 0;
}
