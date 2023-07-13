#include <iostream>

class ANIMAL
{
	public:
		int* m_ptr;
		int m_size;
	private:
		int m_weight;
		int m_sum_of_weights;
	public:
		
		ANIMAL(int animal_weight, int size) : m_weight{ animal_weight }, m_size {size}
		{
			m_sum_of_weights=m_weight;
			m_ptr = new int [m_size];
			for (int i = 0; i< m_size;i++)
			{
				m_ptr[i] = i;
			}
			std::cout<<"ANIMAL constructor"<<std::endl;
		}
		ANIMAL(ANIMAL &obj)
		{
			this->m_weight=obj.m_weight;
			this->m_sum_of_weights=obj.m_sum_of_weights;
			this->m_size=obj.m_size;
			this->m_ptr=new int[this->m_size];
			for (int i =0; i<obj.m_size;i++)
			{
				this->m_ptr[i]=obj.m_ptr[i];
			}
			std::cout<<"ANIMAL copy constructor"<<std::endl;
		}
		ANIMAL& operator=(ANIMAL& obj)
		{
			if (this==&obj)
			{
				return *this;
			}
			this->m_weight=obj.m_weight;
			this->m_sum_of_weights=obj.m_sum_of_weights;
			this->m_size=obj.m_size;
			this->m_ptr=new int[this->m_size];
			for (int i = 0; i< obj.m_size;i++)
			{
				this->m_ptr[i] = obj.m_ptr[i];
			}
			std::cout<<"ANIMAL operator assignment"<<std::endl;
			return *this;
		}
		ANIMAL(ANIMAL&& obj)
		{
			this->m_weight=obj.m_weight;
			this->m_sum_of_weights=obj.m_sum_of_weights;
			this->m_size=obj.m_size;
			this->m_ptr = obj.m_ptr;
			
			obj.m_ptr=nullptr;
			obj.m_size=0;
			obj.m_weight=0;
			obj.m_sum_of_weights=0;
			std::cout<<"ANIMAL move constructor"<<std::endl;
		}
		ANIMAL&& operator=(ANIMAL&& obj)
		{
			if (this==&obj)
			{
				return  std::move(*this);
			}
			delete []this->m_ptr;
			this->m_ptr=obj.m_ptr;
			this->m_size=obj.m_size;
			
			obj.m_ptr=nullptr;
			obj.m_size=0;
			this->m_weight=obj.m_weight;
			obj.m_weight=0;
			this->m_sum_of_weights=obj.m_sum_of_weights;
			obj.m_sum_of_weights=0;
			std::cout<<"ANIMAL move operator assignment"<<std::endl;
			return std::move(*this);
		}
		~ANIMAL()
		{
			delete []m_ptr;
			std::cout<<"ANIMAL destructor"<<std::endl;
		}
	friend bool operator> (const ANIMAL& a1, const ANIMAL& a2)
	{
		return a1.m_weight > a2.m_weight;
	}

	friend bool operator< (const ANIMAL& a1, const ANIMAL& a2)
	{
		return a1.m_weight < a2.m_weight;
	}
	
    int operator()(int animal_weight) {
      return m_sum_of_weights + animal_weight;
    }
};

int main ()
{
	
	ANIMAL pig(60,10);
	std::cout<<"step 1"<<std::endl;
	ANIMAL pig1 = std::move(pig);
	std::cout<<"step 2"<<std::endl;
	ANIMAL horse(120,20);
	std::cout<<"step 3"<<std::endl;
	ANIMAL horse1(110,20);
	std::cout<<"step4"<<std::endl;
	horse1=std::move(horse);
	std::cout<<"step5"<<std::endl;
	return 0;
}
