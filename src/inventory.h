/*************************************************************************
 * AUTHOR     		 : Arman Jafarinia
 * STUDENT ID 		 : 912488
 * Assignment #2     : student
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
	Inventory();				//constructor
	~Inventory();				//destructor

	void SetNumberOfItems(int amountOfNumbers);
	void readInFile();

	int GetNumberOfItems();

private:
	int numberOfItems;
	Item *head;
};

#endif /* INVENTORY_H_ */
