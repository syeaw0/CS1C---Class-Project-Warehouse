/*************************************************************************
 * AUTHOR     		 : Arman Jafarinia
 * STUDENT ID 		 : 912488
 * Assignment #2         : student
 * CLASS      		 : CS 1C
 * SECTION    		 : T Th 12:00-1:50
 * DUE DATE   		 :
 * ***********************************************************************/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "c_Item.h"

class Inventory
{
public:
	/*METHODS*/
	Inventory();				//constructor
	~Inventory();				//destructor

	// MUTATORS
	void SetNumberOfItems(int amountOfItems);
	void ReadInFile(ifstream inFile, string inFileName);
	void AddToList(Item *newItem);
	void SearchItem();

	// ACCESSORS
	Item *GetHead();
	int GetNumberOfItems();

private:
	/*ATTRIBUTES*/
	int numberOfItems;
	Item *head;
};

#endif /* INVENTORY_H_ */
