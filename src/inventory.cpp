/*************************************************************************
 * AUTHOR     		 : Arman Jafarinia
 * STUDENT ID 		 : 912488
 * Assignment #2     : student
 * CLASS      		 : CS 1C
 * SECTION    		 : T Th 12:00-1:50
 * DUE DATE   		 :
 * ***********************************************************************/

#include "inventory.h"

inventory::inventory()
{
	numberOfItems=0;
	head=NULL;
}

inventory::~inventory()
{
	//No code
}

void inventory::SetNumberOfItems(int amountOfItems)
{
	numberOfItems=amountOfItems;
}

void inventory::readInFile()
{

}

int inventory::GetNumberOfItems()
{
	return numberOfItems;
}
