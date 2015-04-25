#include<iostream>
using namespace std;

class Bix
{
    public:
    static void MyFunction()
    {
    	cout<<"hey";
    }
};
int main()
{
    void(*ptr)() = &Bix::MyFunction;
    ptr();
	return 0; 
}
