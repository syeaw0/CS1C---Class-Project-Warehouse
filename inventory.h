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


class inventory
{
	public:
		inventory();				//constructor
		~inventory();				//destructor

		void SetNumberOfItems(int amountOfNumbers);
		void readInFile();

		int GetNumberOfItems();

	private:
		int numberOfItems;
};


#endif /* INVENTORY_H_ */
