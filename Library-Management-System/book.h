//------------------------------------------------------------
// The following abstract class contains the method 
// declaration for the library books. 
// The following classes are inherited from the Book class:
// (1) Fiction (Author, Title, Year)
// (2) Children (Author, Title, Year)
// (3) Periodical (Title, Month, Year)
//------------------------------------------------------------

#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include "hash.h"
#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book
{
	public:
		// Set Quantity of Fiction and Children Book
		Book();
		// Return a book
		void returnBook();
		// Check Out a Book
		bool checkBook();
		// Increase quantity of a Book if the
		// library receives additional copies
		void increaseQuantity();
		// Get the quantity of a book
		int getQuantity()const;
		// Add a new book in the inventory
		virtual Book * create(ifstream &) = 0;
		// Display type of Book
		virtual void displayType()const = 0;
		// Display contents of the book
		virtual void displayBook()const = 0;
		// Compare book
		virtual bool operator==(Book*)const = 0;
		virtual bool operator<=(Book*)const = 0;
		// Retrieve book information to store transaction
		virtual string getBook() = 0;

	protected:
		// Book Title
		string title;
		// Book Year
		int year;
		// Book Quantity
		int quantity;
};

#endif
