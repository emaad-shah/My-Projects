#include "book.h"

// Set Quantity of Fiction and Children Book
Book::Book()
{
	// By default, there are 5 copies of a Fiction Book
	quantity = 5;
}

// Return a book
void Book::returnBook()
{
	quantity++;
}

// Increase quantity of a Book if the
// library receives additional copies
void Book::increaseQuantity()
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
