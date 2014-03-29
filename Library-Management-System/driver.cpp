//------------------------------------------------------------
// Copyright: Syed Emaad Shah 2014 
// Compiler: Visual Studio Express 2013
// 
// This program contains the implementation for a library
// inventory management system. It allows execution of
// transaction such as:
// (1) Check Out Book
// (2) Return Book
// (3) Display Inventory
// (4) View Transaction History
//
// Three types of books are stores in the inventory:
// (1) Fiction: Contains Author, Title and Year
// (2) Children: Contains Author, Title and Year
// (3) Periodical: Contains Title, Year and Month
//
// Implementation: The program adheres to the standards
// described by the open-closed design system. 
// (1) Customer information is stored in a hash table 
//     for a quick retrieval using a unique 4 digit ID
// (2) Books are stored in a linked list as:
//     Children:   C1->C2->C3->NULL
//     Fiction:    F1->F2->F3->NULL 
//     Periodical: P1->P2->P3->NULL
// (3) The book class is polymorphic in behaviour
//
// Limitations: 
// (1) The program reads customer, book and transaction 
//     information from a text file
// (2) The program can be made interactive by minimal
//     modificiation
//------------------------------------------------------------
#include "library.h"

int main(void)
{
	Library l;
	// Test Display Inventory
	l.displayHistory(5678);
	l.displayHistory(1234);
	l.displayHistory(123);   // Invalid Entry
	l.displayHistory(10000); // Invalid Entry
	l.displayHistory(-50);	 // Invalid Entry

	// Test Display Books
	l.displayInventory('C'); // Children
	l.displayInventory('F'); // Fiction
	l.displayInventory('P'); // Periodical
	l.displayInventory('D'); // Invalid Entry
	l.displayInventory('*'); // Invalid Entry
	system("pause");
	return 0;
}
