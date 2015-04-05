#include "Book.h"
#include <iostream>
#include <string>

using namespace std;
//Constructors
Book::Book()
{
	idCode = "";
	title = "";
	author = "";
	location = ON_SHELF;
	checkedOutBy = NULL;
	requestedBy = NULL;
	dateCheckedOut = 0;
}
Book::Book(string inpID, string inpTitle, string inpAuth)
{
	idCode = inpID;
	title = inpTitle;
	author = inpAuth;
	location = ON_SHELF;
	checkedOutBy = NULL;
	requestedBy = NULL;
	dateCheckedOut = 0;
}
const int Book::CHECK_OUT_LENGTH = 21;
string Book::getIdCode()
{
	return idCode;
}
string Book::getAuthor()
{
	return author;
}
string Book::getTitle()
{
	return title;
}
Locale Book::getLocation()
{
	return location;
}
void Book::setLocation(Locale lo)
{
	location = lo;
}
Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
}
void Book::setCheckedOutBy(Patron* p)
{
	checkedOutBy = p;
}
Patron* Book::getRequestedBy()
{
	return requestedBy;
}
void Book::setRequestedBy(Patron* p)
{
	requestedBy = p;
}
int Book::getDateCheckedOut()
{
	return dateCheckedOut;
}
void Book::setDateCheckedOut(int d)
{
	dateCheckedOut = d;
}