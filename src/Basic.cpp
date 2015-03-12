/*********************************************************
 * AUTHOR 			: Samuel Yeaw
 * STUDENT ID 		: 726729
 * Class Project	: Student
 * CLASS 			: CS1C
 * SECTION 			: TTh; 12:30 - 4:20
 * DUE DATE 		: 3/17/14
 *********************************************************/

#include "Basic.h"

Basic::Basic()
{
	static int _index	= 0;
	_index++;
	cout << _index << " members added\n\n";

	name.clear();
	id			= 0;
	totalSpent	= 0;
	type		= BASIC;
	next		= NULL;
}

Basic::~Basic()
{
	static int _2index	= 0;
	_2index++;
	cout << _2index << " members deleted\n\n";
}

/**********************************************************
 * SetName
 * --------------------------------------------------------
 * This member function sets the name of the member
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	aName		: The name of the member
 *
 * POST-CONDITIONS:
 * 	<The name of the member is set>
 **********************************************************/

void Basic::SetName(string aName)	// The name of the member
{
	name = aName;
}

/**********************************************************
 * SetId
 * --------------------------------------------------------
 * This member function sets the ID of the member
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	id		: The ID of the member
 *
 * POST-CONDITIONS:
 * 	<The ID of the member is set>
 **********************************************************/

void Basic::SetId(int anId)		// The ID of the member
{
	id = anId;
}

/**********************************************************
 * SetExpiration
 * --------------------------------------------------------
 * This member function sets the expiration of the member
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	aDate		: The date of the expiration
 *
 * POST-CONDITIONS:
 * 	<The date of the expiration is set>
 **********************************************************/

void Basic::SetExpiration(Date aDate)	// The date of the expiration
{
	expiration	= aDate;
}

/**********************************************************
 * SetTotalSpent
 * --------------------------------------------------------
 * This member function sets the total purchases of the
 * member
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	anAmount		: The amount of the total purchases
 *
 * POST-CONDITIONS:
 * 	<The amount of the total purchases is set>
 **********************************************************/

void Basic::SetTotalSpent(float anAmount)
{
	totalSpent	= anAmount;
}

void Basic::SetMemberType(MemberType aType)
{
	type	= aType;
}

void Basic::SetNext(Basic *ptr)
{
	next	= ptr;
}

string  	Basic::GetName()		const
{
	return name;
}

int			Basic::GetId()			const
{
	return id;
}
Date		Basic::GetExpiration()	const
{
	return expiration;
}

float		Basic::GetTotalSpent()	const
{
	return totalSpent;
}

MemberType 	Basic::GetMemberType()	const
{
	return type;
}

Basic   	*Basic::GetNext()		const
{
	return next;
}

