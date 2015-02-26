

#ifndef DATE_H_
#define DATE_H_

// PRE-PROCESSOR DIRECTIVES

#include <iostream>
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

	void SetDate(int aDay,
				 int aMonth,
				 int aYear);
	void SetDay(int aDay);
	void SetMonth(int aMonth);
	void SetYear(int aYear);

	// ACCESSORS

	void Print()const;
};

#endif /* DATE_H_ */
