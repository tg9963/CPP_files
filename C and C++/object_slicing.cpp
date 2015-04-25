#include <iostream>
#include<string>
using namespace std;
 
class Base
{
public:
	int x;
    virtual string print() const
    {
        return "This is Base class";
    }
};
 
class Derived : public Base
{
public:
	int x;
    virtual string print() const
    {
        return "This is Derived class";
    }
};
 
void describe(Base p)
{
    cout << p.print() << endl;
}
 
int main()
{
    Base b;
    Derived d;
   d=b; // not possible but b=d is possible.
    describe(b);
    describe(d);
    return 0;
}
