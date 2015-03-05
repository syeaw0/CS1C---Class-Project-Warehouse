/**************************************************************************
* AUTHOR        : Jacob Mc'Iver
* STUDENT ID    : 265933
* Assignment #  : Group Project
* CLASS         : MW 12:30pm - 4:20pm
* SECTION       : CS1C
* DUE DATE      : 3//2015
**************************************************************************/

#ifndef MEMBERLIST_H_
#define MEMBERLIST_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class MemberList
{
	public:

	/*METHODS*/

	MemberList();

	void AddMember();

	void DeleteMember(string deleteName);

	void PrintList();

	void GetFileName();

	MemberList SearchId(int userId);

	void  Output();



	private:

	 MemberList *head;

	 MemberList*curr;

	 MemberList*temp;


};


#endif /* MEMBERLIST_H_ */
