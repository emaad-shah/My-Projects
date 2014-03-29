#include "list.h"

// Default Constructor
List::List()
{
	head = NULL;
}

// List Deconstructor
List::~List()
{
	free();
}

// Insert a Book
void List::insert(Book* data)
{
	insertHelper(head, data);
}

// Helper Function for Insert
void List::insertHelper(Node *& head, Book* data)
{
	// If the Book already exists 
	if (head != NULL && *head->data == data)
	{
		// Increase quantity
		head->data->increaseQuantity();
		return;
	}

	else if (head == NULL || *data <= head->data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		return;
	}
	else
		insertHelper(head->next, data);
}

// Display Book Contents
void List::print()
{
	Node* cur = head;
	// Check to see if the list is empty
	if (isEmpty())
		return;
	// Display the type of book (Children, Fiction, Periodical)
	cur->data->displayType();
	while (cur != NULL)
	{
		// Display the content of the books
		cur->data->displayBook();
		cur = cur->next;
	}
}

// Delete the list / Deallocate memory
void List::free()
{
	if (head != NULL)
	{
		Node* cur;
		while (head->next != NULL)
		{
			cur = head->next;
			delete head;
			head = cur;
		}
		head = NULL;
	}
}

// Checks if the list is empty
bool List::isEmpty()
{
	return head == NULL;
}

// Retrieve a Book
bool List::retrieve(Book *& b)const
{
	Node* cur = head;
	while (cur != NULL)
	{
		if (*cur->data == b)
		{
			b = cur->data;
			return true;
		}
		cur = cur->next;
	}
	return false;
}