#pragma once
#include <iostream>
#include <array>
#include <iomanip>





typedef struct bill
{
	//std::array<std::string, 4> data;			//would be better if we make enumn
	float Price;
	float complited_work;
	char Firm_name[100];
	char Work_type[100];
	char Date[100];
	char Unit[100];

	friend std::ostream& operator << (std::ostream& p_out, const bill& p_bill)
	{
		p_out << std::setw(15) << p_bill.Price << std::setw(15) << p_bill.complited_work << std::setw(15) << p_bill.Firm_name << std::setw(15) << p_bill.Work_type << std::setw(15) << p_bill.Date << std::setw(15) << p_bill.Unit << std::endl;
		return p_out;
	}
	friend std::istream& operator >> (std::istream& p_in, bill& p_bill)
	{
		p_in >> p_bill.Price >> p_bill.complited_work >> p_bill.Firm_name >> p_bill.Work_type >> p_bill.Date >> p_bill.Unit;
		return p_in;
	}

	void set_null()
	{
		this->Price = NULL;
		this->complited_work = NULL;
		this->Firm_name[0] = '\0';
		this->Work_type[0] = '\0';
		this->Date[0] = '\0';
		this->Unit[0] = '\0';
	}

	bool full()
	{
		return!(this->Price == NULL || this->complited_work == NULL || this->Firm_name[0] == '\0' || this->Work_type[0] == '\0' || this->Date[0] == '\0' || this->Unit[0] == '\0');
	}

	

};

//std::istream& bill::operator >> (std::istream& p_in, bill& p_bill);


