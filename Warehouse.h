/*************************************************
 * AUTHOR 		: Daniel Phan, Samuel Yeaw,
 * 				  Arman Jafarinia, Jacob McIver
 * STUDENT ID 	: 243390
 * Class Project	: Warehouse Class Project
 * CLASS 		: CS1C
 * SECTION 		: TTh 12:30PM - 4:20PM
 * DUE DATE 		: 3/17/15
 **************************************************/

#ifndef WAREHOUSE_H_
#define WAREHOUSE_H_

// PRE-PROCESSOR DIRECTIVES

#include <iostream>
#include <iomanip>
#include <fstream>
#include "MemberList.h"
#include "Inventory.h"
using namespace std;

/**************************************************
 * CLASS Warehouse
 * ------------------------------------------------
 * The Warehouse class manages the members and the
 * inventory and outputs different reports.
 * ------------------------------------------------
 * ATTRIBUTES:
 *
 * METHODS:
 **************************************************/
class Warehouse
{
private:
	/*ATTRIBUTES*/
	MemberList members;
	Inventory  inventory;

public:
	/*METHODS*/
	Warehouse();
	~Warehouse();

	// MUTATORS
	void LoadMembers(ifstream &inFile);
	void LoadItems(ifstream &inFile);
	void AddMember();

	// ACCESSORS
	void PrintSalesReport(Date aDate);
	void PrintMemberPurchaseReport(Basic aMember);
	void PrintTotalSalesReport();
	void PrintItemSalesReport(string itemToSearch);
	void PrintMemberPaidPerYearReport();
	void PrintAmountDueByMonthReport(Date aDate);
};

#endif /* WAREHOUSE_H_ */
