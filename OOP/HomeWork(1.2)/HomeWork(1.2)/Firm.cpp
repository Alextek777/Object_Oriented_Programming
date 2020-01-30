#include "Firm.h"
#include <vector>
#include <iomanip>
/*
void Firm::addBill(bill &new_bill)
{
	Data.push_back(new_bill);
}


std::vector<bill> search(std::string &fname, std::string &name, int mode)	// 0 - Firm_name 1 - Work_type 2 - Date
{
	std::ifstream str;
	bill buff;
	std::vector<bill> vec;

	str.open(fname, std::ios::binary | std::ios::in | std::ios::app);//| std::ios::trunc -- | std::ios::app it will not delete file content
	if (!str.is_open())
	{
		std::cout << "File is not opened!" << std::endl;
		return vec;
	}

	std::cout << "File is opened!" << std::endl; 

	str.seekg(0,std::ios::end);
	int size = str.tellg();
	str.seekg(0, std::ios::beg);


	while (str.tellg() < size)

	{
		str.read((char*)& buff.data[0], sizeof(buff.data[0]));
		str.read((char*)& buff.data[1], sizeof(buff.data[0]));
		str.read((char*)& buff.data[2], sizeof(buff.data[0]));
		str.read((char*)& buff.data[3], sizeof(buff.data[0]));
		str.read((char*)& buff.Price, sizeof(buff.Price));
		str.read((char*)& buff.complited_work, sizeof(buff.complited_work));

		if(buff.data[mode] == name)
		vec.push_back(buff);
	}
	str.close();
	return vec;
}


std::vector<bill> Firm::search_by_firmName(std::string& Firm_Name)
{
	std::vector<bill>vec = search(FileName, Firm_Name, 0);
	writeFile(Firm_Name, vec);
	return vec;
}
std::vector<bill> Firm::search_by_workType(std::string& work_Type)
{
	std::vector<bill>vec = search(FileName, work_Type, 1);
	writeFile(work_Type, vec);
	return vec;
}
std::vector<bill> Firm::search_by_date(std::string& date)
{
	std::vector<bill>vec = search(FileName, date, 2);
	writeFile(date, vec);
	return vec;
}


void Firm::writeFile(std::string& f_name, std::vector<bill>& data)
{
	std::ofstream of(f_name, std::ios::out | std::ios::app);

	for (int i = 0; i < Data.size(); i++)
	{
		of.write((char*)& Data[i].data[0], sizeof(std::string));
		of.write((char*)& Data[i].data[1], sizeof(std::string));
		of.write((char*)& Data[i].data[2], sizeof(std::string));
		of.write((char*)& Data[i].data[3], sizeof(std::string));
		of.write((char*)& Data[i].Price, sizeof(float));
		of.write((char*)& Data[i].complited_work, sizeof(float));
	}
	of.close();
}


std::vector<bill>& Firm::get_data()
{
	return Data;
}

std::string& Firm::get_FileName()
{
	return FileName;
}
*/





namespace myNamespace
{
	bill create_bill()
	{
		bill data;

		std::cout << "enter price(num)" << std::endl;
		scanf_s("%f", &data.Price);
		std::cout << "enter complited work(num)" << std::endl;
		scanf_s("%f", &data.complited_work);
		std::cout << "enter Firm name" << std::endl;
		std::cin >> data.Firm_name;
		std::cout << "enter Work type" << std::endl;
		std::cin >> data.Work_type;
		std::cout << "enter Date" << std::endl;
		std::cin >> data.Date;
		std::cout << "enter Unit" << std::endl;
		std::cin >> data.Unit;

		if (!data.full())
			exit(EXIT_FAILURE);

		return data;
	}
}





//первичная Запись Bill в файл 
bool Firm::file_input()
{
	bool flag = true;
	bill data;
	std::string sdata;
	std::ofstream fout;


		fout.open(FileName, std::ios::binary | std::ios::trunc);	//trunc -> app (delete/not delete)
		if (fout.is_open())
			std::cout << "File successfully opened!" << std::endl;
		else
		{
			std::cout << "Error while trying to open file!" << std::endl;
			return false;
		}
		std::string command;

	//std::string::size_type sz;
	while(flag)
	{
		//std::cout << "enter price(num)" << std::endl;
		//scanf_s("%f", &data.Price);
		//std::cout << "enter complited work(num)" << std::endl;
		//scanf_s("%f", &data.complited_work);
		//std::cout << "enter Firm name" << std::endl;
		//std::cin >> data.Firm_name;
		//std::cout << "enter Work type" << std::endl;
		//std::cin >> data.Work_type;
		//std::cout << "enter Date" << std::endl;
		//std::cin >> data.Date;
		//std::cout << "enter Unit" << std::endl;
		//std::cin >> data.Unit;
		std::cout << "if you want to add bill enter add else enter end" << std::endl;
		std::cin >> command;
		if (command == "end")
			flag = false;
		else
		{
			data = myNamespace::create_bill();
			//fout << data;

			fout.write(reinterpret_cast<const char*>(&data), sizeof(data));

			data.set_null();
		}

		//if (!data.full())
		//{
		//	std::cout << "Not full data entered!!!" << std::endl;
		//	flag = false;
		//}
		//else
		//{
		//	fout << data;		//output/read with read and write
		//}

	}
	fout.close();
	return true;
}



bool Firm::load_data(unsigned &mod)	//mod1 - firm_name mod2-work_Type mod3 Date
{
	this->mod = mod;
	std::ifstream fin;
	bool flag = true;
	bill data;
	std::pair<std::string, bill> myPair;


	fin.open(this->FileName, std::ios::binary | std::ios::in | std::ios::app);
	if (fin.is_open())
		std::cout << "file successfully opened!" << std::endl;
	else
	{
		std::cout << "Error while trying to open file!" << std::endl;
		return false;
	}
	do
	{
		data.set_null();
		std::string key;
		fin >> data;
		switch (mod)
		{
		case 1:
			key = data.Firm_name;
			break;
		case 2:
			key = data.Work_type;
			break;
		case 3:
			key = data.Date;
			break;
		default:
			key = data.Firm_name;
			break;
		}
		if (!data.full()) flag = false;
		else
		{
			myPair = std::make_pair(key,data);
			this->Data.emplace(myPair);
		}

	} while (flag);
	return true;
}

void Firm::addBill(bill& new_bill)
{
	std::string key;
	std::pair<std::string,bill> mypair;
	switch (mod)
	{
	case 1:
		key = new_bill.Firm_name;
		break;
	case 2:
		new_bill.Work_type;
		break;
	case 3:
		new_bill.Date;
		break;
	default:
		new_bill.Firm_name;
		break;
	}
	mypair = std::make_pair(key, new_bill);
	this->Data.emplace(mypair);
}


bool Firm::upload_data()
{
	std::ofstream fout;
	fout.open(FileName, std::ios::binary | std::ios::in | std::ios::trunc);
	if (fout.is_open())
		std::cout << "file successfully opened!" << std::endl;
	else
	{
		std::cout << "Error while trying to open file!" << std::endl;
		return false;
	}
	for (auto beg = Data.cbegin(); beg != Data.cend(); beg++)
	{
		fout << beg->second;
	}
}

bool Firm::find_stuff(std::string &find_me)
{
	std::ofstream fout;
	fout.open("Search_stuff", std::ios::binary | std::ios::in | std::ios::app);
	if (fout.is_open())
		std::cout << "file successfully opened! " << std::endl;
	else
	{
		std::cout << "Error while trying to open file!" << std::endl;
		return false;
	}
	auto f = Data.find(find_me);
	if (f != Data.end())
	{
		std::cout << f->second;
		fout << f->second;
	}
	else
		std::cout << "couldn`t find that element!!!";
	return true;
}






bool Firm::from_bin_to_txt()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open(FileName, std::ios::binary | std::ios::app);
	fout.open("converted.txt", std::ios::trunc);

	if (fin.is_open() && fout.is_open())
		std::cout << "files succesfully opened!" << std::endl;
	else
	{
		std::cout << "error while opening files!" << std::endl;
		return false;
	}



	fin.seekg(0, std::ios::end);
	const int length = fin.tellg();
	fin.seekg(0, std::ios::beg);

	bill buff;
	std::vector<bill> vec;
	vec.reserve(100);
	while (fin.tellg() < length)

	{
		fin.read(reinterpret_cast<char*>(&buff), sizeof(buff));
		if (buff.full())
			vec.push_back(buff);

		//fin.read((char*)& buff.Price, sizeof(buff.Price));
		//fin.read((char*)& buff.complited_work, sizeof(buff.complited_work));
		//fin.read((char*)& buff.Firm_name, sizeof(buff.Firm_name));
		//fin.read((char*)& buff.Work_type, sizeof(buff.Work_type));
		//fin.read((char*)& buff.Date, sizeof(buff.Date));
		//fin.read((char*)& buff.Unit, sizeof(buff.Unit));

		//if (buff.full())
		//	vec.push_back(buff);
	}
	fin.close();
	fout << std::setw(15) << "Price" << std::setw(15) << "Complited Work" << std::setw(15) << "Firm name" << std::setw(15) << "Work Type" << std::setw(15) << "Date" << std::setw(15) << "Unit" << std::endl;
	for (auto it = vec.begin(); it != vec.end(); it++)
		fout << *it;

	fout.close();
	return true;
}







