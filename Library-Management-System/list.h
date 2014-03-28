//------------------------------------------------------------
// The following class contains the method for a linked list
// The list stores a Book object such as:
// (1) Children
// (2) Fiction 
// (3) Periodical
//------------------------------------------------------------

#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <fstream>
#include "book.h"

using namespace std;

class List
{
	public:
		// Default Constructor
		List();
		// List Deconstructor
		~List();
		// Insert a Book 
		void insert(Book*);
		// Display Book Contents
		void print();
		// Delete List
		void free();
		// Checks if the list is empty
		bool isEmpty();
		// Retrieve Book
		bool retrieve(Book *&)const;

	private:
		struct Node
		{
			Node* next;
			Book* data;
		};
		Node *head;

		// Helper Function for Insert
		void insertHelper(Node *&, Book*);
};


#endif

