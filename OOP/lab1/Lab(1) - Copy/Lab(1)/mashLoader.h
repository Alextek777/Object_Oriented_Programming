#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include "dataType.h"

class Applicatation;

class mashloader
{
public:
	virtual bool loadmash(std::string &fileName) = 0;
	friend Applicatation;
};

class neuMashLoader : public mashloader
{
	std::vector<node> Nodes;
	std::vector<finiteElement> FiniteElements;
	std::vector<boundaryFiniteElement> BoundaryFiniteElements;
public:
	neuMashLoader() {}
	bool loadmash(std::string &fileName)override;																//Loads mash from .neu TXT file

	std::vector<finiteElement> GetFiniteElements();																//returns FiniteElements copy
	std::vector<boundaryFiniteElement> GetBoundaryFiniteElements();												//returns BoundaryFiniteElements copy

	void searchTrio(unsigned int n1, unsigned int n2, unsigned int n3, std::vector<finiteElement> &vec);		//find_it + pred     Finds every Tetrahedron with n1 n2 n3 Nodes included
	void searchDuo(unsigned int n1, unsigned int n2, std::vector<finiteElement> &vec);							//Finds every Tetrahedron with n1 n2 included
	void searchBoundaryNodes(unsigned int ID_bound, std::vector<node> &vec);									//Finds input boundary nodes
	void searchMat(unsigned int ID_mat, std::vector<finiteElement> &vec);										//Search FiniteElements by material
	void searchBoundaryTriangles(unsigned int ID_bound, std::vector<boundaryFiniteElement> &vec);				//search boundary tryangles using bound_ID
	void searchNeighbours(int n,std::vector<finiteElement>& vec);												//input N and it will show all neighbours of node number N


	bool addNode(unsigned int n1, unsigned int n2);																//add node between other 2 nodes


	void outputNodes();																							//Outputs Nodes
	void outputFiniteElements();																				//Outputs FiniteElements
	void outputBoundaryFiniteElements();																		//Outputs BoundaryFiniteElements


	void outputNodes(std::vector<node>&vec);																	//Outputs Nodes
	void outputFiniteElements(std::vector<finiteElement>& vec);													//Outputs FiniteElements
	void outputBoundaryFiniteElements(std::vector<boundaryFiniteElement>& vec);									//Outputs BoundaryFiniteElements


	//bool op(std::vector<finiteElement>::iterator& iter, unsigned int n1, unsigned int n2, unsigned int n3);				//pred
};



