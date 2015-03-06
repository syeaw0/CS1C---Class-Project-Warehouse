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

