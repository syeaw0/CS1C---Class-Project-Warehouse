/*************************************************
* AUTHOR 		: Daniel Phan, Samuel Yeaw,
* 				  Arman Jafarinia, Jacob McIver
* STUDENT ID 	: 243390
* Class Project	: Warehouse Class Project
* CLASS 		: CS1C
* SECTION 		: TTh 12:30PM - 4:20PM
* DUE DATE 		: 3/17/15
**************************************************/

#include "Date.h"
#include <limits>

Date::Date()
{
	day		= 0;
	month	= 0;
	year	= 0;
}

Date::~Date()
{

}

void Date::SetDate(ifstream& inFile)
{
	int aDay;
	int aMonth;
	int aYear;

	inFile >> aMonth;
	inFile.ignore(numeric_limits<streamsize>::max(), '/');

	inFile >> aDay;
	inFile.ignore(numeric_limits<streamsize>::max(), '/');

	inFile >> aYear;
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');


	day		= aDay;
	month	= aMonth;
	year	= aYear;
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

int	 Date::GetDay()	const
{
	return day;
}

int	 Date::GetMonth()	const
{
	return month;
}

int  Date::GetYear()	const
{
	return year;
}

bool Date::CompareDate(Date aDate)	const
{
	bool equal;

	equal = day 	== aDate.GetDay()
		  && month 	== aDate.GetMonth()
		  && year 	== aDate.GetYear();

	return equal;
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

void Date::Print(ostream &output)const
{
	if(month < 10)
	{
		output << '0' << month;
	}
	else
	{
		output << month;
	}

	output << '/';

	if(day < 10)
	{
		output << '0' << day;
	}
	else
	{
		output << day;
	}

	output << '/';

	output << year;
}

