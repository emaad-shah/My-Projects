//------------------------------------------------------------
// Sub-Class of Transaction. Responsible for:
// (1) Returning and adding a book back in to the inventory
//------------------------------------------------------------

#include "transaction.h"
#ifndef RETURN_H
#define RETURN_H

class Return: public Transaction
{
	public:
		Return();
		// Execute transaction (Return)
		bool execute(Book*& book, list<string> &);
};

#endif





