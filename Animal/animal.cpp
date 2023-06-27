#include <iostream>

class ANIMAL
{
	public:
		int body_size;
		int sound_of_animal;
		int tail_type;
		int size_of_tail;
		
	ANIMAL()
	{
		body_size=1;
		sound_of_animal=0;
		tail_type=0;
		size_of_tail=0;
		std::cout<<"Class ANIMAL"<<std::endl;
	}
	void set(int size, int sound, int tail)
	{
		this->body_size=size;
		this->sound_of_animal=sound;
		this->tail_type=tail;
	}
};

class land_animal : virtual public ANIMAL
// class land_animal :  public ANIMAL
{
	public:
		int count_of_legs;
		// int size_of_tail;
	land_animal()
	{
		count_of_legs=0;
		// size_of_tail=0;
		std::cout<<"Class land_animal"<<std::endl;
	}
	virtual void get()
	{
		std::cout<<"Class land_animal virtual function"<<std::endl;
	}
};

class water_animal : virtual public ANIMAL
// class water_animal :  public ANIMAL
{
	private:
		int count_of_legs=0;
		
	public:
	// int size_of_tail;
	water_animal()
	{
		// size_of_tail=1;
		std::cout<<"Class water_animal"<<std::endl;
	}
	virtual void get()
	{
		std::cout<<"Class water_animal virtual function"<<std::endl;
	}
};
class flying_animal : virtual public ANIMAL
{
	public:
		int wings=2;
	flying_animal()
	{
		std::cout<<"Class flying_animal"<<std::endl;
	}
};
class amphibian : virtual public water_animal, virtual public land_animal
// class amphibian :  public water_animal,  public land_animal
{
	public:
		amphibian()
		{
			std::cout<<"Class amphibian"<<std::endl;
		}
		virtual void get()
	{
		std::cout<<"Class amphibian virtual function"<<std::endl;
	}
	
};
int main ()
{
	// water_animal obj1;
	// std::cout<<"end of obj1"<<std::endl;
	// land_animal obj2;
	// std::cout<<"end of obj2"<<std::endl;
	// amphibian obj3;
	amphibian *ptr=new amphibian;
	// std::cout<<"body size "<<++ ptr->body_size<<" address "<<&ptr->body_size<<" "<<std::endl;
	// std::cout<<"body size "<<ptr->body_size<<" address "<<&ptr->water_animal::body_size<<std::endl;
	// std::cout<<"body size "<<ptr->body_size<<" address "<<&ptr->land_animal::body_size<<std::endl;
	// std::cout<<"size_of_tail "<<ptr->size_of_tail<<" address "<<&ptr->size_of_tail<<std::endl;
	// std::cout<<"size_of_tail "<<++ ptr->size_of_tail<<" address "<<&ptr->size_of_tail<<std::endl;
	// std::cout<<"size_of_tail "<<ptr->size_of_tail<<" address "<<&ptr->size_of_tail<<std::endl;
	
	// std::cout<<"end of obj3"<<std::endl;
	// flying_animal obj4;
	// std::cout<<"end of obj4"<<std::endl;
	return 0;
}