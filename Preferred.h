/*********************************************************
 * AUTHOR 			: Samuel Yeaw
 * STUDENT ID 		: 726729
 * Class Project	: Student
 * CLASS 			: CS1C
 * SECTION 			: TTh; 12:30 - 4:20
 * DUE DATE 		: 3/17/14
 *********************************************************/

#ifndef PREFERRED_H_
#define PREFERRED_H_

// PRE-PROCESSOR DIRECTIVES

#include "Basic.h"
using namespace std;

/**********************************************************
 * CLASS Preferred
 * --------------------------------------------------------
 * This class represents the preferred member of a super
 * warehouse. It stores and manipulates the information for
 * that user
 * --------------------------------------------------------
 * ATTRIBUTES:
 *	rebate		: The rebate amount
 *
 * METHODS:
 *
 ***********************************************************/

class Preferred: public Basic
{
private:
	/*ATTRIBUTES*/

	float rebate;	// The rebate amount

public:
	/*METHODS*/
	Preferred();
	~Preferred();

	// MUTATORS

	void SetRebate(float aRebate);

	// ACCESSORS

	float GetRebate()	const;
};

#endif /* PREFERRED_H_ */
