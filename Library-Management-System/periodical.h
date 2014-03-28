//------------------------------------------------------------
// Sub-Class of Book
//------------------------------------------------------------

#include "book.h"
#ifndef PERIODICAL_H
#define PERIODICAL_H

class Periodical: public Book
{
	public:
		// Set Quantity of Periodical Book
		Periodical();
		// Add a book in the library
		Book* create(ifstream&);
		// Display type of Book
		void displayType()const;
		// Display contents of the book
		void displayBook()const;
		// Compare Periodical
		bool operator==(Book *)const;
		string getBook();

	private:
		// Periodical Month
		int month;
};

#endif
