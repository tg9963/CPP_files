#include<iostream>
#include<math.h>
using namespace std;

int main()
{
		int n;
		cin>>n;
		int arr[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>arr[i][j];
			}
		}
		int power;
		cin>>power;
		long long int result;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				result*=pow(power,arr[i][j]);
			}
		}
		cout<<(result%1000000007);
}
