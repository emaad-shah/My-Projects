#include "children.h"

Children::Children()
{

}

// Add a children book in the inventory
Book* Children::create(ifstream & file)
{
	Children* c = new Children();
	// Read book author
	getline(file, c->author, ',');
	file.get();
	// Read book title
	getline(file, c->title, ',');
	file.get();
	// Read book year
	file >> c->year;
	return c;
}

// Display type of Book
void Children::displayType()const
{
	cout << "***Displaying Children***" << endl;
}

// Display contents of the book
void Children::displayBook()const
{
	cout << author << ", " << title << ", "
		<< year << " (Quantity: "
		<< quantity << ")" << endl;
}

// Compare Children Book
bool Children::operator==(Book * b)const
{
	// Compare the author, title and the year
	Children* c = dynamic_cast<Children*>(b);
	return this->author == c->author &&
		this->title == c->title &&
		this->year == c->year;
}

// Compare Children Book
bool Children::operator<=(Book * b)const
{
	// Compare book title
	Children* c = dynamic_cast<Children*>(b);
	return this->title <= c->title;
}

// Retrieve book information to store transaction
string Children::getBook()
{
	return "Children - " + author + ", "
		+ title + ", " + to_string(year);
}


