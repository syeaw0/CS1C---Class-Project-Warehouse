/*********************************************************
 * AUTHOR 			: Daniel Phan
 * STUDENT ID 		: 243390
 * Class Project	: Ralph's Club Membership RipOff
 * CLASS 			: CS1C
 * SECTION 			: TTh 12:30PM - 4:20PM
 * DUE DATE 		: 3/17/15
 *********************************************************/
#ifndef C_ITEM_H_
#define C_ITEM_H_

#include <string>

using namespace std;


class Item
{
public:
	Item();
	~Item();

	/************
	 * Mutators *
	 ************/
	void SetItemName(string theName);
	void SetItemPrice(float thePrice);
	void SetItemQuantity(int theQuantity);
	void SetPurchaseID(int theBuyerID);
	//void SetDatePurchased(BLANK FIELD)	UNKNOWN IMPLEMENTATION
	//void SetNextItem(BLANK FIELD)	UNKNOWN IMPLEMENTATION

	/*************
	 * Accessors *
	 *************/
	string GetName() const;
	float GetPrice() const;
	int GetQuantity() const;
	int GetBuyerID() const;
	//void GetDatePurchased() const; UNKNOWN RETURN METHODS
	//Items nextItem() const;	UNKNOWN RETURN TYPE

private:

	string itemName;
	float itemPrice;
	int itemQuantity;
	int buyerID;
	Date purchaseDate;
	Item *nextItem;

};
#endif /* C_ITEM_H_ */
