#include <iostream>
#include <stdlib.h>

template <typename T>
class MATRIX
{
	private:
		int size_of_matrix;
		T** ptr;
	public:
			
	MATRIX(int size):size_of_matrix(size)
	{
		
		ptr = new T*[size_of_matrix];
		for (int i = 0; i< size_of_matrix;i++)
		{
			ptr[i] = new T[size_of_matrix];
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
		this->ptr=new T*[this->size_of_matrix];
		for (int i = 0; i< obj.size_of_matrix;i++)
		{
			this->ptr[i] = new T[obj.size_of_matrix];
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
		this->ptr=new T*[this->size_of_matrix];
		for (int i = 0; i< obj.size_of_matrix;i++)
		{
			this->ptr[i] = new T[obj.size_of_matrix];
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
	
};

int main()
{
	int size_of_matrix = 10;
	MATRIX<int> obj(size_of_matrix);
	std::cout<<"step 1"<<std::endl;
	MATRIX<int> obj2 = std::move(obj);
	std::cout<<"step 2"<<std::endl;
	MATRIX<int> obj3(size_of_matrix);
	std::cout<<"step 3"<<std::endl;
	MATRIX<int> obj4(size_of_matrix);
	std::cout<<"step 4"<<std::endl;
	obj4=std::move(obj3);
	std::cout<<"step 5"<<std::endl;
	return 0;
}
