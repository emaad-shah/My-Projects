#include "book.h"

// Set Quantity of Fiction and Children Book
Book::Book()
{
	quantity = 5;
}

// Return a book
void Book::returnBook()
{
	quantity++;
}

// Check Out a Book
bool Book::checkBook()
{
	// Check book in stock
	if (quantity > 0)
	{
		quantity--;
		return true;
	}
	return false;
}

// Return the quantity of a book
int Book::getQuantity()const
{
	return quantity;
}
