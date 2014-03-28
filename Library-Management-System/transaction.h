//------------------------------------------------------------
// The following abstract class contains the method 
// declaration for customer transaction
// The following classes are inherited from Transaction class:
// (1) CheckOut
// (2) Return
//------------------------------------------------------------


#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include <hash_map>
#include "book.h"

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction
{
	public:
		Transaction()
		{

		}
		// Execute transaction
		virtual bool execute(Book*&, list<string> &) = 0;
		
	protected:
		Book* book;
		string transaction;
};

#endif





