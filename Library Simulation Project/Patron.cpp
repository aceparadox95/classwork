#include "Patron.h"
#include "Book.h"
#include <iostream>
#include <string>

using namespace std;

Patron::Patron()
{
	idNum = "";
	name = "";
	checkedOutBooks.reserve(100);
	fineAmount = 0.0;
}
Patron::Patron(std::string idn, std::string n)
{
	idNum = idn;
	name = n;
	checkedOutBooks.reserve(100);
	fineAmount = 0.0;
}
string Patron::getIdNum()
{
	return idNum;
}
string Patron::getName()
{
	return name;
}
vector<Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
}
/***************************************************************
                      Add Book Function
 * Input:
 * Pointer to a new book constructed using book ID, book title,
 * and book author inputs from menu.
 *
 * Output:
 * No outputs
 * **************************************************************/ 
void Patron::addBook(Book* newBook)
{
	checkedOutBooks.push_back(newBook);
}
/***************************************************************
                      remove Book Function
 * Input:
 * Pointer to a new book constructed using book ID, book title,
 * and book author inputs from menu.
 *
 * Output:
 * No outputs
 * **************************************************************/
void Patron::removeBook(Book* remBook)
{
	for (int i = 0; i < checkedOutBooks.size(); i++)
	{
		if (remBook->getIdCode() == checkedOutBooks[i]->getIdCode()) //needed help from post on piazza @2325
			checkedOutBooks.erase(checkedOutBooks.begin()+i);
	}
}
double Patron::getFineAmount()
{
	return fineAmount;
}
/***************************************************************
                      amendFine Function
 * Input:
 * Fine payment amount from user
 *
 * Output:
 * No Outputs
 * **************************************************************/
void Patron::amendFine(double amount)
{
		fineAmount+= amount;//increase fine amount
}