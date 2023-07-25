#include <iostream>
#include <vector>
template <typename Z>
Z fibonacci(Z n)
{
	if (n==0) {
		return 0;
	} else if (n==1) 
	{
		return 1;
	}		
	return fibonacci(n-1)+fibonacci(n-2);
	
}



int main()
{
	// std::cout<<factorial(3)<<std::endl;;
	// std::cout<<factorial("b");
	 std::cout<<fibonacci(15)<<std::endl;
	 std::cout<<fibonacci(10)<<std::endl;
	 // fibonacci<40>::value;fibonacci
	 std::vector<int> altern;
	 for (int i = 0; i <= 10; i++)
        altern.push_back(fibonacci(i));
	 for (auto i = altern.begin(); i != altern.end(); ++i)
        std::cout<<*i <<" ";
	return 0;
}