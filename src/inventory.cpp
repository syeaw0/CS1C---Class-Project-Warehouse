/*************************************************************************
 * AUTHOR     		 : Arman Jafarinia
 * STUDENT ID 		 : 912488
 * Assignment #2     : student
 * CLASS      		 : CS 1C
 * SECTION    		 : T Th 12:00-1:50
 * DUE DATE   		 :
 * ***********************************************************************/

#include "inventory.h"
#include <fstream>
#include <ios>
#include <limits>
inventory::inventory()
{
	numberOfItems=0;
	head=NULL;
}

inventory::~inventory()
{
	delete head;
}

void inventory::SetNumberOfItems(int amountOfItems)
{
	numberOfItems=amountOfItems;
}

void inventory::ReadInFile(ifstream inFile, string inFileName)
{
	Item *itemPtr;
	int month;
	int day;
	int year;
	int memberId;
	string itemName;
	float cost;
	int quantity;

	inFile.open(inFileName.c_str());

	itemPtr=new Item;
	while(inFile && itemPtr!=NULL)
	{
		inFile >> month;
		inFile.ignore(numeric_limits<streamsize>::max(), '/');
		inFile >> day;
		inFile.ignore(numeric_limits<streamsize>::max(), '/');
		inFile >> year;
		itemPtr->SetDatePurchased(day, month, year);
		inFile >> memberId;
		itemPtr->SetPurchaseID(memberId);
		inFile.ignore(numeric_limits<streamsize>::max(),'\n');
		getline(inFile, itemName);
		inFile >> cost;
		inFile >> quantity;
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		itemPtr->SetNextItem(head);
		head=itemPtr;
		itemPtr=new Item;
	}

	delete itemPtr;
	itemPtr=NULL;
}

void inventory::AddToList(Item *newItem)
{
	newItem->SetNextItem(head);
	head=newItem;

}

int inventory::GetNumberOfItems()
{
	return numberOfItems;
}

Item *inventory::GetHead()
{
	return *head;
}
