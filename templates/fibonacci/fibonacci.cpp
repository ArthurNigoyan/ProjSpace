#include <iostream>
#include <vector>


template <unsigned int n>
struct fibonacci
{
			
	enum { value =fibonacci<n-1>::value+fibonacci<n-2>::value };
	
};

template <>
struct fibonacci<0>
{
			
	enum { value = 0 };
	
};
template <>
struct fibonacci<1>
{
			
	enum { value = 1 };
	
};


int main()
{
	 std::cout<<fibonacci<15>::value<<std::endl;
	 std::cout<<fibonacci<10>::value<<std::endl;
	 std::cout<<fibonacci<0>::value<<std::endl;
	 std::cout<<fibonacci<1>::value<<std::endl;
	
	
	return 0;
}