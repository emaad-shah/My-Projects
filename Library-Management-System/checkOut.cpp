#include "checkOut.h"

CheckOut::CheckOut()
{

}

// Execute transaction (Check-Out)
bool CheckOut::execute(Book*& book, list<string> &l)
{
	if (book->checkBook())
	{
		this->book = book;
		transaction = this->book->getBook() + " (Issued)";
		l.push_front(transaction);
		return true;
	}
	return false;
}