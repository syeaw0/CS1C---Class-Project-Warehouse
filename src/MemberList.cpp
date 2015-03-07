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

MemberList::MemberList()
{
	head = NULL;
}

MemberList::~MemberList()
{

}

void MemberList::CreateList(ifstream &inFile)
{
	// VARIABLE DECLARATIONS
	Basic*	memberPtr;
	string 	name;
	int		id;
	string  memberType;
	Date	expiration;

	// Loop
	do
	{
		getline(inFile, name);
		inFile >> id;
		inFile.ignore(1000, '\n');
		getline(inFile, memberType);
		expiration.SetDate(inFile);

		if(memberType == "Basic")
		{
			memberPtr	= new Basic;
		}
		else
		{
			memberPtr	= new Preferred;
		}

		if(memberPtr != NULL)
		{
			memberPtr->SetName(name);
			memberPtr->SetId(id);
			memberPtr->SetExpiration(expiration);

			memberPtr->SetNext(head);
			head	= memberPtr;
		}
	}while(inFile && memberPtr != NULL);
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

Basic *MemberList::SearchMember(int userId) const
{
	Basic *memberPtr;
	bool found;

	found = false;
	memberPtr = head;

	while (memberPtr != NULL && !found)
	{
		if (memberPtr->GetId() == userId)
		{
			found = true;
		}
		else
		{
			memberPtr = memberPtr->GetNext();
		}
	}

	return memberPtr;
}

Basic *MemberList::GetHead() const
{
	return head;
}

