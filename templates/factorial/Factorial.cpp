#include <iostream>

template <typename T>
T factorial(T n)
{
	if (n<2) {
		return 1;
	}
	return n*factorial(n-1);
}



int main()
{
	std::cout<<factorial(3)<<std::endl;;
	
	return 0;
}