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

#include "c_item.h"

class inventory
{
	public:
		inventory();				//constructor
		~inventory();				//destructor

		void SetNumberOfItems(int amountOfItems);
		void ReadInFile(ifstream inFile, string inFileName);
		void AddToList(Item *newItem);
		void SearchItem();

		Item *GetHead();
		int GetNumberOfItems();

	private:
		int numberOfItems;
		Item *head;
};


#endif /* INVENTORY_H_ */
