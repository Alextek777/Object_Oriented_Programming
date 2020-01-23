#pragma once
#include <array>
#include <iostream>
#include <iomanip>

struct node
{
	unsigned int ID;
	std::array<double,3> coordinates;
	//double x;
	//double y;
	//double z;
	bool flag = false;

	friend std::ostream& operator << (std::ofstream& p_out, const node& nd)
	{
		p_out << std::setw(5) << nd.ID << std::setw(15) << nd.coordinates[0] << std::setw(15) << nd.coordinates[1] << std::setw(15) << nd.coordinates[2] << std::setw(15) << nd.flag << std::endl;
	}

	bool operator==(node nd)
	{
		if (this->ID == nd.ID && this->flag == nd.flag && this->coordinates == nd.coordinates)
			return true;
		else return false;
	}

};

struct finiteElement
{
	unsigned int ID;
	unsigned int ID_mat;
	std::array<int,4> nodes;
	//int n1;
	//int n2;
	//int n3;
	//int n4;
};

struct boundaryFiniteElement
{
	unsigned int ID;
	unsigned int ID_bound;
	std::array<int,3> nodes;
	//int n1;
	//int n2;
	//int n3;
};