/*********************************************************
 * AUTHOR 			: Samuel Yeaw
 * STUDENT ID 		: 726729
 * Class Project	: Student
 * CLASS 			: CS1C
 * SECTION 			: TTh; 12:30 - 4:20
 * DUE DATE 		: 3/17/14
 *********************************************************/

#include "Basic.h"

/**********************************************************
 * Constructor
 **********************************************************/
Basic::Basic()
{
	name.clear();
	id			= 0;
	totalSpent	= 0;
	type		= BASIC;
	next		= NULL;
}

/**********************************************************
 * Destructor
 **********************************************************/
Basic::~Basic()
{

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
void Basic::SetTotalSpent(float anAmount)	// Some amount
{
	totalSpent	= anAmount;
}

/**********************************************************
 * SetMemberType
 * --------------------------------------------------------
 * This member function sets the type of the member
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	aType		: The type of the member
 *
 * POST-CONDITIONS:
 * 	<The type of the member is set>
 **********************************************************/
void Basic::SetMemberType(MemberType aType)	// A member type (BASIC/PREFERRED)
{
	type	= aType;
}

/**********************************************************
 * SetNext
 * --------------------------------------------------------
 * This member function sets next member in the linked list
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	ptr		: Pointer to the next member
 *
 * POST-CONDITIONS:
 * 	<The pointer to the next member is set>
 **********************************************************/
void Basic::SetNext(Basic *ptr)	// Pointer to another member
{
	next	= ptr;
}

/**********************************************************
 * GetName
 * --------------------------------------------------------
 * This member function returns the member's name
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	<None>
 *
 * POST-CONDITIONS:
 * 	name	: The member's name
 **********************************************************/
string  	Basic::GetName()		const
{
	return name;
}

/**********************************************************
 * GetId
 * --------------------------------------------------------
 * This member function returns the member's id
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	<None>
 *
 * POST-CONDITIONS:
 * 	id	: The member's id
 **********************************************************/
int			Basic::GetId()			const
{
	return id;
}

/**********************************************************
 * GetExpiration
 * --------------------------------------------------------
 * This member function returns the member's expiration
 * date
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	<None>
 *
 * POST-CONDITIONS:
 * 	expiration	: The member's expiration date
 **********************************************************/
Date		Basic::GetExpiration()	const
{
	return expiration;
}

/**********************************************************
 * GetTotalSpent
 * --------------------------------------------------------
 * This member function returns total amount the member
 * spent
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	<None>
 *
 * POST-CONDITIONS:
 * 	totalSpent	: The total amount the member spent
 **********************************************************/
float		Basic::GetTotalSpent()	const
{
	return totalSpent;
}

/**********************************************************
 * GetMemberType
 * --------------------------------------------------------
 * This member function returns the member's type
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	<None>
 *
 * POST-CONDITIONS:
 * 	type	: The member's type (BASIC OR PREFERRED)
 **********************************************************/
MemberType 	Basic::GetMemberType()	const
{
	return type;
}

/**********************************************************
 * GetNext
 * --------------------------------------------------------
 * This member function returns a pointer to the next
 * member
 * --------------------------------------------------------
 * PRE-CONDITIONS:
 * 	<None>
 *
 * POST-CONDITIONS:
 * 	next	: A pointer to the next member
 **********************************************************/
Basic   	*Basic::GetNext()		const
{
	return next;
}

