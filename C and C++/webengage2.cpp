#include<iostream>
#include<math.h>
using namespace std;

int x(int n)
{
	if(n==0)
	{
		return 0;
	}
	while (n%2 == 0)
    {
    	//cout<<" 2 "<<endl;
        return 2;
        n = n/2;
    }
 
     
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
        //	cout<<" "<<i<<endl;
            return i;
            n = n/i;
        }
    }
    if (n > 2)
    {
    	//cout<<" "<<n<<endl;
    	return n;
    }
    return 0;
        
}
int a[1000000],f[1000000],g[1000000];

int y(int n)
{
	if(n==0)
	{
		return 0;
	}
	int sum=0,i=2;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			sum+=i;
		}
	}
	return sum;
}	
		int f_f(int n)
		{
			if(n==0)
			{
				return 0;
			}
			if(f[n]!=0)
			{
				return f[n];
			}
			else
			{
				f[n]=f_f(n-1)+x(n);
				//cout<<"  "<<x(n)<<endl;
				return f[n];
			}
		}
		
		int g_g(int n)
		{
			if(n==0)
			{
				return 0;
			}
			if(g[n]!=0)
			{
				return g[n];
			}
			else
			{
				g[n]=g_g(n-1)+y(n);
				return g[n];
			}
		}
		
		
		int find_vals(int a[],int f[],int g[],int n)
		{
			if(n==0)
			{
				return 0;
			}
			if(a[n]!=0)
			{
				return a[n];
			}
			else
			{int g=f_f(n);
			int f=g_g(n);
				int k=g+f;
				//cout<<g<<"  "<<f<<"  "<<k<<endl;
				a[n]=(k)%n;
				a[n]=a[n]-1;
				return a[n];
			}
		}
		
int main()
{
	int test;
	cin>>test;
	a[0]=f[0]=g[0]=0;
	while(test--)
	{
		int n;
		cin>>n;
		cout<<find_vals(a,f,g,n)<<endl;
	}
	return 0;
}
