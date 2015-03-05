	void Warehouse::PrintSalesReport(Item  items)
	{
		const int TITLE		= 32;
		const int NAME		= 10;
		const int QUANTITY	= 15;
		// VARIABLE DECLARATIONS
		int		index;
		string 	name;
		int		totalSold;
		items    *itemPtr;


		// VARIABLE INITIALIZATION
		totalSold = 0;

		// OUTPUT TITLE
		cout << left;
		cout << setfill('*');
		cout << setw(TITLE) 		<< '*'			 << endl;
		cout << "* Quantity of Items Sold ";
		cout << " *" 				<< endl;
		cout << setw(TITLE)			<< '*'			 << endl;
		cout << setfill(' ');
		cout << endl;

		// OUTPUT HEADING
		cout << setw(NAME)		<< "NAME";
		cout << setw(QUANTITY)	<< "  QUANTITY SOLD";
		cout << endl;

		cout << setfill('-');
		cout << setw(NAME)		<< '-'	<< ' ';
		cout << setw(QUANTITY)	<< '-'	<< ' ';
		cout << setfill(' ');

		while(itemPtr != NULL)
		{
			cout << itemPtr->
			cout << endl;
		}


	}

	void Warehouse::PrintSalesReport(preffered member)
	{
		const int TITLE		= 32;
		const int MEMBER	= 10;
		const int REBATE	= 15;
		// VARIABLE DECLARATIONS
		int		index;
		string 	Rebate;
		int		memberId;
		preffered   *memberPtr;


		// VARIABLE INITIALIZATION
		memberId = 0;

		// OUTPUT TITLE
		cout << left;
		cout << setfill('*');
		cout << setw(TITLE) 		<< '*'			 << endl;
		cout << "* Quantity of Items Sold ";
		cout << " *" 				<< endl;
		cout << setw(TITLE)			<< '*'			 << endl;
		cout << setfill(' ');
		cout << endl;

		// OUTPUT HEADING
		cout << setw(MEMBER)		<< "MEMBER ID";
		cout << setw(REBATE)	<< "  REBATE";
		cout << endl;

		cout << setfill('-');
		cout << setw(MEMBER)		<< '-'	<< ' ';
		cout << setw(REBATE)	<< '-'	<< ' ';
		cout << setfill(' ');

		while(memberPtr != NULL)
		{
			cout << memberPtr->name;
			cout << endl;
		}

	}
