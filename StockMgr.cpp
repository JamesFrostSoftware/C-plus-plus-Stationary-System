#include "stdafx.h"
#include <vector>
#include "Item.cpp"
#include "TransMgr.cpp"
#include <iostream>


using namespace std;

class StockMgr
{

private:
	vector<Item*> itemList;
	vector<TransMgr*> takeStockVector;
	char pound = 156;
	//double totalMoneySpent = 5150; // Value for Testing
	double totalMoneySpent = 0; // Default
	int transLoop = 0;

public:
	bool createNewItem(int itemID, string itemName, int itemQuantity, double itemPrice, int itemTransactionNo, string itemDateAdded)
	{
		if (findItem(itemID))
		{
			for (Item* i : itemList)
			{
				i->setItemQuantity(itemQuantity);
			}
			return false;
		}
		else
		{
			Item* i = new Item(itemID, itemName, itemQuantity, itemPrice, itemTransactionNo, itemDateAdded);
			itemList.push_back(i);
			totalMoneySpent += itemQuantity * itemPrice;
			return true;
		}
	}
	bool removeStock(int itemID, string userName, int itemQuantity)
	{
		Item* i = findItem(itemID);
		if (i != nullptr)
		{
			if (i->getItemQuantity() - itemQuantity < 0)
			{
				cout << "Not enough products in stock to fulfil. Current in stock: " << i->getItemQuantity() << endl;
				return false;
			}
			else
			{
				i->setItemQuantityRemove(itemQuantity);
				TransMgr* t = new TransMgr(itemID, i->getItemName(), userName);
				takeStockVector.push_back(t);
				totalMoneySpent -= itemQuantity * i->getItemPrice();
				return true;
			}
		}
		else
		{
			cout << "No Such item exists" << endl;
			return false;
		}
	}

	bool inventoryReport()
	{
		for (Item* i : itemList)
		{
			if (i->getItemQuantity() == 0)
			{
				cout << i->getItemID() << ": " << i->getItemName() << " - " << "# This product is currently Out of Stock # - " << i->getItemQuantity() << endl;
			}
			else
			{
				cout << i->getItemID() << ": " << i->getItemName() << " - " << i->getItemQuantity() << endl;
			}
		}
		return false;
	}

	bool financialReport()
	{
		for (Item* i : itemList)
		{
			cout << i->getItemID() << ": " << pound << i->getItemPrice()*i->getItemQuantity() << endl;
		}
		cout << "Total Money Spent on all items: " << pound << totalMoneySpent << "\n"<<endl;
		return false;
	}

	bool transactionLog()
	{
		for (Item* i : itemList)
		{
			cout << endl << "Added on - " << i->getItemDateAdded() << "\t Item code - " << i->getItemID() << "\t Item name - " << i->getItemName() << "\t" << pound << i->getItemPrice()*i->getItemQuantity() << "\n" << endl;
		}
		for (TransMgr* t : takeStockVector)
		{
			cout << "Item code - " << t->getItemID() << "\t Item name - "<< t->getItemName() <<"\t Removed by - " << t->getUserName() << "\n" << endl;
		}
		return false;
	}

	bool puReport(string userName)
	{
		TransMgr* i = findUser(userName);
		if (findUser(userName))
		{
			for (TransMgr* t : takeStockVector)
			{
				if (userName == t->getUserName())
				{
					Item* j = findItem(t->getItemID());
					cout << fixed << "\n Item Code - " << t->getItemID() << " | Item Name - " << t->getItemName() << " | Date Taken - " << j->getItemDateAdded() << endl;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	Item* findItem(int itemID)
	{
		Item* item = nullptr;

		for (Item* i : itemList)
		{
			if (i->getItemID() == itemID)
			{
				item = i;
			}
		}
		return item;
	}

	TransMgr* findUser(string userName)
	{
		TransMgr* transMgr = nullptr;

		for (TransMgr* i : takeStockVector)
		{
			if (i->getUserName() == userName)
			{
				transMgr = i;
			}
		}
		return transMgr;
	}

	// Static Values for Testing


	//bool staticAddItems()
	//{
	//	// STATIC ADDED VALUES
	//	Item* m1 = new Item(1000, "Pen", 2000, 0.90, 1000, "16/04/2018");
	//	itemList.push_back(m1);
	//	Item* m2 = new Item(1001, "Pen", 2000, 0.90, 1001, "16/04/2018");
	//	itemList.push_back(m2);
	//	Item* m3 = new Item(1002, "Paper", 1000, 0.05, 1002, "16/04/2018");
	//	itemList.push_back(m3);
	//	Item* m4 = new Item(1003, "Rubber", 3000, 0.50, 1003, "16/04/2018");
	//	itemList.push_back(m4);
	//	Item* m9 = new Item(1004, "Holder", 0, 2, 1004, "16/04/2018");
	//	itemList.push_back(m9);
	//	Item* m10 = new Item(1005, "Compass", 0, 2, 1005, "16/04/2018");
	//	itemList.push_back(m10);
	//	Item* m11 = new Item(1006, "Ruler", 0, 2, 1006, "16/04/2018");
	//	itemList.push_back(m11);
	//	Item* m12 = new Item(1007, "Marker", 0, 2, 1007, "16/04/2018");
	//	itemList.push_back(m12);
	//	return false;
	//}
	//bool staticRemoveItems()
	//{
	//	// STATIC REMOVED VALUES
	//	TransMgr* m5 = new TransMgr(1004, "Holder", "James");
	//	takeStockVector.push_back(m5);
	//	TransMgr* m6 = new TransMgr(1005, "Compass", "James");
	//	takeStockVector.push_back(m5);
	//	TransMgr* m7 = new TransMgr(1006, "Ruler", "Doug");
	//	takeStockVector.push_back(m5);
	//	TransMgr* m8 = new TransMgr(1007, "Marker", "James");
	//	takeStockVector.push_back(m5);
	//	return false;
	//}
};