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
void Warehouse::PrintSalesReport(Date aDate) //OBJECTIVE 1
{
	// CONSTANT DECLARATIONS
	const int TITLE = 31;
	const int ITEM = 26;
	const int QUANTITY = 10;
	const int COST = 10;
	const int BUYER = 10;

	// VARIABLE DECLARATIONS
	int index;
	int totalBasic;
	int totalPreferred;
	float totalRevenue;
	bool noItemsPurchased;
	Basic* aMember;
	Item* itemPtr;
	Date datePtr;


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
	cout << setw(ITEM + 1) << "ITEM";
	cout << setw(QUANTITY + 1) << "QUANTITY";
	cout << setw(COST + 1) << "COST";
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
	itemPtr = inventory.GetHead();
	noItemsPurchased = true;

	while (itemPtr != NULL)
	{
		if(index < 10)
		{
			cout << index << ".  ";
		}
		else
		{
			cout << index << ". ";
		}
		cout << setw(ITEM - 3) << itemPtr->GetName();
		cout << setw(QUANTITY + 1) << itemPtr->GetQuantity();
		cout << '$';
		cout << setw(COST) << itemPtr->GetPrice();

		aMember	= members.SearchMember(itemPtr->GetBuyerID());
		cout << aMember->GetName();

		itemPtr = itemPtr->GetNextItem();
		cout << endl;
		index++;
	}

	cout << setfill('-');
	cout << setw(ITEM + QUANTITY + COST + BUYER) << '-';
	cout << endl << endl;

	cout << "TOTAL NUMBER OF MEMBERS\n";
	cout << setw(23) << '-' << endl;
	cout << setfill(' ');
	cout << endl;

	aMember = members.GetHead();
	while(aMember != NULL)
	{
	if(aMember->GetMemberType() == 0)
	{
		totalBasic++;
	}
	else
	{
		totalPreferred++;
	}
	aMember = aMember->GetNext();
	}

	cout << "BASIC:     " << totalBasic << endl;
	cout << "PREFERRED: " << totalPreferred << endl;
	cout << endl;

	cout << "TOTAL REVENUE: $" << totalRevenue << endl;
	cout << endl << endl;

	cout << right;
}
//Output All Members (Non-objective)
void Warehouse :: OutputMembers()
{
	Basic *memberPtr;
	//Date datePtr;

	memberPtr = members.GetHead();

	while(memberPtr != NULL)
	{
	cout << "NAME: " <<  memberPtr->GetName() << endl;
	cout << "ID:   " << memberPtr->GetId() << endl;
	//cout << "Expiration: " << datePtr.GetDay() << endl;
	cout << "Membership   ";
	if(memberPtr->GetMemberType() == 0)
	{
		cout << "BASIC";
	}
	else
	{
		cout << "PREFERRED";
	}
	cout << endl << endl;
	memberPtr = memberPtr->GetNext();
	}

}
//Outputs Entire Item list from Inventory (Non-objective)
void Warehouse :: OutputInventory()
{
	Item* itemPtr;
	//Date datePtr;

	itemPtr = inventory.GetHead();

	while(itemPtr != NULL)
	{
		cout << "ITEM NAME: " <<  itemPtr->GetName() << endl;
		cout << "SHOPPER ID:   " << itemPtr->GetBuyerID() << endl;
		cout << "COST:   " << itemPtr->GetPrice() << endl;
		cout << "QUANTITY:   " << itemPtr->GetQuantity() << endl;

		cout << endl << endl;
		itemPtr = itemPtr->GetNextItem();
	}

}
//OBJECTIVE 2
void Warehouse::PrintMemberPurchaseReport(Basic aMember, int search)
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
	bool memberFound;
	Item* perPtr;
	Basic *memberPtr;

	// OUTPUT TITLE
	cout << left;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* MEMBER PURCHASE REPORT *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

	// MEMBER INITIALIZATIONS
	memberPtr = members.GetHead();
	memberFound = false;

	while(memberPtr!=NULL && !memberFound)
	{
		if(memberPtr->GetId() == search)
		{
			memberFound = true;
		}
		else
		{
			memberPtr = memberPtr->GetNext();
		}
	}
	cout << "NAME: " << memberPtr->GetName();;
	cout << "ID:   " << memberPtr->GetId();

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
		if (perPtr->GetBuyerID() == memberPtr->GetId())
		{
			cout << index << ". " << endl;
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

//OBJECTIVE 3
void Warehouse::PrintTotalSalesReport()
{
	Basic *memberPtr;
	Item *perPtr;
	Date datePtr;

	memberPtr = members.GetHead();

	while(memberPtr != NULL)
	{
		perPtr = inventory.GetHead();
		cout << "   ID # " << memberPtr->GetId() << " PURCHASED:" << endl;
		cout << "----------------------------------" << endl;

		while (perPtr != NULL)
		{
			if (perPtr->GetBuyerID() == memberPtr->GetId())
			{
				cout << "ITEM NAME: " << perPtr->GetName();
				cout << endl;
			}

			perPtr = perPtr->GetNextItem();
		}
		memberPtr = memberPtr->GetNext();
		cout << endl;
	}

}
//OBJECTIVE 4
void Warehouse::PrintItemSalesReport(string itemToSearch)
{
	const int TITLE = 21;
	Item *itemPtr = NULL;
	int totalSold = 0;
	bool itemFound;

	cout << left;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* ITEM SALES REPORT *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

	itemPtr = inventory.GetHead();
	itemFound = false;

	while(itemPtr!=NULL && !itemFound)
	{
		if(itemPtr->GetName() == itemToSearch)
		{
			itemFound = true;
		}
		else
		{
			itemPtr = itemPtr->GetNextItem();
		}
	}
	cout << setw(20 / 2) << itemPtr->GetName();
	cout <<  "QUANTITY SOLD: " << itemPtr->GetQuantity() << endl;
	cout <<	 "TOTAL SALES: "
	<< (float(itemPtr->GetQuantity()) * (itemPtr->GetPrice()))
	<< endl << endl;
}


//OBJECTIVE 7
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
//OBJECTIVE 8
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

//OBJECTIVE 6
void Warehouse::PrintRebateReport()
{
	Basic *memberPtr;
	Date datePtr;

	cout << "=====================================" << endl <<
			"	Rebate Report" << endl <<
			"=====================================" << endl;
	memberPtr = members.GetHead();
	while(memberPtr != NULL)
	{
		if(memberPtr->GetMemberType() == PREFERRED)
		{
			cout << "ID:   " << memberPtr->GetId() << "	REBATE:" << endl;
			cout << "";
		}
		memberPtr = memberPtr->GetNext();
	}
	cout << endl;
}

void Warehouse::PrintItemsSold()
{
	Item *itemPtr;
	Date datePtr;

	cout << "=====================================" << endl <<
			"	Items Sold" << endl <<
			"=====================================" << endl;
	itemPtr = inventory.GetHead();
	while(itemPtr != NULL)
	{
			cout << "ITEM NAME:   " << itemPtr->GetName();
			cout  << "Quantity: " << itemPtr->GetQuantity() << endl;

		itemPtr = itemPtr->GetNextItem();
	}
	cout << endl;
}

void Warehouse::PrintMembershipDues()
{
	Basic *memberPtr;
	Date datePtr;

	memberPtr = members.GetHead();

	cout << "=====================================" << endl <<
	"	MEMBERSHIP DUES\n" << endl <<
	"=====================================" << endl;

	while(memberPtr != NULL)
	{
		if(memberPtr->GetMemberType() == PREFERRED)
		{
			cout << "MEMBER TYPE: PREFERRED" << endl;
			cout << "NAME: " << memberPtr->GetName() << endl;
			cout << "MEMBERSHIP DUES: $" << 95.00; // NEED to edit this still
			cout << endl << endl;

		}

		memberPtr = memberPtr->GetNext();
	}

	memberPtr = members.GetHead();

	while(memberPtr != NULL)
	{
		if(memberPtr->GetMemberType() == BASIC)
		{
			cout << "MEMBER TYPE: BASIC" << endl;
			cout << "NAME: " << memberPtr->GetName() << endl;
			cout << "MEMBERSHIP DUES: $" << 55.00; // NEED to edit this still
			cout << endl << endl;

		}
		memberPtr = memberPtr->GetNext();
	}
	cout << endl << endl;
}

