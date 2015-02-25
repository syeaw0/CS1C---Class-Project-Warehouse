

#include "Date.h"

Date::Date()
{
	day		= 0;
	month	= 0;
	year	= 0;
}

Date::~Date()
{

}

/**********************************************************
 * SetDate
 * --------------------------------------------------------
 * This member function sets the day, month, and year
 * of an object of this class
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	aDay		: The day to set the date to
 * 	aMonth		: The set month
 * 	aYear		: The year to set the date to
 *
 * POST-CONDITIONS:
 * 	<The day, month, and year are set>
 ***********************************************************/

void Date::SetDate(int aDay,		// The day to set to
			 	   int aMonth,		// The month to set to
			 	   int aYear)		// The year to set to
{
	day		= aDay;
	month	= aMonth;
	year	= aYear;
}

/**********************************************************
 * SetDay
 * --------------------------------------------------------
 * This member function sets the day of an object of this
 * class
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	aDay		: The day to set the date to
 *
 * POST-CONDITIONS:
 * 	<The day is set>
 ***********************************************************/

void Date::SetDay(int aDay)	// The day to set to
{
	day = aDay;
}

/**********************************************************
 * SetMonth
 * --------------------------------------------------------
 * This member function sets the month of an object of
 * this class
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	aMonth		: The set month
 *
 * POST-CONDITIONS:
 * 	<The month is set>
 ***********************************************************/

void Date::SetMonth(int aMonth)	// The month to set to
{
	month = aMonth;
}

/**********************************************************
 * SetYear
 * --------------------------------------------------------
 * This member function sets the year of an object of this
 * class
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	aYear		: The year to set the date to
 *
 * POST-CONDITIONS:
 * 	<The year is set>
 ***********************************************************/

void Date::SetYear(int aYear)	// The year to set to
{
	year = aYear;
}

/**********************************************************
 * Print
 * --------------------------------------------------------
 * This member function prints the date to the console
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	<None>
 *
 * POST-CONDITIONS:
 * 	<The date is printed to the console>
 ***********************************************************/

void Date::Print()const
{
	cout << month << '/' << day << '/' << year << endl;
}

