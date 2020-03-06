#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Item 
{
private:
	int itemID = 0;
	string itemName = "";
	int itemQuantity = 0;
	double itemPrice = 0;
	int itemTransactionNo = 0;
	string itemDateAdded = "";

public:
	Item(int itemID, string itemName, int itemQuantity, double itemPrice, int itemTransactionNo, string itemDateAdded)
	{
		this->itemID = itemID;
		this->itemName = itemName;
		this->itemQuantity = itemQuantity;
		this->itemPrice = itemPrice;
		this->itemTransactionNo = itemTransactionNo;
		this->itemDateAdded = itemDateAdded;
	}

	int getItemID()
	{
		return itemID;
	}
	string getItemName()
	{
		return itemName;
	}

	void setItemQuantity(int itemQuantity)
	{
		this->itemQuantity += itemQuantity;
	}

	void setItemQuantityRemove(int itemQuantity)
	{
		this->itemQuantity -= itemQuantity;
	}

	int getItemQuantity()
	{
		return itemQuantity;
	}
	double getItemPrice()
	{
		return itemPrice;
	}
	int getItemTransactionNo()
	{
		return itemTransactionNo;
	}
	string getItemDateAdded()
	{
		return itemDateAdded;
	}
};