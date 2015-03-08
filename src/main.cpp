
#include <iostream>
#include <fstream>
#include "Warehouse.h"
#include "Myheader.h"
using namespace std;


int main()
{
	ifstream 	memberInFile;
	ifstream	itemInFile;
	Warehouse	warehouse;
	Date		testDate;
	Basic   testMember;
	MemberList members;
	int choice;
	int search;

	itemInFile.open("day1.txt");
	memberInFile.open("warehouse shoppers.txt");

	warehouse.LoadMembers(memberInFile);
	warehouse.LoadItems(itemInFile);
	testDate.SetDate(1, 2, 2015);



	do
	{
		cout << MENU;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore(1000,'\n');
		cout << endl << endl;

		switch(choice)
		{
		case 1: 			warehouse.PrintSalesReport(testDate);
							break;

		case 2:				cout << "Enter the Id of the member you would"
									" like to search for: " << endl << endl;
							cin >> search;

							warehouse.PrintMemberPurchaseReport(testMember,search);
							break;

		case 3:				warehouse.PrintTotalSalesReport();
							break;
		case 4:
							break;

		case 5: 			warehouse.PrintRebateReport();
							break;

		case 6: 			warehouse.OutputMembers();
							break;

		case 7: 			warehouse.OutputInventory();
							break;
		}
	}while(choice != 0);



	memberInFile.close();
	itemInFile.close();

	return 0;
}
