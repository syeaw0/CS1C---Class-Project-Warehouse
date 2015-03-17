/*********************************************************
 * AUTHOR 			: Daniel Phan
 * STUDENT ID 		: 243390
 * Class Project	: Ralph's Club Membership RipOff
 * CLASS 			: CS1C
 * SECTION 			: TTh 12:30PM - 4:20PM
 * DUE DATE 		: 3/17/15
 *********************************************************/
#include "c_Item.h"
//Default Constructor
Item::Item()
{
	itemName.clear();
	itemPrice = 0.0;
	itemQuantity = 0;
	buyerID = 0;
	purchaseDate.SetDate(1, 1, 1970);
	nextItemPtr = NULL;
}

//Default Destructor
Item::~Item()
{
	//Need something that manages memory
}

//**Mutators**
void Item::SetItemName(string theName)
{
	itemName = theName;
}
void Item::SetItemPrice(float thePrice)
{
	itemPrice = thePrice;
}
void Item::SetItemQuantity(int theQuantity)
{
	itemQuantity = theQuantity;
}
void Item::SetPurchaseID(int theBuyerID)
{
	buyerID = theBuyerID;
}
void Item::SetDatePurchased(Date aDate)
{
	purchaseDate	= aDate;
}

void Item::SetNextItem(Item *nextNode)
{
	nextItemPtr = nextNode;
}

//***Accessors***

string Item::GetName() const
{
	return itemName;
}
float Item::GetPrice() const
{
	return itemPrice;
}
int Item::GetQuantity() const
{
	return itemQuantity;
}
int Item::GetBuyerID() const
{
	return buyerID;
}
Date Item::GetDatePurchased() const
{
	return purchaseDate;
}

Item *Item::GetNextItem() const
{
	return nextItemPtr;
}

