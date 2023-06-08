#include <iostream>
#include <stdlib.h>

class MATRIX
{
	private:
		int size_of_matrix;
		int** ptr;
	public:
			
	
	MATRIX();
	MATRIX(int size)
	{
		size_of_matrix=size;
		ptr = new int*[size_of_matrix];
		for (int i = 0; i< size_of_matrix;i++)
		{
			ptr[i] = new int[size_of_matrix];
		}
		for(int i=0; i<size_of_matrix;i++)
		{
			for(int j=0; j<size_of_matrix;j++)
			{
				ptr[i][j]=rand()%100;
			}
		}
	}
	~MATRIX()
	{
		for (int i = 0; i< size_of_matrix;i++)
		{
			delete []ptr[i];
		}
		delete []ptr;
	}
	void print_matrix()
	{
		for (int i=0; i<size_of_matrix;i++)
		{
			for (int j=0;j<size_of_matrix;j++)
			{
				std::cout<<ptr[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
	void transfer_columns(int col_first, int col_second)
	{
		for (int i=0; i<size_of_matrix; i++)
		{
			ptr[i][col_first]=ptr[i][col_first]+ptr[i][col_second];
			ptr[i][col_second]=ptr[i][col_first]-ptr[i][col_second];
			ptr[i][col_first]=ptr[i][col_first]-ptr[i][col_second];
		}
	}

	void transfer(int first, int second, std::string col_row)
	{
		if ((first > size_of_matrix) ||  (second>size_of_matrix))
		{
			std::cout<<"Wrong rows entered";
		} 
		else
		{
			if (col_row.compare("row") == 0) 
			{
				for (int i=0; i<size_of_matrix; i++)
				{
					ptr[first][i]=ptr[first][i]+ptr[second][i];
					ptr[second][i]=ptr[first][i]-ptr[second][i];
					ptr[first][i]=ptr[first][i]-ptr[second][i];
				}
			} else if (col_row.compare("col") == 0)
			{
				for (int i=0; i<size_of_matrix; i++)
				{
					ptr[i][first]=ptr[i][first]+ptr[i][second];
					ptr[i][second]=ptr[i][first]-ptr[i][second];
					ptr[i][first]=ptr[i][first]-ptr[i][second];
				}
			} else
			{
				std::cout<<"Please enter 'row' or 'col'"<<std::endl;
			}
		}			
	}
};
int matrix_size_is()
{
	int size_of_matrix;
	do 
	{
		std::cout<<"Enter size of matrix: ";
		std::cin>>size_of_matrix;
		
	}
	while (size_of_matrix<4);
	
	return size_of_matrix;
}
int main()
{
	int size_of_matrix;
	size_of_matrix=matrix_size_is();
	MATRIX obj(size_of_matrix);
	obj.print_matrix();
	obj.transfer(1,3,"col");
	obj.print_matrix();
	obj.transfer(1,3,"row");
	obj.print_matrix();
	
	return 0;
}
