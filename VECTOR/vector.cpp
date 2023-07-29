#include <iostream>

template <typename T>
class vectorclass
{
	private:
		int m_size;
		T* m_ptr;
		int capacity;
	public:
	vectorclass()
	{
		
		m_ptr = new T[1];
		m_size=0;
		capacity = 1;
		std::cout<<"vectorclass constructor"<<std::endl;
	}
	vectorclass(vectorclass &obj)
	{
		this->m_size=obj.m_size;
		this->m_ptr=new T[m_size];
		for (int i=0;i<m_size;i++)
		{
			this->m_ptr[i] = obj.m_ptr[i];
		}
		std::cout<<"vectorclass copy constructor"<<std::endl;
	}
	vectorclass& operator=(vectorclass& obj)
	{
		if (this==&obj)
		{
			return *this;
		}
		delete []m_ptr;
		this->m_size=obj.m_size;
		this->m_ptr=new int[m_size];
		for (int i=0;i<m_size;i++)
		{
			this->m_ptr[i] = obj.m_ptr[i];
		}
		std::cout<<"operator assignment for vectorclass"<<std::endl;
		return *this;
	}
	vectorclass(vectorclass&& obj)
	{
		this->m_size=obj.m_size;
		this->m_ptr=obj.m_ptr;
		obj.m_ptr=nullptr;
		obj.m_size = 0;
		std::cout<<"vectorclass move constructor"<<std::endl;
	}
	vectorclass&& operator=(vectorclass&& obj)
	{
		if (this==&obj)
		{
			return std::move(*this);
		}
		delete []m_ptr;
		this->m_size=obj.m_size;
		this->m_ptr=obj.m_ptr;
		obj.m_ptr=nullptr;
		obj.m_size = 0;
		std::cout<<"vectorclass move operator assignment"<<std::endl;
		return std::move(*this);
	}
	~vectorclass()
	{
		delete []m_ptr;
		std::cout<<"vectorclass destructor"<<std::endl;
	}
	 void print()
    {
        for (int i = 0; i < m_size; i++) {
            std::cout << m_ptr[i] << " ";
        }
        std::cout << std::endl;
    }
	void push_back(T need_add)
	{
		if (m_size==capacity) {
			 T* m_ptr1 = new T[2*capacity];
			for (int i = 0; i < this->capacity; i++) {
				m_ptr1[i] = m_ptr[i];
			}
			delete[] m_ptr;
			this->m_ptr = m_ptr1;
			capacity*=2;
		}
		// this->m_size++;
        this->m_ptr[this->m_size] = need_add;
		m_size++;
	}
	void pop_back()
	{
		T* m_ptr1 = new T[this->m_size-1];
        for (int i = 0; i < this->m_size-1; i++) {
			m_ptr1[i] = m_ptr[i];
        }
        delete[] m_ptr;
        this->m_ptr = m_ptr1;
		this->m_size--;
        
	}
	T* begin ()
	{
		T* mm1_ptr=m_ptr;
		
		return mm1_ptr;
	}
	T* end ()
	{
		T* mm2_ptr=m_ptr;
		mm2_ptr+=m_size;
		return mm2_ptr;
	}
	int size ()
	{
		return m_size;
	}
	int vectorclasscapacity ()
	{
		return capacity;
	}
	void erase(int index)
	{
		if (index <= capacity) {
			if (index <= m_size)
			{
				T* m_ptr1 = new T[capacity];
				int j=0;
				for (int i = 0; i < m_size; i++) {
					
					if (i==index)
					{
						j=i+1;
					} 
					m_ptr1[i] = m_ptr[j];
					j++;
				}
				delete[] m_ptr;
				this->m_ptr = m_ptr1;
				this->m_size--;
			}
		}
	}
	void erase(int firstindex, int secondindex)
	{
		if (firstindex<=secondindex) {
			if ((firstindex<secondindex) && (secondindex<=m_size))
			{
				T* m_ptr1 = new T[capacity];
				int j=0;
				for (int i = 0; i < m_size; i++) {
					
					if (i==firstindex)
					{
						j=i+(secondindex-firstindex);
					} 
					m_ptr1[i] = m_ptr[j];
					j++;
				}
				delete[] m_ptr;
				this->m_ptr = m_ptr1;
				this->m_size-=secondindex-firstindex;
			}
		}
		
	}
	bool empty()
	{
		if (m_size==0)
		{
			return true;
		} else {
			return false;
		}
	}
	
};

int main()
{
	vectorclass<int> a;
	a.push_back(5);
	// a.print();
	a.push_back(9);
	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.print();
	std::cout<<"first element is: "<<a.begin()<<" last index is: "<<a.end()<<" vector size is: "<<a.size()<<std::endl;
	std::cout<<"capacity is: "<<a.vectorclasscapacity()<<std::endl;
	a.erase(2);
	std::cout<<"after erase"<<std::endl;
	a.print();
	a.push_back(44);
	a.push_back(45);
	a.push_back(46);
	a.push_back(47);
	a.print();
	a.erase(2,5);
	std::cout<<"after erase with range"<<std::endl;
	a.print();
	std::cout<<a.empty()<<std::endl;
	for (auto it = a.begin(); it != a.end(); ++it)
        std::cout << ' ' << *it;
	std::cout<<std::endl;
	return 0;
}