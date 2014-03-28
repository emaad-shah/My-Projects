#include "fiction.h"

Fiction::Fiction()
{

}

// Add a book in the library
Book* Fiction::create(ifstream& file)
{
	Fiction* temp = new Fiction();
	getline(file, temp->author, ',');
	file.get();
	getline(file, temp->title, ',');
	file.get();
	file >> temp->year;
	return temp;
}

// Display type of Book
void Fiction::displayType()const
{
	cout << "***Displaying Fiction***" << endl;
}

// Display contents of the book
void Fiction::displayBook()const
{
	cout << author << ", " << title << ", " << year << endl;
}

// Compare Fiction
bool Fiction::operator==(Book * b)const
{
	// Compare the author, title and the year
	Fiction* f = dynamic_cast<Fiction*>(b);
	return this->author == f->author &&
		this->title == f->title &&
		this->year == f->year;
}

string Fiction::getBook()
{
	return "Fiction- " + author + ", "
		+ title + ", " + to_string(year);
}