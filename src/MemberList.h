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
#include <string>
#include <fstream>
#include "Preferred.h"

using namespace std;

class MemberList
{
public:

	/*METHODS*/

	MemberList();
	~MemberList();

	// MUTATORS
	void AddMember();
	void DeleteMember(string deleteName);

	// ACCESSORS
	void PrintList()const;
	void GetFileName(string fileName)const;
	Basic* SearchMember(int anId)const;

private:
	struct memberInfo
	{
		string name;
		int id;
		string membership;
		string expiration;
		memberInfo *next;
	};

	memberInfo *head;
	memberInfo *curr;
	memberInfo *temp;
	string fileName;
	ifstream inFile;

};

#endif /* MEMBERLIST_H_ */
