#pragma once
#include "mashLoader.h"
#include "Application.h"
#include <iomanip>

class Applicatation
{

	std::string file_name;
	neuMashLoader myneu;
public:
	Applicatation() {}
	~Applicatation() {}
	void start();
};



void Applicatation::start()
{
	std::cout << "Welcome! Enter file name which you want to open " << std::endl;
	std::cin >> file_name;

	if (!myneu.loadmash(file_name)) return;

	bool end = false;
	unsigned int mode;
	while (!end)
	{
		system("cls");
		std::cout << "now you can choose some options : " << std::endl;
		std::cout << "Find every Tetrahedron with n1 n2 n3 Nodes included" << std::setw(15) << "1" << std::endl;
		std::cout << "Find every Tetrahedron with n1 n2 included" << std::setw(24) << "2" << std::endl;
		std::cout << "Find input boundary nodes" << std::setw(41) << "3" << std::endl;
		std::cout << "Search FiniteElements by material" << std::setw(33) << "4" << std::endl;
		std::cout << "search boundary tryangles using bound_ID" << std::setw(26) << "5" << std::endl;
		std::cout << "input N and it will show all neighbours of node number N" << std::setw(10) << "6" << std::endl;
		std::cout << "add nodes between other 2 nodes " << std::setw(34) << "7" << std::endl;
		std::cout << "Outputs Nodes" << std::setw(53) << "8" << std::endl;
		std::cout << "Outputs FiniteElements" << std::setw(44) << "9" << std::endl;
		std::cout << "Outputs BoundaryFiniteElements" << std::setw(37) << "10" << std::endl;
		std::cout << "Clear Screen" << std::setw(55) << "11" << std::endl;
		std::cout << "End" << std::setw(64) << "12" << std::endl;

		std::cin >> mode;
		
		unsigned int n1, n2, n3, boundary;
		std::vector<finiteElement> vecf;
		std::vector<node> vecN;
		std::vector<boundaryFiniteElement> vecB;
		
		switch (mode)
		{
		case 11:
			system("cls");
			system("pause");
			break;
		case 1:
			system("cls");
			std::cout << "mode 1 is running..." << std::endl;
			std::cout << "please enter first node : ";
			std::cin >> n1;
			std::cout << "please enter second node : ";
			std::cin >> n2;
			std::cout << "please enter third node : ";
			std::cin >> n3;
			std::cout << std::endl;
			
			myneu.searchTrio(n1, n2, n3, vecf);

			if (vecf.size() != 0)		myneu.outputFiniteElements(vecf);
			else						std::cout << "couldn`t find any Tetrahedron with those nodes..." << std::endl << std::endl;

			system("pause");
			break;
		case 2:
			system("cls");
			std::cout << "mode 2 is running..." << std::endl;
			std::cout << "please enter first node : ";
			std::cin >> n1;
			std::cout << "please enter second node : ";
			std::cin >> n2;
			myneu.searchDuo(n1, n2, vecf);

			if (vecf.size() != 0) myneu.outputFiniteElements(vecf);
			else                 std::cout << "couldn`t find any Tetrahedron with those nodes..." << std::endl << std::endl;
			system("pause");
			break;
		case 3:
			system("cls");
			std::cout << "mode 3 is running..." << std::endl;
			std::cout << "please enter boundary : ";
			std::cin >> boundary;
			myneu.searchBoundaryNodes(boundary,vecN);

			if (vecN.size() != 0) myneu.outputNodes(vecN);
			else                 std::cout << "couldn`t find any BoundaryFiniteElement on that boundary" << std::endl;

			system("pause");
			break;
		case 4:
			system("cls");
			unsigned int mat;
			std::cout << "mode 4 is running..." << std::endl;
			std::cout << "please enter matherial : ";
			std::cin >> mat;
			myneu.searchMat(mat, vecf);

			if (vecf.size() != 0) myneu.outputFiniteElements(vecf);
			else                 std::cout << "couldn`t find any Tetrahedron made from that material" << std::endl;

			system("pause");
			break;
		case 5:
			system("cls");
			std::cout << "mode 5 is running..." << std::endl;
			std::cout << "please enter boundary : ";
			std::cin >> boundary;
			myneu.searchBoundaryTriangles(boundary, vecB);

			if (vecB.size() != 0) myneu.outputBoundaryFiniteElements(vecB);
			else                 std::cout << "couldn`t find any tryangles on that boundary" << std::endl;

			system("pause");
			break;
		case 6:
			system("cls");
			std::cout << "mode 6 is running..." << std::endl;
			std::cout << "please enter node : ";
			std::cin >> n1;
			myneu.searchNeighbours(n1,vecf);

			if (vecf.size() != 0) myneu.outputFiniteElements(vecf);
			else                 std::cout << "couldn`t find any neigbour" << std::endl;

			system("pause");
			break;
		case 7:
			system("cls");
			std::cout << "mode 7 is running..." << std::endl;
			std::cout << "please enter node 1 : ";
			std::cin >> n1;
			std::cout << "please enter node 2 : ";
			std::cin >> n2;
			myneu.addNode(n1, n2);


			system("pause");
			break;
		case 8:
			system("cls");
			std::cout << "mode 8 is running..." << std::endl;
			myneu.outputNodes();


			system("pause");
			break;
		case 9:
			system("cls");
			std::cout << "mode 9 is running..." << std::endl;
			myneu.outputFiniteElements();


			system("pause");
			break;
		case 10:
			system("cls");
			std::cout << "mode 10 is running..." << std::endl;
			myneu.outputBoundaryFiniteElements();


			system("pause");
			break;
		case 12:
			end = true;
			break;
		}
	}
	
	
}