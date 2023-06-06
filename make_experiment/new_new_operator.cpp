#include <iostream>
#include "new_new_operator.h"
#include "new_new_operator_i.h"



void* operator new (std::size_t size_new)
	{
		void* ptr = (void*) malloc(sizeof(int)*size_new);
		std::cout<<"my new operator"<<std::endl;
		return ptr;
	}
int main()
{
	int size_of_matrix;
	int sum;
	do 
	{
		std::cout<<"Enter size of matrix: ";
		std::cin>>size_of_matrix; 
	} 
	while (size_of_matrix <2);
		
	int** ptr = new int*[size_of_matrix];
	for (int i=0; i<size_of_matrix; i++)
	{
		ptr[i] = new int[size_of_matrix];
	}
	initialize_matrix(ptr,size_of_matrix);
	sum=sum_of_num_under_diag(ptr,size_of_matrix);
	
	std::cout<<"Sum is: "<<sum<<std::endl;
	
	for (int i=0;i<size_of_matrix;i++)
	{
		delete []ptr[i];
	}
	
	delete []ptr;
	return 0;
}