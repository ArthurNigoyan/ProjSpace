#include <iostream>
#include <stdlib.h>
#include <fstream>

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
class MATRIX
{
	private:
		int size_of_matrix;
		int** ptr;
	public:
			
	
	MATRIX();
	MATRIX(int size)
	{
		if (size<4)
		{
			size_of_matrix=matrix_size_is();
		} else
		{
			size_of_matrix=size;
		}
		
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
		std::cout<<"MATRIX constructor"<<std::endl;
	}
	MATRIX(MATRIX &obj)
	{
		this->size_of_matrix=obj.size_of_matrix;
		this->ptr=new int*[this->size_of_matrix];
		for (int i = 0; i< obj.size_of_matrix;i++)
		{
			this->ptr[i] = new int[obj.size_of_matrix];
		}
		for(int i=0; i<obj.size_of_matrix;i++)
		{
			for(int j=0; j<obj.size_of_matrix;j++)
			{
				this->ptr[i][j]=obj.ptr[i][j];
			}
		}
		std::cout<<"MATRIX copy constructor"<<std::endl;
		
	}
	MATRIX& operator=(MATRIX& obj)
	{
		if (this==&obj)
		{
			return *this;
		}
		for (int i = 0; i< size_of_matrix;i++)
		{
			delete []ptr[i];
		}
		delete []ptr;
		this->size_of_matrix=obj.size_of_matrix;
		this->ptr=new int*[this->size_of_matrix];
		for (int i = 0; i< obj.size_of_matrix;i++)
		{
			this->ptr[i] = new int[obj.size_of_matrix];
		}
		for(int i=0; i<obj.size_of_matrix;i++)
		{
			for(int j=0; j<obj.size_of_matrix;j++)
			{
				this->ptr[i][j]=obj.ptr[i][j];
			}
		}
		std::cout<<"operator assignment"<<std::endl;
		return *this;
	}
	MATRIX(MATRIX&& obj)
	{
		this->size_of_matrix=obj.size_of_matrix;
		this->ptr=obj.ptr;
		
		for (int i = 0; i< obj.size_of_matrix;i++)
		{
			obj.ptr[i] = nullptr;
		}
		obj.ptr= nullptr;
		obj.size_of_matrix =0;
		std::cout<<"MATRIX move constructor"<<std::endl;
		
	}
	MATRIX&& operator=(MATRIX&& obj)
	{
		if (this==&obj)
		{
			return std::move(*this);
		}
		for (int i = 0; i< this->size_of_matrix;i++)
		{
			delete []ptr[i];
		}
		delete []ptr;
		this->size_of_matrix=obj.size_of_matrix;
		this->ptr=obj.ptr;
		for (int i = 0; i< obj.size_of_matrix;i++)
		{
			obj.ptr[i] = nullptr;
		}
		obj.ptr= nullptr;
		obj.size_of_matrix =0;
		std::cout<<"MATRIX move operator assignment"<<std::endl;
		return std::move(*this);
	}
	~MATRIX()
	{
		for (int i = 0; i< size_of_matrix;i++)
		{
			delete []ptr[i];
		}
		delete []ptr;
		std::cout<<"MATRIX destructor"<<std::endl;
	}
	void print_matrix()
	{
		std::ofstream fin;
		fin.open("matrix.txt");
		for (int i=0; i<size_of_matrix;i++)
		{
			for (int j=0;j<size_of_matrix;j++)
			{
				std::cout<<ptr[i][j]<<" ";
				fin<<ptr[i][j]<<" ";
			}
			std::cout<<std::endl;
			fin<<std::endl;
		}
		std::cout<<std::endl;
		fin<<std::endl;
		fin.close();
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

int main()
{
	int size_of_matrix;
	size_of_matrix=matrix_size_is();
	MATRIX obj(size_of_matrix);
	obj.print_matrix();
	
	return 0;
}

