/*************************************************
 * AUTHOR 		: Daniel Phan, Samuel Yeaw,
 * 				  Arman Jafarinia, Jacob McIver
 * STUDENT ID 	: 243390
 * Class Project	: Warehouse Class Project
 * CLASS 		: CS1C
 * SECTION 		: TTh 12:30PM - 4:20PM
 * DUE DATE 		: 3/17/15
 **************************************************/

#ifndef DATE_H_
#define DATE_H_

// PRE-PROCESSOR DIRECTIVES

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

/*********************************************************
 * CLASS Date
 * -------------------------------------------------------
 * This class represents the date. It has methods to
 * change and get the date
 * -------------------------------------------------------
 * ATTRIBUTES:
 * 	day		: The day
 * 	month	: The month
 * 	year	: The year
 *
 * METHODS:
 * 	SetDate
 * 	SetDay
 * 	SetMonth
 * 	SetYear
 * 	Print
 *********************************************************/

class Date
{
private:
	/*ATTRIBUTES*/

	int day;	// The day
	int month;	// The month
	int year;	// The year

public:
	/*METHODS*/

	Date();
	~Date();

	// MUTATORS

	void SetDate (ifstream& inFile);
	void SetDate (int aDay,
				  int aMonth,
				  int aYear);
	void SetDay  (int aDay);
	void SetMonth(int aMonth);
	void SetYear (int aYear);

	// ACCESSORS

	int GetDay() 	const;
	int GetMonth() 	const;
	int GetYear() 	const;
	bool CompareDate(Date aDate) const;
	void Print() 	const;
};

#endif /* DATE_H_ */
