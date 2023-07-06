#include <iostream>
#include <string>
enum week {
		Monday = 1, 
		Tuesday = 2, 
		Wednesday = 3, 
		Thursday = 4, 
		Friday = 5, 
		Saturday = 6, 
		Sunday = 7
		};

class MLASS
{
	public:
	
		MLASS()
		{
			
		};
		~MLASS()
		{};
		int return_number_of_day(week obj)
		{
			switch(obj)
			{
				case Monday:
					return 1;
					break;
				case Tuesday:
					return 2;
					break;
				case Wednesday:
					return 3;
					break;
				case Thursday:
					return 4;
					break;
				case Friday:
					return 5;
					break;
				case Saturday:
					return 6;
					break;
				case Sunday:
					return 7;
					break;
			}
			return week::Monday;
		};
		std::string return_name_of_day(int number_of_day)
		{
			std::string s1;
			switch(number_of_day)
			{
				case week::Monday:
					s1="Monday";
					break;
				case week::Tuesday:
					s1="Tuesday";
					break;
				case week::Wednesday:
					s1="Wednesday";
					break;
				case week::Thursday:
					s1="Thursday";
					break;
				case week::Friday:
					s1="Friday";
					break;
				case week::Saturday:
					s1="Saturday";
					break;
				case week::Sunday:
					s1="Sunday";
					break;
				default:
					std::cout<<"please enter the number 1-7"<<std::endl;
			}
			return s1;
		};
};
int main ()
{
	MLASS day;
	std::cout<<day.return_number_of_day(Sunday)<<std::endl;
	std::cout<<day.return_name_of_day(5)<<std::endl;
	return 0;
}
