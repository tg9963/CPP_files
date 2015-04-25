#include<iostream>
using namespace std;
class aclass
{
	private:
		int b;
		int a;
	public:
		aclass(): b(10),a(b+11)
		{
			//a=12;
		}
		/*	
		aclass(int dataa,int datab)
		{
			b=datab;
			a=dataa;
		}
		*/
		void print_l()
		{
			cout<<"a : "<<a<<" b: "<<b;
		}
};

int main()
{
	class aclass obj1;
	obj1.print_l();
}
