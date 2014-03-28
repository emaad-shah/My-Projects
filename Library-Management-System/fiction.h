//------------------------------------------------------------
// Sub-Class of Book
//------------------------------------------------------------

#include "book.h"
#ifndef FICTION_H
#define FICTION_H

using namespace std;

class Fiction: public Book
{
	public:
		Fiction();
		// Add a book in the library
		Book* create(ifstream&);
		// Display type of Book
		void displayType()const;
		// Display contents of the book
		void displayBook()const;
		// Compare Fiction
		bool operator==(Book *)const;
		string getBook();
	
	private:
		// Fiction Author
		string author;
};

#endif
