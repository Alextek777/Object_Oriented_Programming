#pragma once
#include "Functions.h"



void createData(std::string &FileName)
{
	srand(time(NULL));
	std::ofstream str;
	str.open(FileName, std::ios::out | std::ios::trunc);

	for (int i = 0; i < 100; i++)
		str << rand() % 101 - 50 << " ";
	str.close();
}

void createData(std::string& FileName, std::vector<int>& vec)
{
	std::generate(vec.begin(), vec.end(), []() {return rand() % 101 - 50; });
	std::ofstream out;
	out.open(FileName, std::ios::out | std::ios::trunc);

	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(out," "));
	out.close();
}







