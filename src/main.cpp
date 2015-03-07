
#include <iostream>
#include <fstream>
#include "Warehouse.h"
using namespace std;

int main()
{
	ifstream 	memberInFile;
	ifstream	itemInFile;
	Warehouse	warehouse;
	Date		testDate;

	memberInFile.open("day1.txt");
	itemInFile.open("warehouse shoppers.txt");

	warehouse.LoadMembers(memberInFile);
	warehouse.LoadItems(itemInFile);

	testDate.SetDate(1, 2, 2015);
	warehouse.PrintSalesReport(testDate);

	memberInFile.close();
	itemInFile.close();

	return 0;
}
