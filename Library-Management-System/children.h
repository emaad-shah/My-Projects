//------------------------------------------------------------
// Sub-Class of Book
//------------------------------------------------------------


#include "book.h"
#ifndef CHILDREN_H
#define CHILDREN_H

class Children: public Book
{
	public:
		Children();
		// Add a book in the library
		Book* create(ifstream&);
		// Display type of Book
		void displayType()const;
		// Display contents of the book
		void displayBook()const;
		// Compare Children
		bool operator==(Book *)const;
		string getBook();
	
	private:
		// Children Author
		string author;
};

#endif
