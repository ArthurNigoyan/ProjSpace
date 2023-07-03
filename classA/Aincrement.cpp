#include <iostream>

class A
{
    private: 
        int i;
	public:
 
    A(int i = 0)
    {
        this->i = i;
    }
 
    //pre
    A& operator++()
    {
        ++i;
        return *this;
    }
	//post
    A operator++(int)
    {
        A temp = *this;
        ++i;
        return temp;
    }
 
    void display()
    {
        std::cout << "i = " << i << std::endl;
    }
};

int main ()
{
	A a(3);
	A a1 = ++a;
	std::cout << "After pre increment: " << std::endl;
    std::cout << "a: ";
    a.display();
    std::cout << "a1: "; 
    a1.display();
	A a2 = a++;
	std::cout << "After post increment: " << std::endl;
    std::cout << "a: ";
    a.display();
    std::cout << "a2: "; 
    a2.display();
	
	
	return 0;
}