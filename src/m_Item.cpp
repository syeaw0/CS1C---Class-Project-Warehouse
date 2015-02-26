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
void Item::SetDatePurchased(int day, int month, int year)
{
	purchaseDate.SetDate(day, month, year);
}

void Item::SetNextItem(Item *nextNode)
{
	nextItemPtr = nextNode;		//TODO fix method if necessary
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
void Item::GetDatePurchased() const
{
	purchaseDate.Print();
	//THIS WILL PRINT OUT SOMETHING
	//WOULD WE NEED IT TO DO THAT OR RETURN AN ACTUAL DATE VALUE(S)?
}

Item *Item::GetNextItem() const
{
	return nextItemPtr;
}

