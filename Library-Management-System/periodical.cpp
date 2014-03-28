#include "periodical.h"

// Set Quantity of Periodical Book
Periodical::Periodical()
{
	quantity = 1;
}

// Add a book in the library
Book* Periodical::create(ifstream& file)
{
	Periodical * temp = new Periodical();
	getline(file, temp->title, ',');
	file.get();
	file >> temp->month;
	file >> temp->year;
	return temp;
}

// Display type of Book
void Periodical::displayType()const
{
	cout << "***Displaying Periodical***" << endl;
}

// Display contents of the book
void Periodical::displayBook()const
{
	cout << title << ", " << year << " " << month << endl;
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

string Periodical::getBook()
{
	return "Periodical- " + title + ", " +
		to_string(month) + ", " + to_string(year);
}