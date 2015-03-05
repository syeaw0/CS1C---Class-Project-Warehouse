/*
 * memberList.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: jmciver1
 */




/**************************************************************************
* AUTHOR        : Jacob Mc'Iver
* STUDENT ID    : 265933
* Assignment #  : Group Project
* CLASS         : MW 12:30pm - 4:20pm
* SECTION       : CS1C
* DUE DATE      : 3//2015
**************************************************************************/

#include "memberList.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

	MemberList :: MemberList()
	{
		head = NULL;
		curr = NULL;
		temp = NULL;
	}

	void MemberList :: AddMember()
	{
		MemberList *memberPtr = new MemberList;

		//CALC - assigns variables to struct members
		memberPtr -> name = SetName(aName);
		memberPtr -> id = SetId(anId);
		memberPtr -> membership = SetMemberType(aType);
		memberPtr -> expiration = SetExpiration(aDate);

		//CALC - links new node to stack
		memberPtr -> next = SetNext(*ptr);
		head = memberPtr;
		memberPtr = NULL;
	}

//	void memberList :: DeleteMember(memberInfo* head)
//	{
//
//		 memberInfo* memberPtr;
//		 memberPtr = head;
//
//		 if (head !=NULL )
//		 {
//			 memberPtr = memberPtr -> next;
//			 head = memberPtr;
//		 }
//
//		delete memberPtr;
//
//	}

	void MemberList :: PrintList()
	{
		memberPtr = head;

		while(curr != NULL)
		{
			cout << "Name: " << GetName() << endl;
			cout << "ID: " <<  GetId()<< endl;
			cout << "Membership state: " << GetMemberType() << endl;
			cout << "Expiration date : ";
			cout << GetExpiration() << endl << endl;
			memberPtr -> next = SetNext(*ptr);
		}
	}

	MemberList MemberList :: SearchId(int userId)
		{
			MemberList *memberPtr;
			bool found;

			found = false;
			memberPtr = head;

			while(memberPtr != NULL)
			{
				if(memberPtr->id == userId)
				{
					found = true;
				}
				else
				{
					memberPtr = memberPtr->next;
				}
			}

			return memberPtr;
		}


	void memberList :: Output()
	{

		cout << setw(30) << "Rebate Report" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "Name: " <<  50;
		cout << left << setw(10) << "Id: " << 20;

	}


