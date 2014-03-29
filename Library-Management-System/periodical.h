//------------------------------------------------------------
// Sub-Class of Book
// (1) Adding a Periodical in to the inventory
// (2) Comparing one Periodical to another
// (2) Displaying it's content
//------------------------------------------------------------

#include "book.h"
#ifndef PERIODICAL_H
#define PERIODICAL_H

class Periodical: public Book
{
	public:
		// Set Quantity of Periodical Book
		Periodical();
		// Add a periodical book in the inventory
		Book* create(ifstream&);
		// Display type of Book
		void displayType()const;
		// Display contents of the book
		void displayBook()const;
		// Compare Periodical
		bool operator==(Book *)const;
		bool operator<=(Book *)const;
		// Retrieve periodical information to store transaction
		string getBook();

	private:
		// Periodical Month
		int month;
};

#endif
