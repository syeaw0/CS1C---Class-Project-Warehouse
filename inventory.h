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

#include <fstream>
#include <ios>
#include <limits>
#include "c_Item.h"
#include "Date.h"
class Inventory
{
public:
	/*METHODS*/
	Inventory();				//constructor
	~Inventory();				//destructor

	// MUTATORS
	void SetNumberOfItems(int amountOfItems);
	void ReadInFile(ifstream &inFile);
	void AddToList(Item *newItem);
	Item *SearchItem(int purchaseCode);
	Item *SearchItem(string purchaseItemName);

	// ACCESSORS
	Item *GetHead() const;
	int GetNumberOfItems() const;

private:
	/*ATTRIBUTES*/
	int numberOfItems;
	Item *head;
};

#endif /* INVENTORY_H_ */
