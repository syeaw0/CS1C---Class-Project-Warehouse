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

	memberList :: memberList()
	{
		head = NULL;
		curr = NULL;
		temp = NULL;
	}

	void memberList :: AddMember()
	{
		memberInfo *memberPtr = new memberInfo;

		//CALC - assigns variables to struct members
		getline(inFile, memberPtr -> name);
		inFile >> memberPtr -> id;
		inFile.ignore(1000, '\n');
		getline(inFile, memberPtr -> membership);
		getline(inFile, memberPtr -> expiration);

		//CALC - links new node to stack
		memberPtr -> next = head;
		head = memberPtr;
		memberPtr = NULL;
	}

	void memberList :: DeleteMember(string deleteName)
	{
		// havent written yet
	}

	void memberList :: PrintList()
	{
		curr = head;

		while(curr != NULL)
		{
			cout << "Name: " << curr->name << endl;
			cout << "ID: " <<  curr->id << endl;
			cout << "Membership state: " << curr->membership << endl;
			cout << "Expiration date : ";
			cout << curr->expiration << endl << endl;
			curr = curr->next;
		}
	}


	void memberList :: GetFileName(string fileName)
	{
		inFile.open(fileName.c_str());
	}
