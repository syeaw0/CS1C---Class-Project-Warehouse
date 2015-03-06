/*************************************************
 * AUTHOR 		: Daniel Phan, Samuel Yeaw,
 * 				  Arman Jafarinia, Jacob McIver
 * STUDENT ID 	: 243390
 * Class Project	: Warehouse Class Project
 * CLASS 		: CS1C
 * SECTION 		: TTh 12:30PM - 4:20PM
 * DUE DATE 		: 3/17/15
 **************************************************/

#include "Warehouse.h"

/*************************************************
 * Default Constructor
 *************************************************/
Warehouse::Warehouse()
{

}

/*************************************************
 * Destructor
 *************************************************/
Warehouse::~Warehouse()
{

}

void Warehouse::LoadMembers(ifstream &inFile)
{
	members.CreateList(inFile);
}

void Warehouse::LoadItems(ifstream &inFile)
{
	inventory.ReadInFile(inFile);
}

void Warehouse::AddMember()
{
	// CONSTANT DECLARATIONS
	const int SPACING = 17;
	string name;
	int id;
	string expiration;

	cout << "You have chosen to create a new member.\n";
	cout << "Please enter the following information about the new member\n";

	cout << left;
	cout << setw(SPACING) << "NAME:";
	getline(cin, name);

	cout << setw(SPACING) << "ID:   ";
	cin >> id;

	cout << setw(SPACING) << "EXPIRATION DATE:" << "(mm/dd/yyyy)";
	getline(cin, expiration);

	// ERROR TESTING !!!!!!!!!!!!!!!!!

	cout << right;
}

/*************************************************
 * PrintSalesReport
 * -----------------------------------------------
 * This member function prints a sales report. It
 * searches for a date and outputs the information
 * associated with that date.
 * -----------------------------------------------
 * PRE-CONDITIONS:
 * 	aDate	: A date to search for
 *
 * POST-CONDITIONS:
 *  <Outputs a report with information associated
 *   with a particular date>
 *************************************************/
void Warehouse::PrintSalesReport(Date aDate)
{
	// CONSTANT DECLARATIONS
	const int TITLE = 32;
	const int ITEM = 10;
	const int QUANTITY = 10;
	const int COST = 10;
	const int BUYER = 10;
	const int NUMBERING = 4;

	// VARIABLE DECLARATIONS
	int index;
	int totalBasic;
	int totalPreferred;
	float totalRevenue;
	bool noItemsPurchased;
	Item* perPtr;
	Basic* aMember;

	// VARIABLE INITIALIZATION
	totalBasic = 0;
	totalPreferred = 0;
	totalRevenue = 0;

	// OUTPUT TITLE
	cout << left;
	cout << setprecision(2) << fixed;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* SALES REPORT FOR ";
	aDate.Print();
	cout << " *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

	// OUTPUT HEADING
	cout << setw(ITEM) << "ITEM";
	cout << setw(QUANTITY) << "QUANTITY";
	cout << setw(COST) << "COST";
	cout << setw(BUYER) << "BUYER";
	cout << endl;

	cout << setfill('-');
	cout << setw(ITEM) << '-' << ' ';
	cout << setw(QUANTITY) << '-' << ' ';
	cout << setw(COST) << '-' << ' ';
	cout << setw(BUYER) << '-';
	cout << setfill(' ');
	cout << endl;

	// OUTPUT LIST OF ITEMS BOUGHT
	index = 1;
	perPtr = inventory.GetHead();
	noItemsPurchased = true;

	while (perPtr != NULL)
	{
		if (aDate.CompareDate(perPtr->GetDatePurchased()))
		{
			cout << setw(NUMBERING) << index << '.';
			cout << setw(ITEM - NUMBERING) << perPtr->GetName();
			cout << setw(QUANTITY) << perPtr->GetQuantity();
			cout << setw(COST) << perPtr->GetPrice();

			aMember = members.SearchMember(perPtr->GetBuyerID());

			cout << setw(BUYER) << aMember->GetName();
			cout << endl;

			totalRevenue += (perPtr->GetQuantity() * perPtr->GetPrice());

			if (aMember->GetMemberType() == BASIC)
			{
				totalBasic++;
			}
			else
			{
				totalPreferred++;
			}

			noItemsPurchased = false;
		}

		perPtr = perPtr->GetNextItem();
		index++;
	}

	if (noItemsPurchased)
	{
		cout << "<No items were purchased on this date>\n";
	}

	cout << setfill('-');
	cout << setw(ITEM + QUANTITY + COST + BUYER) << '-';
	cout << endl << endl;

	cout << "TOTAL NUMBER OF MEMBERS\n";
	cout << setw(23) << '-' << endl;
	cout << setfill(' ');
	cout << endl;

	cout << "BASIC:     " << totalBasic << endl;
	cout << "PREFERRED: " << totalPreferred << endl;
	cout << endl;

	cout << "TOTAL REVENUE: $" << totalRevenue << endl;
	cout << endl << endl;

	cout << right;
}

void Warehouse::PrintMemberPurchaseReport(Basic aMember)
{
	// CONSTANT DECLARATIONS
	const int TITLE = 26;
	const int ITEM = 10;
	const int QUANTITY = 10;
	const int COST = 10;

	// VARIABLE DECLARATIONS
	int index;
	int totalPurchases;
	bool noItemsPurchased;
	Item* perPtr;

	// OUTPUT TITLE
	cout << left;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* MEMBER PURCHASE REPORT *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

	cout << "NAME: " << aMember.GetName();
	cout << "ID:   " << aMember.GetId();

	cout << setw(ITEM) << "ITEM";
	cout << setw(QUANTITY) << "QUANTITY";
	cout << setw(COST) << "COST";
	cout << endl;

	cout << setfill('-');
	cout << setw(ITEM) << '-' << ' ';
	cout << setw(QUANTITY) << '-' << ' ';
	cout << setw(COST) << '-';
	cout << endl;

	// Loop for Purchases
	index = 1;
	totalPurchases = 0;
	perPtr = inventory.GetHead();
	noItemsPurchased = true;

	while (perPtr != NULL)
	{
		if (perPtr->GetBuyerID() == aMember.GetId())
		{
			cout << index << ". ";
			cout << setw(ITEM - 4) << perPtr->GetName();
			cout << setw(QUANTITY) << perPtr->GetQuantity();
			cout << setw(COST) << perPtr->GetPrice();
			cout << endl;

			totalPurchases++;
			noItemsPurchased = false;
		}

		perPtr = perPtr->GetNextItem();
		index++;
	}

	if (noItemsPurchased)
	{
		cout << "<No items were puchased by this user>\n";
	}

	cout << setfill('-');
	cout << setw(ITEM + QUANTITY + COST) << '-';
	cout << setfill(' ');
	cout << endl << endl;

	cout << "TOTAL PURCHASES: ";
	cout << endl << endl;

	cout << right;
}

void Warehouse::PrintTotalSalesReport()
{
//EMPTY BLOCK, NEED MEMBERLIST HEAD TO SORT BY ID NUM
}
void Warehouse::PrintItemSalesReport(string itemToSearch)
{
	const int TITLE = 20;
	Item *ptr = NULL;
	int totalSold = 0;
	cout << left;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* ITEM SALES REPORT *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;
	ptr = inventory.GetHead();
	while (ptr != NULL)
	{
		if (ptr->GetName() == itemToSearch)
		{
			totalSold = totalSold + ptr->GetQuantity();
		}
		ptr->SetNextItem(ptr->GetNextItem());
	}
	ptr = inventory.SearchItem(itemToSearch);
	cout << setw(20 / 2) << ptr->GetName()
			<< (float(totalSold) * (ptr->GetPrice()));
}

void Warehouse::PrintMemberPaidPerYearReport()
{
	const int TITLE = 29;
	const int MEMBER_TYPE = 11;
	const int MEMBER_NAME = 10;
	const int TOTAL_SPENT = 10;

	Basic *perPtr;

	perPtr = members.GetHead();

	cout << left;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* MEMBER YEARLY AMOUNT PAID *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

	cout << setw(MEMBER_TYPE) << "MEMBER TYPE   ";
	cout << setw(MEMBER_NAME) << "MEMBER NAME  ";
	cout << setw(TOTAL_SPENT) << "TOTAL SPENT";
	cout << endl;

	cout << setfill('-');
	cout << setw(MEMBER_TYPE) << '-' << "   ";
	cout << setw(MEMBER_NAME) << '-' << "   ";
	cout << setw(TOTAL_SPENT) << '-';
	cout << endl;

	while (perPtr != NULL)
	{

		if (perPtr->GetMemberType() == BASIC)
		{
			cout << setw(MEMBER_TYPE) << "Basic";
		}
		else if (perPtr->GetMemberType() == PREFERRED)
		{
			cout << setw(MEMBER_TYPE) << "Preferred";
		}

		cout << setw(MEMBER_NAME) << perPtr->GetName();
		cout << setw(TOTAL_SPENT) << perPtr->GetTotalSpent();
		cout << endl;

		perPtr = perPtr->GetNext();
	}

	cout << right;

}

void Warehouse::PrintAmountDueByMonthReport(Date aDate)
{
	const int TITLE = 29;
	const int MONTH = 11;
	const int MEMBER_NAME = 10;
	const int AMOUNT_DUE = 10;

	Basic *perPtr = members.GetHead();

	cout << left;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* AMOUNT DUE AT THE END OF MONTH REPORT *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

	cout << setw(MONTH) << "MONTH   ";
	cout << setw(MEMBER_NAME) << "MEMBER NAME  ";
	cout << setw(AMOUNT_DUE) << "AMOUNT DUE";
	cout << endl;

	cout << setfill('-');
	cout << setw(MONTH) << '-' << "   ";
	cout << setw(MEMBER_NAME) << '-' << "   ";
	cout << setw(AMOUNT_DUE) << '-';
	cout << endl;

	while (perPtr != NULL)
	{
		if (aDate.GetMonth() == perPtr->GetExpiration().GetMonth())
		{
			cout << setw(MONTH) << aDate.GetMonth();
			cout << setw(MEMBER_NAME) << perPtr->GetName();
			if (perPtr->GetMemberType() == BASIC)
			{
				cout << setw(AMOUNT_DUE) << "$55.00";

			}
			else
			{
				cout << setw(AMOUNT_DUE) << "$95.00";
			}
			cout << endl;
		}

		perPtr = perPtr->GetNext();
	}

	cout << right;
}

