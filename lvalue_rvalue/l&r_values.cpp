#include <iostream>
#include <string>

class A
{
	public:
		std::string mb_str;
		A()
		{
			std::cout<<"default constructor for A class"<<std::endl;
		}
		A(const std::string str) : mb_str(str)
		{
			std::cout<<"constructor for A class"<<std::endl;
		}
		A(const A & object) : mb_str(object.mb_str)
		{
			std::cout<<"copy constructor for A class"<<std::endl;
		}
		~A()
		{
			std::cout<<"destructor for A class"<<std::endl;
		}
		A& operator = (const A & object)
		{
			if (this != &object) 
			{
				this->mb_str = object.mb_str;
			}
			std::cout<<"operator assignment for A class"<<std::endl;
			return *this;
		}
		public:
			std::string get_mb_str() const
			{	
				std::cout<<"method for A class"<<std::endl;
				return mb_str;
			}
		
};
void print(A& obj)
{
	std::cout<<"by left value reference -- "<<obj.get_mb_str() <<std::endl;
}
void print1(A obj)
{
	std::cout<<"by left value -- "<<obj.get_mb_str()<<std::endl;
	
}
void print(const A& obj)
{
	std::cout<<"by const left value reference "<<obj.get_mb_str()<<std::endl;
}
void print(A&& obj)
{
	std::cout<<"by right value reference "<<obj.get_mb_str() <<std::endl;
}
void print(const A&& obj)
{
	std::cout<<"by const right value reference "<<obj.mb_str<<std::endl;

}



int main ()
{
	A obj1("Bubba");
	print1(obj1); //lvalue
	print(obj1);//lvalue reference
	const A obj2("DRACA");
	print(obj2);//const lvalue reference
	
	A&& obj3 = A("Mochi");
	print(std::move(obj3));
	const A&& obj4 = A("Makki");
	print(std::move(obj4));
	return 0;
}