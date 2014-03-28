//------------------------------------------------------------
// Sub-Class of Transaction
//------------------------------------------------------------

#include "transaction.h"
#ifndef CHECKOUT_H
#define CHECKOUT_H

class CheckOut : public Transaction
{
	public:
		CheckOut();
		// Execute transaction (Check-Out)
		bool execute(Book*& tmp, list<string> &);
};

#endif

