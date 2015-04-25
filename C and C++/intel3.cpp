#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
	long long s_time;
	long long e_time;
};

struct result
{
	long long time;
	int num;
};

int comp(const void * a,const void * b)
{
	struct result * t=(struct result *)a;
	struct result * r=(struct result *)b;
	return ((*t).time > (*r).time);
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		struct node array[n];
		long long temp;
		long long count=0;
		
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			array[i].s_time=temp;
		}
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			array[i].e_time=array[i].s_time+temp;
		}
		struct result exp[2*n];
		for(int i=0;i<n;i++)
		{
			exp[i].time=array[i].e_time;
			exp[i].num=-1;
		}
		for(int i=0;i<n;i++)
		{
			exp[n+i].time=array[i].s_time;
			exp[n+i].num=1;
		}	
		qsort(exp,2*n,sizeof(struct result),comp);

		int max=exp[0].num;
		for(int i=1;i<2*n;i++)
		{
			exp[i].num+=exp[i-1].num;
			if(exp[i].num>max)
			{
				max=exp[i].num;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
