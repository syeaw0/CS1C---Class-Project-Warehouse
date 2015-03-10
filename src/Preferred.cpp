/*********************************************************
 * AUTHOR 			: Samuel Yeaw
 * STUDENT ID 		: 726729
 * Class Project	: Student
 * CLASS 			: CS1C
 * SECTION 			: TTh; 12:30 - 4:20
 * DUE DATE 		: 3/17/14
 *********************************************************/

#include "Preferred.h"

Preferred::Preferred()
{
	SetMemberType(PREFERRED);
	rebate	= 0.06;
}

Preferred::~Preferred()
{

}

void Preferred::SetRebate(float aRebate)
{
	rebate	= aRebate;
}

float Preferred::GetRebate()	const
{
	return rebate;
}


