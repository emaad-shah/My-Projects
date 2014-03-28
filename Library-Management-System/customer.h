//------------------------------------------------------------
// The following class is responsible for storing and 
// retrieving customer information such as:
// (1) First Name
// (2) Last Name
// (2) Unique ID (4 Digit)
//------------------------------------------------------------

#include <iostream>
#ifndef CUSTOMER_H
#define CUSTOMER_H

using namespace std;

class Customer
{
	public:
		Customer();
		// Create a new customer
		void makeCustomer(const string &, const string &, const int &);
		// Return customer name
		string getName()const;
		// Return customer ID
		int getID()const;
		// Checks if a customer exists
		bool validCustomer()const;
		// Checks if the id is valid
		bool validID(const int &, const int &)const;
	
	private:
		// Unique 4 digit ID
		int id;
		// Customer First Name
		string firstName;
		// Customer Last Name
		string lastName;
};

#endif
