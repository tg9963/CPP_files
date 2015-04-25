#include<stdio.h>
void multiply(int mat1[2][2],int mat2[2][2])
{
	mat2[0][0]=mat1[0][0]*mat2[0][0] + mat1[0][1]*mat2[1][0];
	mat2[0][1]=mat1[0][0]*mat2[0][1] + mat1[0][1]*mat2[0][1];
	mat2[1][0]=mat1[1][0]*mat2[0][0] + mat1[1][1]*mat2[1][0];
	mat2[1][1]=mat1[1][0]*mat2[0][1] + mat1[1][1]*mat2[0][1];
}
void power(int mat1[2][2],int mat2[2][2],int a)
{
	int i;
	for(i=2;i<a;i++)
	multiply(mat1,mat2);
}

int fib(int a)
{
	if(a==0 || a==1)return a;
	int mat1[2][2]={ {1,1},{1,0}};
	int mat2[2][2]={ {1,1},{1,0}};
	power(mat1,mat2,a);
	return mat2[1][0];
}

int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",fib(a));
	return 0;
}
