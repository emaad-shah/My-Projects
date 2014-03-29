#include "periodical.h"

// Set Quantity of Periodical Book
Periodical::Periodical()
{
	// By default, there is 1 copy of a Periodical
	quantity = 1;
}

// Add a periodical book in the inventory
Book* Periodical::create(ifstream & file)
{
	Periodical * p = new Periodical();
	// Read periodical title
	getline(file, p->title, ',');
	file.get();
	// Read periodical month
	file >> p->month;
	// Read periodical year
	file >> p->year;
	return p;
}

// Display type of Book
void Periodical::displayType()const
{
	cout << "***Displaying Periodical***" << endl;
}

// Display contents of the book
void Periodical::displayBook()const
{
	cout << title << ", " << year << " " << month 
		 << " (Quantity: " << quantity << ")" << endl;
}

// Compare Periodical
bool Periodical::operator==(Book * b)const
{
	// Compare the title month and the year
	Periodical* p = dynamic_cast<Periodical*>(b);
	return this->month == p->month &&
		this->title == p->title &&
		this->year == p->year;
}

// Compare Periodical
bool Periodical::operator<=(Book * b)const
{
	// Compare book title
	Periodical* p = dynamic_cast<Periodical*>(b);
	return this->title <= p->title;
}

// Retrieve periodical information to store transaction
string Periodical::getBook()
{
	return "Periodical - " + title + ", " +
		to_string(month) + ", " + to_string(year);
}