#include "Application.h"
using namespace std;

void Application::start()
{
	string f_name;
	cout << "please enter name of the File" << endl;
	cin >> f_name;
	Firm myFirm(f_name);


	
	bool end = false;
	int command;


	while (!end)
	{
		system("cls");
		std::cout << "file input                - 1" << std::endl;
		std::cout << "add bill                  - 2" << std::endl;
		std::cout << "load data                 - 3" << std::endl;
		std::cout << "upload data               - 4 " << std::endl;
		std::cout << "find stuff                - 5" << std::endl;
		//std::cout << "convert from bin to txt   - 6" << std::endl;
		std::cout << "end                       - 0" << std::endl;
		std::cin >> command;

		bill data;
		unsigned int mod;
		std::string find_me;

		switch(command)
		{
		case 0:
			end = true;
			break;
		case 1:
			system("cls");
			if (!myFirm.file_input())
				std::cout << "error while working!" << std::endl;
			break;
		case 2:
			system("cls");
			//data = myNamespace::create_bill();
			myFirm.addBill(data);
			break;
		case 3:
			system("cls");
			std::cout << "enter mod: " << std::endl;			//mod1 - firm_name mod2-work_Type mod3 Date
			std::cout << "load by firm name    - 1" << std::endl; 
			std::cout << "load by work type    - 2" << std::endl;
			std::cout << "load by date         - 3" << std::endl;
			cin >> mod;
			if(!myFirm.load_data(mod))
				std::cout << "error while working!" << std::endl;
			break;
		case 4:
			system("cls");
			if(!myFirm.upload_data())
				std::cout << "error while working!" << std::endl;
			break;
		case 5:
			system("cls");
			std::cout << "enter what you want to find :" << std::endl;
			std::cin >> find_me;
			if(!myFirm.find_stuff(find_me))		// found elements are wrotten in file named "Search_stuff"
				std::cout << "error while working!" << std::endl;
			break;
		//case 6:

		//	break;
		default:
			end = true;
			break;
		}
	}
	


}