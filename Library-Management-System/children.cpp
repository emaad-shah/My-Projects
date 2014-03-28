#include "children.h"

Children::Children()
{

}

// Add a book in the library
Book* Children::create(ifstream& file)
{
	Children* temp = new Children();
	getline(file, temp->author, ',');
	file.get();
	getline(file, temp->title, ',');
	file.get();
	file >> temp->year;
	return temp;
}

// Display type of Book
void Children::displayType()const
{
	cout << "***Displaying Children***" << endl;
}

// Display contents of the book
void Children::displayBook()const
{
	cout << author << ", " << title << ", " << year << endl;
}

// Compare Children
bool Children::operator==(Book * b)const
{
	// Compare the author, title and the year
	Children* c = dynamic_cast<Children*>(b);
	return this->author == c->author &&
		this->title == c->title &&
		this->year == c->year;
}

string Children::getBook()
{
	return "Children- " + author + ", "
		+ title + ", " + to_string(year);
}


