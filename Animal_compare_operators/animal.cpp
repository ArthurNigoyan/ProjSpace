#include <iostream>

class ANIMAL
{
	private:
		int weight;
		int sum_of_weights;
	public:
		
		ANIMAL(int animal_weight) : weight{ animal_weight }
		{
			sum_of_weights=weight;
		}
	
	friend bool operator> (const ANIMAL& a1, const ANIMAL& a2)
	{
		return a1.weight > a2.weight;
	}

	friend bool operator< (const ANIMAL& a1, const ANIMAL& a2)
	{
		return a1.weight < a2.weight;
	}
	
    int operator()(int animal_weight) {
      return sum_of_weights + animal_weight;
    }
};

int main ()
{
	ANIMAL pig{60};
	ANIMAL horse{250};
	if (horse > pig) 
	{
		std::cout<<"a horse is a greater than a pig"<<std::endl;
	}
	ANIMAL dog{15};
	ANIMAL cat{8};
	if (cat<dog) 
	{
		std::cout<<"a dog is a greater than a cat"<<std::endl;
	}
	int sum = cat(10);
	std::cout<<"8+10 ="<<sum;
	return 0;
}
