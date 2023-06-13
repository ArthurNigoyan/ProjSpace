#include <iostream>
class car
{
	public:
		int weight;
		int height;
	// public:
	car(int w,int h)
	{
		if (w>0 && h>0)
		{
			weight=w;
			height=h;
		}
	}
	int type_of_car()
	{
		if (weight>1500 && height>120)
		{
			return 1;
		} else {
			return 0;
		}
	}
};
class parking
{
	private:
		const int max_number_of_cars=100;
	public:
		int count_of_Suvs;
		int count_of_sedans;
		int SUV_price;
		int sedan_price;
	
	parking(int cSUV,int price1, int csedan, int price2)
	{
		this->count_of_Suvs=cSUV;
		this->count_of_sedans=csedan;
		this->SUV_price=price1;
		this->sedan_price=price2;
	}
	
	void parking_reserve_check(int type_of_car)
	{
		if (count_of_Suvs+count_of_sedans>=max_number_of_cars)
		{
			std::cout<<"Parking spaces are over"<<std::endl;
		} else 
		{
			if (type_of_car == 1)
			{
				count_of_Suvs++;
			} else if (type_of_car == 0)
			{
				count_of_sedans++;
			}
		}
		std::cout<<"Count of SUV's is: "<<count_of_Suvs<<std::endl;
		std::cout<<"Count of sedans's is: "<<count_of_sedans<<std::endl;
		
	}
	void car_left(int type_of_car)
	{
		if (type_of_car == 1)
		{
			count_of_Suvs--;
		} else if (type_of_car == 0)
		{
			count_of_sedans--;
		}
		std::cout<<"After left count of SUV's is: "<<count_of_Suvs<<std::endl;
		std::cout<<"After left count of sedans's is: "<<count_of_sedans<<std::endl;
	}
	
};

int main ()
{
	car car1(1700,130);
	car car2(1100,110);
	
	parking Ppark(5,1000,3,500);
	Ppark.parking_reserve_check(car1.type_of_car());
	Ppark.parking_reserve_check(car2.type_of_car());
	Ppark.car_left(car2.type_of_car());
	
	
	
	return 0;
}