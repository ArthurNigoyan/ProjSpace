#include <iostream>
#include <vector>

class PERSON
{
	public:
		int salary;
		int age;
		std::string name;
		std::string surname;
		std::string date_of_bird;
	void set_info (int number)
	{
		std::cout<<"Enter client N"<<number<<" name: ";
		std::cin>>name;
		std::cout<<"Enter client N"<<number<<" surname: ";
		std::cin>>surname;
		std::cout<<"Enter client N"<<number<<" age: ";
		std::cin>>age;
		std::cout<<"Enter client N"<<number<<" salary: ";
		std::cin>>salary;
		std::cout<<"Enter client N"<<number<<" date of bird: ";
		std::cin>>date_of_bird;
	}
	
	void get_info()
	{
		std::cout<<"Client name is: "<<name<<std::endl;
		std::cout<<"Client surname is: "<<surname<<std::endl;
		std::cout<<"Client age is: "<<age<<std::endl;
		std::cout<<"Client date of bird is: "<<date_of_bird<<std::endl;
		std::cout<<"Client salary is: "<<salary<<std::endl;
	}
	
};

int main()
{
	int client_count;
	do 
	{
		std::cout<<"Enter clients counts: ";
		std::cin>>client_count;
	}
	while (client_count<1);
	PERSON obj[client_count];
	for (int j=0;j<client_count;j++)
	{	
		obj[j].set_info(j+1);
	}	
	for (int j=0;j<client_count;j++)
	{	
		obj[j].get_info();
	}
	
	
	return 0;
}