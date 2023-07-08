#include <iostream>
#include <string>


class MLASS
{
	public:
		enum week {
		Monday = 1, 
		Tuesday = 2, 
		Wednesday = 3, 
		Thursday = 4, 
		Friday = 5, 
		Saturday = 6, 
		Sunday = 7
		};
		MLASS()
		{
			
		};
		~MLASS()
		{};
		week return_number_of_day(week obj)
		{
			return obj;
		};
		std::string convert_To_enum(int number_of_day)
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
	MLASS::week a = day.week::Sunday;
	std::cout<<day.return_number_of_day(a)<<std::endl;
	MLASS::week b = day.week::Wednesday;
	std::cout<<a<<std::endl;
	
	std::cout<<day.convert_To_enum(b)<<std::endl;
	return 0;
}
