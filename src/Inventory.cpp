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
	numberOfItems = 0;
	head = NULL;
}

Inventory::~Inventory()
{
	Item*	perPtr;

	perPtr = head;

	while(perPtr != NULL)
	{
		head = head->GetNextItem();
		delete perPtr;
		perPtr = head;
	}
}

void Inventory::SetNumberOfItems(int amountOfItems)
{
	numberOfItems = amountOfItems;
}

void Inventory::ReadInFile(ifstream &inFile)
{
	Item *itemPtr;
	Date aDate;
	int memberId;
	string itemName;
	float cost;
	int quantity;
	int i;

	itemPtr = new Item;
	while(!inFile.eof() && itemPtr != NULL)
	{
		//aDate.SetDate(inFile);
		//itemPtr->SetDatePurchased(aDate);
		inFile >> memberId;
		itemPtr->SetPurchaseID(memberId);
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(inFile, itemName);
		itemPtr->SetItemName(itemName);
		inFile >> cost;
		itemPtr->SetItemPrice(cost);
		inFile >> quantity;
		itemPtr->SetItemQuantity(quantity);
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');

		itemPtr->SetNextItem(head);
		head	= itemPtr;
		itemPtr	= new Item;
	}

	delete itemPtr;
	itemPtr = NULL;
}

Item *Inventory::SearchItem(int purchaseCode)
{
	Item *itemPtr;
	bool found = false;

	itemPtr = head;

	while (itemPtr != NULL && !found)
	{
		if (itemPtr->GetBuyerID() == purchaseCode)
		{
			found = true;
		}
		else
		{
			itemPtr	= itemPtr->GetNextItem();
		}
	}

	return itemPtr;
}

//Overloaded Search w/ string input
Item *Inventory::SearchItem(string purchaseItemName)
{
	Item *itemPtr;
	bool found = false;

	itemPtr = head;

	while (itemPtr != NULL && !found)
	{
		if (itemPtr->GetName() == purchaseItemName)
		{
			found = true;
		}
		else
		{
			itemPtr	= itemPtr->GetNextItem();
		}
	}

	return itemPtr;
}

void Inventory::AddToList(Item *newItem)
{
	newItem->SetNextItem(head);
	head = newItem;

}

int Inventory::GetNumberOfItems()const
{
	return numberOfItems;
}

Item *Inventory::GetHead()const
{
	return head;
}
