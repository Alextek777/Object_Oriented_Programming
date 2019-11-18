#pragma once
#include <iostream>
#include <array>





typedef struct bill
{
	//std::array<std::string, 4> data;			//would be better if we make enumn
	float Price;
	float complited_work;
	std::string Firm_name;
	std::string Work_type;
	std::string Date;
	std::string Unit;

	friend std::ostream& operator << (std::ostream& p_out, const bill& p_bill)
	{
		p_out << p_bill.Price << " " << p_bill.complited_work << " " << p_bill.Firm_name << " " << p_bill.Work_type << " " << p_bill.Date << " " << p_bill.Unit << std::endl;
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
		this->Firm_name = "";
		this->Work_type = "";
		this->Date = "";
		this->Unit = "";
	}

	bool full()
	{
		return!(this->Price == NULL || this->complited_work == NULL || this->Firm_name.size() == 0 || this->Work_type.size() == 0 || this->Date.size() == 0 || this->Unit.size() == 0);
	}

	

};

//std::istream& bill::operator >> (std::istream& p_in, bill& p_bill);


