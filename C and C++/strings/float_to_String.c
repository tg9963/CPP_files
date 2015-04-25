#include<stdio.h>
void reverse(char *ch,int len)
{
	int i=0,j=len-1;
	char temp;
	while(i<j)
	{
		temp=ch[j];
		ch[j]=ch[i];
		ch[i]=temp;
		i++;
		j--;
	}
}
int string_main(int temp,char *ch,int d)
{
	int i=0;
	while(temp)
	{
		ch[i++]=(temp%10)+'0';
		temp=temp/10;
	}
	while(i<d)ch[i++]='0';
	reverse(ch,i);
	return i;
}

void convert(float num,char *ch,int prec)
{
	int temp;
	temp=(int)num;
	int i=string_main(temp,ch,4);
	float fpart=num-temp;
	if(prec !=0)
	{
		ch[i]='.';
		fpart=fpart*pow(10,prec);
		//printf("%f \n",fpart);
		string_main((int)fpart,ch+i+1,prec);
	}
	return ;
}
int main()
{
	char ch[10];
	float num;
	scanf("%f",&num);
	convert(num,ch,8);
  printf("%s",ch);
	return 0;
}
