#include<iostream> 
using namespace std;
class TestDrive
{
    int x; 
    public:
    TestDrive(int xx)
    {
        x = xx;
    }
    int DriveIt(void);
};
int TestDrive::DriveIt(void)
{
    static int value = 0;
    int m;
while(x/2)
{
    m = x % 2;
    x = x / 2;
   /* if((x / 2)) DriveIt(); */ 
    value = value + m * 10; 
}
    return value;

}
int main()
{
    TestDrive TD(1234);
    cout<< TD.DriveIt() * 10 << endl;
    return 0; 
}
