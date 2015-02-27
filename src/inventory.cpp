/*************************************************************************
 * AUTHOR     		 : Arman Jafarinia
 * STUDENT ID 		 : 912488
 * Assignment #2     : student
 * CLASS      		 : CS 1C
 * SECTION    		 : T Th 12:00-1:50
 * DUE DATE   		 :
 * ***********************************************************************/

#include "Inventory.h"

Inventory::Inventory()
{
	numberOfItems	= 0;
	head 			= NULL;
}

Inventory::~Inventory()
{
	//No code
}

void Inventory::SetNumberOfItems(int amountOfItems)
{
	numberOfItems = amountOfItems;
}

void Inventory::readInFile()
{

}

Item*	Inventory::GetHead()			const
{
	return head;
}

int 	Inventory::GetNumberOfItems()	const
{
	return numberOfItems;
}
