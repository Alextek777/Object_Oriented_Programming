#pragma once
#include <fstream>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iterator>
#include <math.h>

void createData(std::string &FileName); //1.1

void createData(std::string& FileName,std::vector<int> &vec); //1.2


template<typename contType>
bool loadDataFile(contType& cont, std::string& fileName)		//2.1
{
	std::ifstream str;
	str.open(fileName, std::ios::out | std::ios::app);
	if (!str.is_open())
	{
		std::cout << "failed opening file!" << std::endl;
		return false;
	}

	typename contType::value_type dataT;

	while (!str.eof())
	{
		str >> dataT;
		cont.push_back(dataT);
	}
	cont.pop_back();
	str.close();
	return true;
}


template<typename contType>
bool loadDataIterator(contType& cont, std::string& fileName)		//2.2
{
	std::ifstream fin;
	
	fin.open(fileName, std::ios::in);
	if(!fin.is_open())
	{
		std::cout << "couldn`t open file : " << fileName << std::endl;
		return false;
	}
	std::copy( std::istream_iterator<typename contType::value_type>(fin) , std::istream_iterator<typename contType::value_type>()  ,std::inserter(cont,cont.end()) );
	fin.close();
	return true;
}




template<typename contType>
void modify(contType& cont)	//3.1 #17
{
	typename contType::value_type max;
	typename contType::value_type sum = 0;
	max = *cont.begin();

	for (auto it = cont.begin(); it != cont.end(); ++it)
	{
		if (max < *it)	max = *it;
	}

	for(auto it = cont.begin(); it != cont.end(); ++it)
	{
		if (*it > 0) *it = max;
		sum += abs(*it);
	}
	cont.push_back(sum / cont.size());
	cont.push_back(sum);

}


template<typename iterType>
void modify(iterType beg,iterType end)	//3.2 #17
{
	typename iterType::value_type max = *beg;
	for (auto it = beg; it != end; it++)
	{
		if (max < *it)	max = *it;
	}

	for (auto it = beg; it != end; it++)
	{
		if (*it > 0) *it = max;
	}

}



template<typename iterType>
void modify_each(iterType beg,iterType end)	//3.3 #17
{
	typename iterType::value_type max = *beg;
	for (auto it = beg; it != end; it++)
	{
		if (max < *it)	max = *it;
	}

	std::for_each(beg, end, [=](typename iterType::value_type& current) {if (current > 0) current = max; });
}


template<typename contType>
void outputResultStream(contType& cont,std::string fileName)
{
	std::ofstream fout;
	fout.open(fileName, std::ios::out | std::ios::app);
	if (!fout.is_open())
	{
		std::cout << "couldn`t open file!" << std::endl;
		return;
	}
	typename contType::iterator iter = cont.begin();
	while (iter != cont.end())
	{
		fout << *iter;
		++iter;
	}
	fout.close();
}

template<typename contType>
void outputResultIterators(contType& cont, std::string fileName)
{
	std::ofstream fout;
	fout.open(fileName, std::ios::out | std::ios::app);
	if (!fout.is_open())
	{
		std::cout << "couldn`t open file!" << std::endl;
		return;
	}
	std::copy(cont.begin(), cont.end(), std::ostream_iterator<typename contType::value_type>(fout," "));
	fout.close();
}

