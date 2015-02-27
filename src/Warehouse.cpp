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
	const int TITLE		= 28;
	const int ITEM		= 10;
	const int QUANTITY	= 10;
	const int COST		= 10;
	const int BUYER		= 10;
	const int NUMBERING	= 4;

	// VARIABLE DECLARATIONS
	int		index;
	bool	noItemsPurchased;
	Item*	perPtr;
	Basic*	aMember;

	// OUTPUT TITLE
	cout << left;
	cout << setprecision(2)		<< fixed;
	cout << setfill('-');
	cout << setw(TITLE) 		<< '-'			 << endl;
	cout << "SALES REPORT FOR " << aDate.Print() << endl;
	cout << setw(TITLE)			<< '-'			 << endl	<< endl;

	// OUTPUT HEADING
	cout << setw(ITEM)		<< "ITEM";
	cout << setw(QUANTITY)	<< "QUANTITY";
	cout << setw(COST)		<< "COST";
	cout << setw(BUYER)		<< "BUYER";
	cout << endl;

	cout << setfill('-');
	cout << setw(ITEM)		<< '-'	<< ' ';
	cout << setw(QUANTITY)	<< '-'	<< ' ';
	cout << setw(COST)		<< '-'	<< ' ';
	cout << setw(BUYER)		<< '-';
	cout << setfill(' ');
	cout << endl;

	// OUTPUT LIST OF ITEMS BOUGHT
	index				= 1;
	perPtr				= inventory.GetHead();
	noItemsPurchased	= true;

	while(perPtr != NULL)
	{
		if(perPtr->GetDatePurchased() == aDate)
		{
			cout << setw(NUMBERING)			<< index << '.';
			cout << setw(ITEM - NUMBERING)	<< perPtr->GetName();
			cout << setw(QUANTITY)			<< perPtr->GetQuantity;
			cout << setw(COST)				<< perPtr->GetPrice();

			aMember	= members.SearchMember(perPtr->GetBuyerID());

			cout << setw(BUYER)				<< aMember->GetName();
			cout << endl;

			noItemsPurchased	= false;
		}
		else
		{
			perPtr	= perPtr->GetNextItem();
			index++;
		}
	}

	cout << setfill('-');
	cout << setw(ITEM + QUANTITY + COST + BUYER)	<< '-';
	cout << setfill(' ');
	cout << endl << endl;



	cout << right;
}

