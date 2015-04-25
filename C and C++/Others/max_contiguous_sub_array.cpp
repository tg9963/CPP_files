#include<stdio.h>
 
int max(int x, int y)
{ return (y > x)? y : x; }
 
int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0], i;
   int curr_max = a[0];
 	int low_index,end_index,temp_index;
 	low_index=0,end_index=0;
   for (i = 1; i < size; i++)
   {
   		int temp=curr_max;
        curr_max = max(a[i], curr_max+a[i]);
        if(curr_max==a[i] && temp!=0)
        {
        	low_index=i;
    	}
        else
        {
        	temp_index=i;
        }
        max_so_far = max(max_so_far, curr_max);
        if(max_so_far==curr_max)
        {
        	end_index=temp_index;
        }
   }
   //cout<<" start : "<<low_index<<" end: "<<end_index;
   printf("start: %d , end: %d ",low_index,end_index);
   return max_so_far;
}
 
/* Driver program to test maxSubArraySum */
int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   printf("\nMaximum contiguous sum is %d\n", max_sum);
   return 0;
}
