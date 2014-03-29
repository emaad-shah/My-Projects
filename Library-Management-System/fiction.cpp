#include "fiction.h"

Fiction::Fiction()
{

}

// Add a fiction book in the inventory
Book* Fiction::create(ifstream & file)
{
	Fiction* f = new Fiction();
	// Read book author
	getline(file, f->author, ',');
	file.get();
	// Read book title
	getline(file, f->title, ',');
	file.get();
	// Read book year
	file >> f->year;
	return f;
}

// Display type of Book
void Fiction::displayType()const
{
	cout << "***Displaying Fiction***" << endl;
}

// Display contents of the book
void Fiction::displayBook()const
{
	cout << author << ", " << title << ", " 
		 << year << " (Quantity: " 
		 << quantity << ")" << endl;
}

// Compare Fiction Book
bool Fiction::operator==(Book * b)const
{
	// Compare the author, title and the year
	Fiction* f = dynamic_cast<Fiction*>(b);
	return this->author == f->author &&
		this->title == f->title &&
		this->year == f->year;
}

// Compare Fiction Book
bool Fiction::operator<=(Book * b)const
{
	// Compare book title
	Fiction* f = dynamic_cast<Fiction*>(b);
	return this->title <= f->title;
}

// Retrieve book information to store transaction
string Fiction::getBook()
{
	return "Fiction - " + author + ", "
		+ title + ", " + to_string(year);
}