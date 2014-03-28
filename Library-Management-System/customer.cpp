#include "customer.h"

Customer::Customer()
{
	lastName = firstName = "";
	id = 0;
}

// Create a new customer
void Customer::makeCustomer(const string & customerLastName, 
	const string & customerFirstName, const int & customerID)
{
	lastName = customerLastName;
	firstName = customerFirstName;
	id = customerID;
}

// Return customer name
string Customer::getName()const
{
	return lastName + " " + firstName;
}

// Return customer ID
int Customer::getID()const
{
	return id;
}

// Checks if a customer exists
bool Customer::validCustomer()const
{
	return id == 0 && lastName == "" && firstName == "";
}

// Checks if the id is valid
bool Customer::validID(const int & id, const int & MAX)const
{
	return id < MAX && id > 999;
}