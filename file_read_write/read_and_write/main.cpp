#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>
#include<vector>

int main()
{
	std::vector<std::string> map;
	std::ifstream fout;
	fout.open("sample.txt");
	std::string line;
	while(std::getline(fout, line))
	{
	  if (line.find("Armenia ") != std::string::npos)
	  {  
		map.push_back(line); 
	  }
	}
	fout.close();
	std::ofstream fin;
	std::vector<std::string>::iterator IIt = map.begin();
	fin.open("sample1.txt");
	 while (IIt != map.end())
	 {
		 fin<<*IIt<<std::endl;
		 ++IIt;
	 }
	 fin.close();
	return 0;
}


