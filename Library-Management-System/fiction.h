//------------------------------------------------------------
// Sub-Class of Book. Responsible for:
// (1) Adding a Fiction Book in to the inventory
// (2) Comparing one fiction book to another
// (2) Displaying it's content
//------------------------------------------------------------

#include "book.h"
#ifndef FICTION_H
#define FICTION_H

using namespace std;

class Fiction: public Book
{
	public:
		Fiction();
		// Add a children book in the inventory
		Book* create(ifstream&);
		// Display type of Book
		void displayType()const;
		// Display contents of the book
		void displayBook()const;
		// Compare Fiction Book
		bool operator==(Book *)const;
		bool operator<=(Book *)const;
		// Retrieve book information to store transaction
		string getBook();
	
	private:
		// Fiction Author
		string author;
};

#endif
