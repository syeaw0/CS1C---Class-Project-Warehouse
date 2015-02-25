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

using namespace std;

class memberList
{
	public:

	/*METHODS*/

	memberList();

	string SetName(string addName);

	int SetId(int addName);

	string SetMembership(string addMemberShip);

	string SetExpiration(string addExpiration);


	void AddMember(string addName, int addId, string addMembership,
					string addExpiration);

	void DeleteMember(string deleteName);

	void PrintList();

	void GetFileName();



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


};


#endif /* MEMBERLIST_H_ */
