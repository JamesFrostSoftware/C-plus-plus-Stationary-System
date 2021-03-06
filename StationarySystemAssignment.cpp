#include "stdafx.h"
#include <iostream>
#include <cctype>
#include "StockMgr.cpp"

using namespace std;

StockMgr stockMgr;

int transLoop = 0;

void addItem()
{
	int itemID = 0;
	string itemName;
	int itemQuantity = 0;
	double itemPrice = 0;
	int itemTransactionNo = 0;
	string itemDateAdded;

	// Add item menu
	transLoop++;
	cout << "Add Stock Menu" << endl << "----------------------------------------------------------" << endl;

	cout << "Item id: > ";
	cin >> itemID;

	cout << "Item Name > ";
	cin >> itemName;

	cout << "Quantity: > ";
	cin >> itemQuantity;

	cout << "Price: > ";
	cin >> itemPrice;

	itemTransactionNo += transLoop;
	cout << "The Transaction Number for this order is: " << itemTransactionNo << endl;

	cout << "Date Added (##/##/##) > ";
	cin >> itemDateAdded;

	if (stockMgr.createNewItem(itemID, itemName, itemQuantity, itemPrice, itemTransactionNo, itemDateAdded))
	{
		cout << "Item added." << endl;
	}
	else
	{
		cout << "Item quantity updated." << endl;
	}
}

void removeItem()
{
	int itemID = 0;
	string userName;
	int itemQuantity = 0;
	int date = 0;

	cout << "Take Stock Menu" << endl << "----------------------------------------------------------" << endl;

	cout << "Item id: > ";
	cin >> itemID;

	cout << "User name: > ";
	cin >> userName;

	cout << "Quantity: > ";
	cin >> itemQuantity;

	if (stockMgr.removeStock(itemID, userName, itemQuantity)) 
	{
		cout << "Quantity Updated." << endl;
	}
	else
	{
		cout << "Quantity not Updated." << endl;
	}

}

void inventoryReport()
{
	cout << "\nInventory Report" << endl << "----------------------------------------------------------" << endl;
	stockMgr.inventoryReport();
	cout << "" << endl;
}

void financialReport()
{
	cout << "\nFinancial Report" << endl << "----------------------------------------------------------" << endl;
	stockMgr.financialReport();
}

void transactionLog()
{
	cout << "\nTransaction Log" << endl << "----------------------------------------------------------" << endl;
	stockMgr.transactionLog();
}

void personalUsageReport()
{
	string userName;
	cout << "\nPersonal Usage Report" << endl << "----------------------------------------------------------" << endl;
	cout << "Please enter the name of the person > ";
	cin >> userName;

	if (stockMgr.puReport(userName))
	{
	}
	else
	{
		cout << "\nDoes not match names on record\n" << endl;
	}
}

int displayMainMenu()
{
	int option = -1;

	//Main Menu
	cout << "Stationary Tracking Main Menu" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "Please enter your choice from the menu below with the corresponding number" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << " 1 - Add to stock" << endl;
	cout << " 2 - Take from stock" << endl;
	cout << " 3 - Inventory report" << endl;
	cout << " 4 - Financial report" << endl;
	cout << " 5 - Transaction log" << endl;
	cout << " 6 - Personal usage report" << endl;
	cout << " 7 - Exit Program" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "Choice : ";

	cin >> option;
	return option;
}
int main()
{
	// Initiates Values for Testing
	//stockMgr.staticAddItems();
	//stockMgr.staticRemoveItems();
	int choice = displayMainMenu();

	while (choice != 7)
	{
		switch (choice)
		{
		case 1:
			addItem();
			break;
		case 2:
			removeItem();
			break;
		case 3:
			inventoryReport();
		default:
			break;
		case 4:
			financialReport();
			break;
		case 5:
			transactionLog();
			break;
		case 6:
			personalUsageReport();
			break;
		}
		choice = displayMainMenu();
	}
    return 0;
}

