//------------------------------------------------------------
// The following class contains Hash functions for:
// (1) Book Inventory         
//     0 = Children
//     1 = Fiction
//     2 = Periodical
// (2) Customer Transaction
//     0 = CheckOut
//     1 = Return
//------------------------------------------------------------

#include <iostream>
#include <map>

#ifndef HASH_H
#define HASH_H

using namespace std;

class Hash
{
	public:
		// Default Constructor
		Hash();
		// Hashes keys to buckets
		int hashKey(const char &);
		// Hashes transactions to buckets
		int hashTransaction(const char &);
		// Check if a transaction is valid
		bool validTransaction(const char &);
		// Check if a book type is valid
		bool validType(const int &);

	private:
		map <char, int> key;
};

#endif