#include "Functions.h"
#include <vector>

void main()
{
	std::string stk = "newFIle.txt";
	createData(stk);
	std::vector<int> vec;
	std::vector<int> vec1;
	std::vector<int> vec2;
	vec.resize(50);
	createData(stk,vec);
	loadDataFile(vec1, stk);
	std::vector<int>::iterator beg = vec1.begin();
	std::vector<int>::iterator end = vec1.end();
	modify_each(beg,end);
	outputResultIterators(vec1, "eddited_file.txt");
	system("pause");
	return;
}