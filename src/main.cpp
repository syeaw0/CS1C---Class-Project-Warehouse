
#include <iostream>
#include <fstream>
#include "Warehouse.h"
using namespace std;

int main()
{
	ifstream 	memberInFile;
	ifstream	itemInFile;
	Warehouse	warehouse;

	memberInFile.open("day1.txt");
	itemInFile.open("warehouse shoppers.txt");

	memberInFile.close();
	itemInFile.close();

	return 0;
}
