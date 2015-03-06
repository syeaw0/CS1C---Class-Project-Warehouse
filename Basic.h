/*********************************************************
 * AUTHOR 			: Samuel Yeaw
 * STUDENT ID 		: 726729
 * Class Project	: Student
 * CLASS 			: CS1C
 * SECTION 			: TTh; 12:30 - 4:20
 * DUE DATE 		: 3/17/14
 *********************************************************/

#ifndef BASIC_H_
#define BASIC_H_

// PRE-PROCESSOR DIRECTIVES

#include <fstream>
#include <string>
#include "Date.h"
using namespace std;

// USER DEFINED TYPES

enum MemberType
{
	BASIC,
	PREFERRED
};

/**********************************************************
 * CLASS Basic
 * --------------------------------------------------------
 * This class represents the basic member of a super
 * warehouse. It stores and manipulates the information for
 * that user
 * --------------------------------------------------------
 * ATTRIBUTES:
 * 	name		: The name of the member
 * 	id			: The ID of the member
 * 	expiration	: The expiration date of the member
 * 	totalSpent	: The total amount spent
 * 	next		: A pointer to the next member
 *
 * METHODS:
 * 	LoadMember
 * 	SetName
 * 	SetId
 * 	SetExpiration
 *	SetTotalSpent
 *	GetName
 *	GetId
 *	GetExpiration
 *	GetTotalSpent
 ***********************************************************/

class Basic
{
protected:
	/*ATTRIBUTES*/

	string 		name;		// The name of the member
	int    		id;			// The ID of the member
	Date		expiration;	// The expiration date of the member
	float		totalSpent;	// The total amount spent
	MemberType	type;		// The type of member
	Basic		*next;		// A pointer to the next member

public:
	/*METHODS*/

	Basic();
	~Basic();

	// MUTATORS

	void SetName(string aName);
	void SetId(int anId);
	void SetExpiration(Date aDate);
	void SetTotalSpent(float anAmount);
	void SetMemberType(MemberType aType);
	void SetNext(Basic *ptr);

	// ACCESSORS

	string  	GetName()		const;
	int			GetId()			const;
	Date		GetExpiration()	const;
	float		GetTotalSpent()	const;
	MemberType 	GetMemberType()	const;
	Basic   	*GetNext()		const;
};

#endif /* BASIC_H_ */
