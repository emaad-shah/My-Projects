#include "hash.h"

// Default Constructor
Hash::Hash()
{
	// Initialize Hash Map
	for (char i = 0; i <= 126; i++)
		key[i] = -1;
	// Children Book or Check Out
	key['C'] = 0;
	// Fiction Book
	key['F'] = 1;
	// Return 
	key['R'] = 1;
	// Periodical Book
	key['P'] = 2;
}

// Hashes keys to buckets
int Hash::hashKey(const char & key)
{
	return this->key[key];
}

// Check if a transaction is valid
bool Hash::validTransaction(const char & key)
{
	return (key - 'A') == 2 || (key - 'A') == 17;
}

// Check if a book type is valid
bool Hash::validType(const int & key)
{
	if (key == 0 || key == 1 || key == 2)
		return true;
	return false;
}