#include "mashLoader.h"
#include <iomanip>
#include <algorithm>



bool neuMashLoader::loadmash(std::string &fileName)
{
	std::ifstream fin;
	std::string data;
	try
	{
		fin.open(fileName);
		if (!fin.is_open()) throw fileName;
		std::cout << "File : " << fileName << " successfully opened!" << std::endl;
	}
	catch (std::string closed_file)
	{
		std::cout << "Couldn`t open file : " << closed_file << std::endl;
		return false;
	}
	fin >> data;
	int dataInt = std::stoi(data);
	node buff_node;
	for (int i = 0; i < dataInt; i++)
	{
		buff_node.ID = i;
		fin >> data;
		buff_node.coordinates[0] = std::stof(data);
		fin >> data;
		buff_node.coordinates[1] = std::stof(data);
		fin >> data;
		buff_node.coordinates[2] = std::stof(data);
		Nodes.push_back(buff_node);
	}
	finiteElement buff_finiteElement;
	fin >> data;
	dataInt = std::atoi(data.c_str());
	int buff_int;

	for (int i = 0; i < dataInt; i++)
	{
		buff_finiteElement.ID = i;
		fin >> data;
		buff_finiteElement.ID_mat = std::atoi(data.c_str());
		fin >> data;
		buff_finiteElement.nodes[0] = std::atoi(data.c_str());
		fin >> data;
		buff_finiteElement.nodes[1] = std::atoi(data.c_str());
		fin >> data;
		buff_finiteElement.nodes[2] = std::atoi(data.c_str());
		fin >> data;
		buff_finiteElement.nodes[3] = std::atoi(data.c_str());
		FiniteElements.push_back(buff_finiteElement);
	}

	boundaryFiniteElement buff_boundaryfinityelement;

	fin >> data;
	dataInt = std::atoi(data.c_str());

	for (int i = 0; i < dataInt; i++)
	{
		buff_boundaryfinityelement.ID = i;
		fin >> data;
		buff_boundaryfinityelement.ID_bound = std::atoi(data.c_str());
		fin >> data;
		//Nodes[stoi(data)-1].flag = true;
		buff_boundaryfinityelement.nodes[0] = std::atoi(data.c_str());
		fin >> data;
		//Nodes[stoi(data)-1].flag = true;
		buff_boundaryfinityelement.nodes[1] = std::atoi(data.c_str());
		fin >> data;
		//Nodes[stoi(data)-1].flag = true;
		buff_boundaryfinityelement.nodes[2] = std::atoi(data.c_str());
		BoundaryFiniteElements.push_back(buff_boundaryfinityelement);
	}

	fin.close();
	return true;
}

std::vector<finiteElement> neuMashLoader::GetFiniteElements()
{
	return FiniteElements;
}

std::vector<boundaryFiniteElement> neuMashLoader::GetBoundaryFiniteElements()
{
	return BoundaryFiniteElements;
}



//                 OUTPUTSf

void neuMashLoader::outputNodes()
{
	std::cout << "Output Nodes : " << std::endl;
	std::cout << std::setw(5) << "ID" << std::setw(15) << "X" << std::setw(15) << "Y" << std::setw(15) << "Z" << std::setw(15)  << "Flag" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	for (int i = 0; i < Nodes.size(); i++)
	{
		//std::cout << Nodes[i];
		std::cout << std::setw(5) << Nodes[i].ID << std::setw(15) << Nodes[i].coordinates[0] << std::setw(15) << Nodes[i].coordinates[1] << std::setw(15) << Nodes[i].coordinates[2] << std::setw(15) << Nodes[i].flag << std::endl;
	}
}



void neuMashLoader::outputFiniteElements()
{
	std::cout << "Output Finite Elements : " << std::endl;
	std::cout << std::setw(5) << "ID" << std::setw(15) << "Material" << std::setw(15) << "N1" << std::setw(15) << "N2" << std::setw(15) << "N3" << std::setw(15) << "N4" << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < FiniteElements.size(); i++)
	{
		std::cout << std::setw(5) << FiniteElements[i].ID << std::setw(11) << FiniteElements[i].ID_mat << std::setw(19) << FiniteElements[i].nodes[0] << std::setw(15) << FiniteElements[i].nodes[1] << std::setw(15) << FiniteElements[i].nodes[2] << std::setw(15) << FiniteElements[i].nodes[3] << std::endl;
	}
}

void neuMashLoader::outputBoundaryFiniteElements()
{
	std::cout << "Output Boundary Finite Elements : " << std::endl;
	std::cout << std::setw(5) << "ID" << std::setw(15) << "Bound ID" << std::setw(15) << "N1" << std::setw(15) << "N2" << std::setw(15) << "N3" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	for (int i = 0; i < BoundaryFiniteElements.size(); i++)
	{
		std::cout << std::setw(5) << BoundaryFiniteElements[i].ID << std::setw(11) << BoundaryFiniteElements[i].ID_bound << std::setw(19) << BoundaryFiniteElements[i].nodes[0] << std::setw(15) << BoundaryFiniteElements[i].nodes[1] << std::setw(15) << BoundaryFiniteElements[i].nodes[2] << std::endl;
	}
}


void neuMashLoader::outputNodes(std::vector<node>& vec)
{
	std::cout << "Output Nodes : " << std::endl;
	std::cout << std::setw(5) << "ID" << std::setw(15) << "X" << std::setw(15) << "Y" << std::setw(15) << "Z" << std::setw(15) << "Flag" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << std::setw(5) << vec[i].ID << std::setw(15) << vec[i].coordinates[0] << std::setw(15) << vec[i].coordinates[1] << std::setw(15) << vec[i].coordinates[2] << std::setw(15) << vec[i].flag << std::endl;
	}
}



void neuMashLoader::outputFiniteElements(std::vector<finiteElement>& vec)
{
	std::cout << "Output Finite Elements : " << std::endl;
	std::cout << std::setw(5) << "ID" << std::setw(15) << "Material" << std::setw(15) << "N1" << std::setw(15) << "N2" << std::setw(15) << "N3" << std::setw(15) << "N4" << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << std::setw(5) << vec[i].ID << std::setw(11) << vec[i].ID_mat << std::setw(19) << vec[i].nodes[0] << std::setw(15) << vec[i].nodes[1] << std::setw(15) << vec[i].nodes[2] << std::setw(15) << vec[i].nodes[3] << std::endl;
	}
}



void neuMashLoader::outputBoundaryFiniteElements(std::vector<boundaryFiniteElement>& vec)
{
	std::cout << "Output Boundary Finite Elements : " << std::endl;
	std::cout << std::setw(5) << "ID" << std::setw(15) << "Bound ID" << std::setw(15) << "N1" << std::setw(15) << "N2" << std::setw(15) << "N3" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << std::setw(5) << vec[i].ID << std::setw(11) << vec[i].ID_bound << std::setw(19) << vec[i].nodes[0] << std::setw(15) << vec[i].nodes[1] << std::setw(15) << vec[i].nodes[2] << std::endl;
	}
}


//							SEARCH ALGORITHMS
/*
bool neuMashLoader::op(std::vector<finiteElement>::iterator& iter, unsigned int n1, unsigned int n2, unsigned int n3)
{
	bool flag1 = true, flag2 = true;
	if (iter->nodes[0] != n1 || iter->nodes[0] != n2 || iter->nodes[0] != n3)flag1 = false;
	if (iter->nodes[1] != n1 || iter->nodes[1] != n2 || iter->nodes[1] != n3)
	{
		if (flag1 == false)
			return false;
		else
			flag1 = false;
	}
	if (iter->nodes[2] != n1 || iter->nodes[2] != n2 || iter->nodes[2] != n3)
	{
		if (flag1 == false)
			return false;
		else
			flag1 = false;
	}
	if (iter->nodes[3] != n1 || iter->nodes[3] != n2 || iter->nodes[3] != n3)
	{
		if (flag1 == false)
			return false;
		else
			flag1 = false;
	}
	return true;
}
*/
auto pred = [](std::array<int, 7> &var)
{
	bool flag = false;
	if (var[0] == var[4] || var[0] == var[5] || var[0] == var[6]) flag = true;
	if (var[1] == var[4] || var[1] == var[5] || var[1] == var[6]) flag = true;
	if (var[2] == var[4] || var[2] == var[5] || var[2] == var[6]) flag = true;
	if (var[3] == var[4] || var[3] == var[5] || var[3] == var[6]) flag = true;
	return flag;
	/*
	bool flag1 = true, flag2 = true;
	if (iter->nodes[0] != n1 || iter->nodes[0] != n2 || iter->nodes[0] != n3)flag1 = false;
	if (iter->nodes[1] != n1 || iter->nodes[1] != n2 || iter->nodes[1] != n3)
	{
		if (flag1 == false)
			return false;
		else
			flag1 = false;
	}
	if (iter->nodes[2] != n1 || iter->nodes[2] != n2 || iter->nodes[2] != n3)
	{
		if (flag1 == false)
			return false;
		else
			flag1 = false;
	}
	if (iter->nodes[3] != n1 || iter->nodes[3] != n2 || iter->nodes[3] != n3)
	{
		if (flag1 == false)
			return false;
		else
			flag1 = false;
	}
	return true;*/
};

void neuMashLoader::searchTrio(unsigned int n1, unsigned int n2, unsigned int n3, std::vector<finiteElement> &vec)
{
	/*
	std::vector<finiteElement>::iterator iter = FiniteElements.begin();
	std::array<int, 7> var;
	while (iter != FiniteElements.end())
	{
		var = { iter->nodes[0],iter->nodes[1],iter->nodes[2],iter->nodes[3],int(n1),int(n2),int(n3) };
		iter = (std::find_if(iter, FiniteElements.end(), pred(var)));
		vec.push_back(*iter);
	}*/
	

	bool flag1, flag2;
	for (int i = 0; i < FiniteElements.size(); i++)
	{
		flag1 = false;
		flag2 = false;

		if (n1 == FiniteElements[i].nodes[0]) flag1 = true;			//find_if
		if (n1 == FiniteElements[i].nodes[1]) flag1 = true;
		if (n1 == FiniteElements[i].nodes[2]) flag1 = true;
		if (n1 == FiniteElements[i].nodes[3]) flag1 = true;

		if (flag1)
		{
			flag1 = false;
			if (n2 == FiniteElements[i].nodes[0]) flag1 = true;
			if (n2 == FiniteElements[i].nodes[1]) flag1 = true;
			if (n2 == FiniteElements[i].nodes[2]) flag1 = true;
			if (n2 == FiniteElements[i].nodes[3]) flag1 = true;

			if (flag1 == true)
			{
				flag1 = false;
				if (n3 == FiniteElements[i].nodes[0]) flag1 = true;
				if (n3 == FiniteElements[i].nodes[1]) flag1 = true;
				if (n3 == FiniteElements[i].nodes[2]) flag1 = true;
				if (n3 == FiniteElements[i].nodes[3]) flag1 = true;
			}

			if (flag1 == true) flag2 = true;
		}
		if (flag2 == true)
			vec.push_back(FiniteElements[i]);
			
	}
}





void neuMashLoader::searchDuo(unsigned int n1, unsigned int n2, std::vector<finiteElement> &vec)
{
	bool flag1;
	bool flag2;
	std::vector<finiteElement>::iterator iterBeg = FiniteElements.begin();
	while (iterBeg != FiniteElements.end())
	{
		iterBeg = std::find_if(iterBeg, FiniteElements.end(), [&](finiteElement fin) {return (fin.nodes[0] == n1 || fin.nodes[1] == n1 || fin.nodes[2] == n1 || fin.nodes[3] == n1); });
		if (iterBeg != FiniteElements.end())
		{
			if (iterBeg->nodes[0] == n2 || iterBeg->nodes[1] == n2 || iterBeg->nodes[2] == n2 || iterBeg->nodes[3] == n2)
			{

				vec.push_back(*iterBeg);
			}
			iterBeg++;
		}
	}

	
}


bool if_exists(const std::vector<node>& vec, const node &buff)
{
	std::vector<node>::const_iterator iter = vec.cbegin();
	iter = std::find_if(iter, vec.cend(), [&](node nd) {return nd == buff; });
	if (iter != vec.cend() && vec.size() != 0) return true;
	else return false;
}

void neuMashLoader::searchBoundaryNodes(unsigned int ID_bound, std::vector<node> &vec)
{
	std::vector<boundaryFiniteElement>::iterator iter = BoundaryFiniteElements.begin();
	std::vector<node>::iterator pos = vec.begin();
	node buff;
	while (iter != BoundaryFiniteElements.end())
	{
		iter = std::find_if(iter, BoundaryFiniteElements.end(), [&](boundaryFiniteElement data) {return data.ID_bound == ID_bound; });
		if (iter != BoundaryFiniteElements.end())
		{
			buff.flag = true;
			buff.ID = iter->nodes[0];
			buff.coordinates[0] = Nodes[iter->nodes[0]].coordinates[0];
			buff.coordinates[1] = Nodes[iter->nodes[0]].coordinates[1];
			buff.coordinates[2] = Nodes[iter->nodes[0]].coordinates[2];

			if (!if_exists(vec,buff))
			vec.push_back(buff);

			buff.ID = iter->nodes[1];
			buff.coordinates[0] = Nodes[iter->nodes[1]].coordinates[0];
			buff.coordinates[1] = Nodes[iter->nodes[1]].coordinates[1];
			buff.coordinates[2] = Nodes[iter->nodes[1]].coordinates[2];

			if (!if_exists(vec, buff))
			vec.push_back(buff);


			buff.ID = iter->nodes[2];
			buff.coordinates[0] = Nodes[iter->nodes[2]].coordinates[0];
			buff.coordinates[1] = Nodes[iter->nodes[2]].coordinates[1];
			buff.coordinates[2] = Nodes[iter->nodes[2]].coordinates[2];

			if (!if_exists(vec, buff))
			vec.push_back(buff);


			//vec.push_back(*iter);
			iter++;
		}
	}
}


void neuMashLoader::searchMat(unsigned int ID_mat, std::vector<finiteElement> &vec)
{
	std::vector<finiteElement>::iterator iter = FiniteElements.begin();
	while (iter != FiniteElements.end())
	{
		iter = std::find_if(iter, FiniteElements.end(), [&](finiteElement fin) {return fin.ID_mat == ID_mat; });
		if (iter != FiniteElements.end())
		{
			vec.push_back(*iter);
			iter++;
		}
	}
}


void neuMashLoader::searchBoundaryTriangles(unsigned int ID_bound, std::vector<boundaryFiniteElement> &vec)
{
	std::vector<boundaryFiniteElement>::iterator iter = BoundaryFiniteElements.begin();
	node buff;
	while (iter != BoundaryFiniteElements.end())
	{
		iter = std::find_if(iter, BoundaryFiniteElements.end(), [&](boundaryFiniteElement data) {return data.ID_bound == ID_bound; });
		if (iter != BoundaryFiniteElements.end())
		{
			vec.push_back(*iter);
			iter++;
		}
	}
}





void neuMashLoader::searchNeighbours(int n, std::vector<finiteElement>& vec)
{
	std::vector<finiteElement>::iterator iter = FiniteElements.begin();
	while (iter != FiniteElements.end())
	{
		iter = std::find_if(iter, FiniteElements.end(), [&](finiteElement fin) {return(fin.nodes[0] == n || fin.nodes[1] == n || fin.nodes[2] == n || fin.nodes[3] == n); });
		if (iter != FiniteElements.end())
		{
			vec.push_back(*iter);
			iter++;
		}
	}
}




bool neuMashLoader::addNode(unsigned int n1, unsigned int n2)					// add node
{
	std::vector<finiteElement> vec;
	searchDuo(n1, n2, vec);
	if(vec.size() == 0)
		{
		std::cout << "nodes : " << n1 << " and " << n2 << " are not neigbours, that means you can`t add node between them!" << std::endl;
		return false;
		}
	else
		{
		node newNode;

		newNode.coordinates[0] = (Nodes[n1].coordinates[0] + Nodes[n2].coordinates[0]) / 2;
		newNode.coordinates[1] = (Nodes[n1].coordinates[1] + Nodes[n2].coordinates[1]) / 2;
		newNode.coordinates[2] = (Nodes[n1].coordinates[2] + Nodes[n2].coordinates[2]) / 2;
		newNode.ID = Nodes.size();

		Nodes.push_back(newNode);
		std::cout << "node successfully has added " << std::endl;
		return true;
		}
}