//------------------------------------------------------------
// Sub-Class of Book
// (1) Adding a Children Book in to the inventory
// (2) Comparing one Children book to another
// (2) Displaying it's content
//------------------------------------------------------------

#include "book.h"
#ifndef CHILDREN_H
#define CHILDREN_H

class Children: public Book
{
	public:
		Children();
		// Add a children book in the inventory
		Book* create(ifstream&);
		// Display type of Book
		void displayType()const;
		// Display contents of the book
		void displayBook()const;
		// Compare Children Book
		bool operator==(Book *)const;
		bool operator<=(Book *)const;
		// Retrieve book information to store transaction
		string getBook();
	
	private:
		// Children Author
		string author;
};

#endif
