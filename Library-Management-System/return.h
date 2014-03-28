//------------------------------------------------------------
// Sub-Class of Transaction
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





