#include "library.h"

// Call library methods
Library::Library()
{
	// Initialize the objects and variables
	initialize();
	// Store customer info
	storeCustomer();
	// Store Book info
	storeBook();
	// Perform Transactions (Return, Check-Out)
	performTransaction();
}

// Initialize objects
void Library::initialize()
{
	// Creating customer class array
	c = new His[MAXCUSTOMERS];
	for (int i = 0; i < MAXCUSTOMERS; i++)
	{
		for (int j = 0; j < 2; j++)
			c[i].t[j] = NULL;
		c[i].t[0] = new CheckOut();
		c[i].t[1] = new Return();
	}

	for (int i = 0; i < 3; i++)
		inventory[i] = NULL;
	
	inventory[0] = new Children();
	inventory[1] = new Fiction();
	inventory[2] = new Periodical();
}

// Library deconstructor
Library::~Library()
{
	for (int i = 0; i < 3; i++)
		delete inventory[i];
	for (int i = 0; i < MAXCUSTOMERS; i++)
	{
		delete c[i].t[0];
		delete c[i].t[1];
	}
	delete[] c;
}

// Add new customers
void Library::storeCustomer()
{
	string discard, lastName, firstName;
	int id;
	ifstream file;
	file.open("customer.txt");
	if (!file)
	{
		cerr << "Can not open file" << endl;
		return;
	}
	
	while (!file.eof())
	{
		file >> id;
		file.get();
		// Verify the id is unique
		if (c[id].customer.validID(id, MAXCUSTOMERS))
		{
			// Read customer name and ID
			file >> lastName;
			file.get();
			file >> firstName;
			// Check if customer already exists
			if (c[id].customer.validCustomer())
				c[id].customer.makeCustomer(lastName, firstName, id);
		}
		else
			getline(file, discard, '\n');
	}
	file.close();
}

// Add books to the inventory
void Library::storeBook()
{
	string discard;
	char type;	
	int key;
	ifstream file2;
	file2.open("book.txt");
	if (!file2)
	{
		cerr << "Can not open file" << endl;
		return;
	}
	
	while (!file2.eof())
	{
		file2 >> type;
		file2.get();
		key = h.hashKey(type);
		// The inventory only accepts Children, Fiction and Periodical
		if (h.validType(key))
		{
			inventory[key] = inventory[key]->create(file2);
			bookList[key].insert(inventory[key]);
		}
		else
			getline(file2, discard, '\n');
	}
	file2.close();
}

// Perform library transactions
void Library::performTransaction()
{
	string discard;
	char transaction, type;
	int transKey, key, id;

	ifstream file3;
	file3.open("transaction.txt");
	if (!file3)
	{
		cerr << "Can not open file" << endl;
		return;
	}
	
	while (!file3.eof())
	{
		file3 >> transaction;
		file3.get();
		transKey = h.hashKey(transaction);
		if (h.validTransaction(transaction))
		{
			file3 >> id;
			file3.get();

			// Verify the customer is legitimate
			if (c[id].customer.getID() == id)
			{
				file3 >> type;
				file3.get();
				key = h.hashKey(type);
				if (h.validType(key))
				{
					inventory[key] = inventory[key]->create(file3);
					bool retrieve = bookList[key].retrieve(inventory[key]);
					if (retrieve)
						c[id].t[transKey]->execute(inventory[key], c[id].tList);
				}
				else
					getline(file3, discard, '\n');
			}
			else
				getline(file3, discard, '\n');
		}
		else
			getline(file3, discard, '\n');
		
	}
	file3.close();
}

// Display inventory for a type of book
void Library::displayInventory(const char & type)
{
	int key = h.hashKey(type);
	// Books must be Children, Fiction or Periodical
	if (h.validType(key))
	{
		if (bookList[key].isEmpty())
			cout << "Nothing in inventory" << endl;
		else
			bookList[key].print();
	}
	else
		cerr << "Invalid Book Type: " << type << endl;
	cout << endl;
}

// Display customer transaction history
void Library::displayHistory(const int& id)
{
	// Check if a customer exists
	if (id > 999 && c[id].customer.getID() == id)
	{
		if (c[id].tList.empty())
			cout << "***No Transaction History For "
			<< c[id].customer.getName() << ": " << id
			<< "***" << endl << endl;
		else
		{
			cout << "***Displaying Transaction History For "
				<< c[id].customer.getName() << ": " << id
				<< "***" << endl << endl;
			// STL List iterator
			list <string>::iterator i;
			for (i = c[id].tList.begin(); i != c[id].tList.end(); i++)
				cout << *i << endl;
		}
	}
	else
		cerr << "Invalid Customer ID: " << id << endl;
	cout << endl;
}