//------------------------------------------------------------
// The following class contains the method declaration for the
// library. The library class is responsible for the following
// operations:
// (1) Add Customer to the inventory
// (2) Add Book to the inventory
// (3) Perform Transaction - (Check-Out, Return)
// (4) Display Inventory
// (5) View Transaction History
//
// Limitations: The customer must have a unique 4 digit ID 
//------------------------------------------------------------

#include <iostream>
#include <string>
#include <hash_map>
#include <fstream>
#include <algorithm>
#include "book.h"
#include "children.h"
#include "fiction.h"
#include "periodical.h"
#include "customer.h"
#include "hash.h"
#include "transaction.h"
#include "return.h"
#include "checkOut.h"
#include "list.h"

#ifndef LIBRARY_H
#define LIBRARY_H

using namespace std;

class Library
{
	public:
		// Call library methods
		Library();
		// Initialize objects
		void initialize();
		// Library deconstructor
		~Library();
		// Add new customers
		void storeCustomer();
		// Add books to the inventory
		void storeBook();
		// Perform library transactions
		void performTransaction();
		// Display inventory for a type of book
		void displayInventory(const char &);
		// Display customer transaction history
		void displayHistory(const int &);
	
	private:
		// Hash keys to buckets
		Hash h;

		// Book (Children, Fiction, Periodical)
		Book* inventory[3];
		// Custom list class to store book
		List bookList[3];

		// Customer information and transaction history
		struct His
		{
			// Customer name, id
			Customer customer;
			// Transaction (CheckOut, Return)
			Transaction* t[2];
			// Transaction detail
			list<string> tList;
		};
		His* c;

		// 4 digit unique ID number
		const int MAXCUSTOMERS = 10000;
};

#endif
