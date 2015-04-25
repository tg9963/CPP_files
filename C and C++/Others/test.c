int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while(n)
  {
  	printf("hey");
    count += n & 1;
    n >>= 1;
  }
  return count;
}
 
/* Program to test function countSetBits */
int main()
{
    int i = 9;
    printf("%d", countSetBits(i));
    getchar();
    return 0;
}
