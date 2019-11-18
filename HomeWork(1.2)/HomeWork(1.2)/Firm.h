#pragma once
#include "DataType.h"
#include <fstream>
#include <map>
#include <cstring>


class Application;

class Firm
{
private:
	std::map<std::string,bill> Data;		//if we ad multimap we can add infinite elements with same keys
	std::string FileName;
	friend Application;
	unsigned mod = 1;
public:
	Firm(std::string &FileName)
	{
		FileName += ".bin";
		this->FileName = FileName;
	}

	bool file_input();

	void addBill(bill &new_bill);

			//void writeFile(std::string &f_name, std::vector<bill> &data);

		/*	std::vector<bill> search_by_firmName(std::string &Firm_Name);
			std::vector<bill> search_by_workType(std::string &work_Type);
			std::vector<bill> search_by_date(std::string &date);*/

			//std::vector<bill>& get_data();
	bool load_data(unsigned &mod);



	bool upload_data();


	bool find_stuff(std::string &find_me);


	std::string& get_FileName();


	bool from_bin_to_txt();


};




