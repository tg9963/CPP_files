# include <stdio.h>
# include <stdlib.h>
 
/* Following function is needed for library function qsort(). Refer
   http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
int compare (const void *a, const void * b)
{  return ( *(int *)a - *(int *)b ); }
 
 
int bin_search(int A[],int low,int high,int rem)
{
	if(low>high)return -1;
	int mid=low+(high-low)/2;
	if(rem==A[mid])return mid;
	if(rem > A [mid])
	{
		return bin_search(A,low,mid-1,rem);
	}
	else
	{
		return bin_search(A,mid+1,high,rem);
	}
	
}
/* A sorting based solution to print all combination of 4 elements in A[]
   with sum equal to X */
void find4Numbers(int A[], int n, int X)
{
    int l, r;
    int rem;
 
    // Sort the array in increasing order, using library
    // function for quick sort
    qsort (A, n, sizeof(A[0]), compare);
 
    /* Now fix the first 2 elements one by one and find
       the other two elements */
       int i,j;
    for (i = 0; i < n - 3; i++)
    {
        for ( j = i+1; j < n - 2; j++)
        {
            // Initialize two variables as indexes of the first and last 
            // elements in the remaining elements
            l = j + 1;
            /*
            r = n-1;
 
            // To find the remaining two elements, move the index 
            // variables (l & r) toward each other.
            while (l < r)
            {
                if( A[i] + A[j] + A[l] + A[r] == X)
                {
                   printf("%d, %d, %d, %d", A[i], A[j],
                                           A[l], A[r]);
                   l++; r--;
                }
                else if (A[i] + A[j] + A[l] + A[r] < X)
                    l++;
                else // A[i] + A[j] + A[l] + A[r] > X
                    r--;
            } // end of while
            
            */
            rem=X-(A[i]+A[j]+A[l]);
           //printf("%d \n",rem);
		    r=bin_search(A,l,n-1,rem);
            
            //printf("%d  %d %d %d \n",r,rem,X,A[i]+A[j]+A[l] );
            if(r!=-1)
            	 printf("%d, %d, %d, %d", A[i], A[j],
                                           A[l], A[r]);
            
        } // end of inner for loop
    } // end of outer for loop
}
 
/* Driver program to test above function */
int main()
{
    int A[] = {1, 2, 7, 9, 10, 13, 15};
    int X = 22;
    int n = sizeof(A)/sizeof(A[0]);
    find4Numbers(A, n, X);
    return 0;
}
