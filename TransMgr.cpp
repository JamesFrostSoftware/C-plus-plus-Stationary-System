#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class TransMgr
{
private:
	int itemID = 0;
	string itemName = "";
	string userName;

public:
	TransMgr(int itemID, string itemName, string userName)
	{
		this->itemID = itemID;
		this->itemName = itemName;
		this->userName = userName;
	}

	int getItemID()
	{
		return itemID;
	}
	string getItemName()
	{
		return itemName;
	}
	string getUserName()
	{
		return userName;
	}
};