#include "return.h"

Return::Return()
{

}

// Execute transaction (Return)
bool Return::execute(Book*& book, list<string> &l)
{
	book->returnBook();
	this->book = book;
	transaction = this->book->getBook() + " (Returned)";
	l.push_front(transaction);
	return true;
}