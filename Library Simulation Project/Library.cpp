#include "Book.h"
#include "Patron.h"
#include "Library.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Library::Library()
{
	holdings.reserve(100);
	members.reserve(100);
	currentDate = 0;
}
const double Library::DAILY_FINE = 0.1; // had to initialize variable outside header file for it compile correctly
/***************************************************************
                      Add Book Function
 * Input:
 * Prompts library clerk for book ID, title, and author
 *
 * Output:
 * Tells user if book was properly added or not
 * **************************************************************/
void Library::addBook()
{
	cin.ignore();//clear keyboard buffer from menu input
	string tempID, tempTitle, tempAuthor;// temporary variable to store input
	int bookCount = 0; //variable to store count of books with same ID
	cout << "Enter the book ID code: "; // prompt user for book ID
	getline(cin, tempID);
	for (int i = 0; i < holdings.size(); i++)// loop through holdings to find ID in book list
	{
		if (tempID == holdings[i].getIdCode())
		{
			bookCount++;
		}
	}
	if (bookCount == 1) // if a book with the same ID is found then user is sent back to menu
	{
		cout << "The book ID entered is already part of the library system" << endl;
		return;
	}
	cout << "Enter the book title: ";//prompt for book title
	getline(cin, tempTitle);
	cout << "Enter the author of the Book: ";//prompt for author
	getline(cin, tempAuthor);
	Book newBook(tempID, tempTitle, tempAuthor);//create book object
	holdings.push_back(newBook);//push book object to back of holdings vector
}
/***************************************************************
                      Add Member Function
 * Input:
 * Prompts library clerk for patron ID and name
 *
 * Output:
 * Tells user if patron was properly added or not
 * **************************************************************/
void Library::addMember()
{
	cin.ignore();//clear keyboard buffer from menu input
	string tempID, tempName; //temp variables
	cout << "Enter new member ID code: ";// prompt for patron ID
	getline(cin, tempID);
	int patCount = 0; // variable to count number of patrons with same ID
	for (int i = 0; i < members.size(); i++) //loop through patrons list to find books with same ID
	{
		if (tempID == members[i].getIdNum())
		{
			patCount++;
		}
	}
	if (patCount == 1)// if book with same ID is found then user is sent back to menu
	{
		cout << "The patron ID entered is already part of the library system" << endl;
		return;
	}
	cout << "Enter new member Name: ";//prompt for patron name
	getline(cin, tempName);
	Patron newPatron(tempID, tempName);//create new patron object
	members.push_back(newPatron);// add patron to patrons list
}
/***************************************************************
                      Checkout Book Function
 * Input:
 * Patron ID and Book ID from menu
 *
 * Output:
 * Tells patron if Book was checked out properly or not
 * **************************************************************/
void Library::checkOutBook(string patronID, string bookID)
{
	int patCount = 0, bookCount = 0, bookIndex = 0, patIndex = 0; //variables to store counts and indexes of patrons and books
	for (int i = 0; i < members.size(); i++) //search patrons list for input ID
	{
		if (patronID == members[i].getIdNum())
		{
			patCount++;
			patIndex = i;//store index of patron in vector if found
		}
	}
	if (patCount != 1) //send user to menu if patron Id isnt found
	{
		cout << "The patron ID entered was not recognized in the library system" << endl;
		return;
	}
	for (int i = 0; i < holdings.size(); i++)//search books list for Input ID
	{
		if (bookID == holdings[i].getIdCode())
		{
			bookCount++;
			bookIndex = i;//store index of book if book is found
		}
	}
	if (bookCount != 1)//send user to menu if book isnt found
	{
		cout << "The book ID entered was not recognized in the library system" << endl;
		return;
	}
	if (holdings[bookIndex].getLocation() == CHECKED_OUT) //return user to menu if book is already checked out
	{
		cout << holdings[bookIndex].getTitle() << " is currently unavailable for check out." << endl;
		return;
	}
	else if (((holdings[bookIndex].getLocation() == ON_HOLD) && (holdings[bookIndex].getRequestedBy()) == &members[patIndex]) || (holdings[bookIndex].getLocation() == ON_SHELF)) // check out book if patron has book on hold or if the book is on the shelf
	{
		holdings[bookIndex].setCheckedOutBy(&members[patIndex]); //mark in the book objects who book is checked out by
		holdings[bookIndex].setDateCheckedOut(get_currentDate()); //set the checkout date of the book to the current date
		if ((holdings[bookIndex].getLocation() == ON_HOLD) && (holdings[bookIndex].getRequestedBy()) == &members[patIndex])
			holdings[bookIndex].setRequestedBy(NULL);//if book is checked out by someone who has had requested it previously then set the requested by variable to NULL to allow other patrons to request it
		holdings[bookIndex].setLocation(CHECKED_OUT);//set the location to checked out
		members[patIndex].addBook(&holdings[bookIndex]);//add the book to the patrons book list
		cout << holdings[bookIndex].getTitle() << " has been checked out by " << members[patIndex].getName() << endl;//tell user the book was checked out
	}
	else //the book is on hold by another person so they cant check it out
	{
		cout << holdings[bookIndex].getTitle() << " is currently on hold by another person and is unavailable for check out." << endl;
		return;
	}
}
/***************************************************************
                      return Book function
 * Input:
 * Book ID from Menu
 *
 * Output:
 * Tells user if book was returned properly or not
 * **************************************************************/
void Library::returnBook(string bookID)
{
	int bookCount = 0, bookIndex = 0; //variables to store bookcount and Id
	vector <Book*> tempBookList; //temporary book list variable
	for (int i = 0; i < holdings.size(); i++)//check holdsings list for book ID input
	{
		if (bookID == holdings[i].getIdCode())
		{
			bookCount++;
			bookIndex = i;//store book index if found
		}
	}
	if (bookCount != 1)//if its not found then send user back to menu
	{
		cout << "The book ID entered was not recognized in the library system" << endl;
		return;
	}
	if (holdings[bookIndex].getLocation() != CHECKED_OUT)//dont allow user to return a book that hasnt been checked out previously
	{
		cout << "This book has not been checked out so its not possible to return it" << endl;
		return;
	}
	for (int i = 0; i < members.size(); i++)// loop through all of the patrons and their book lists to find the book
	{
		tempBookList = members[i].getCheckedOutBooks();
		for (int p = 0; p < tempBookList.size(); p++)
		{
			//if (members[i].getCheckedOutBooks[p].getIdCode() == bookID)
			members[i].removeBook(&holdings[bookIndex]);// remove the book from that patrons list if found
		}
	}
	if (holdings[bookIndex].getRequestedBy() != NULL) // if the book has been requested by somebody then put it on hold after return
		holdings[bookIndex].setLocation(ON_HOLD);
	else
		holdings[bookIndex].setLocation(ON_SHELF); // if it hasnt been requested by somebody then just put it back on the shelf
	cout << holdings[bookIndex].getTitle() << " has been returned." << endl;//tell user the book has been returned
}
/***************************************************************
                      Requested Book Function
 * Input:
 * Book and Patron IDs from menu
 *
 * Output:
 * Tells user if book was properly requested or not
 * **************************************************************/
void Library::requestBook(string patronID, string bookID)
{
	int patCount = 0, bookCount = 0, bookIndex = 0, patIndex = 0;//temp variables to store book and patron coutns and indexes
	for (int i = 0; i < members.size(); i++) //find patron ID in patron list
	{
		if (patronID == members[i].getIdNum())
		{
			patCount++;
			patIndex = i;//if found then save the index of the patron
		}
	}
	if (patCount != 1)//if not found then send user back to menu
	{
		cout << "The patron ID entered was not recognized in the library system" << endl;
		return;
	}
	for (int i = 0; i < holdings.size(); i++)//find book ID in book list
	{
		if (bookID == holdings[i].getIdCode())
		{
			bookCount++;
			bookIndex = i;// if found then save the index of the book
		}
	}
	if (bookCount != 1)//if not found then send the user back to the menu
	{
		cout << "The book ID entered was not recognized in the library system" << endl;
		return;
	}
	if ((holdings[bookIndex].getLocation() == ON_HOLD) || (holdings[bookIndex].getRequestedBy() != NULL)) // if the book is on hold or has been requested by another person then send user back to menu
	{
		cout << "Sorry this book has already been requested by another patron" << endl;
		return;
	}
	holdings[bookIndex].setRequestedBy(&members[patIndex]); //set the book requested by variable to the current patron
	if (holdings[bookIndex].getLocation() == ON_SHELF) // if the book is on the shelf then set the location to the hold shelf
	{
		holdings[bookIndex].setLocation(ON_HOLD);
	}
	cout << holdings[bookIndex].getTitle() << " has been requested by " << members[patIndex].getName() << endl;// notify user that the book has been requested
}
int Library::get_currentDate()
{
	return currentDate;
}
/***************************************************************
                      Increment Current Date Function
 * Input:
 * Function is initiated by command in the Menu function
 *
 * Output:
 * No outputs
 * **************************************************************/
void Library::incrementCurrentDate()
{
	currentDate++;
	vector <Book*> tempBookList;
	for (int i = 0; i < members.size(); i++) // search for any books that are over the due date in each patron list
	{
		tempBookList = members[i].getCheckedOutBooks();
		for (int b = 0; b < tempBookList.size(); b++)
		{
			if (((get_currentDate())- (tempBookList[b]->getDateCheckedOut())) > tempBookList[b]->CHECK_OUT_LENGTH)
			{
				members[i].amendFine(DAILY_FINE);// build the fine each time the date is increased for each book
			}
		}
	}
}
/***************************************************************
                      Retrieve Patron Fine Function
 * Input:
 * Patron ID from menu
 * 
 * Output:
 * Displays current fine amount patron
 * **************************************************************/
double Library::retrievePatronFine(string patronID)
{
	int patCount = 0, patIndex = 0;
	for (int i = 0; i < members.size(); i++)//search patrons for ID
	{
		if (patronID == members[i].getIdNum())
		{
			patCount++; 
			patIndex = i; //if found then store index
		}
	}
	if (patCount != 1)
	{
		return 0.0; //if not found then return a blank value
	}
	return members[patIndex].getFineAmount(); //retrieve fine amount using variable
}
/***************************************************************
                      Pay Fine Function
 * Input:
 * Patron ID and Fine Amount from menu function
 *
 * Output:
 * Tells user updated fine amount
 * **************************************************************/
void Library::payFine(string patronID, double payment)
{
	int patCount = 0, patIndex = 0;
	for (int i = 0; i < members.size(); i++)//search for patron in patrons list
	{
		if (patronID == members[i].getIdNum())
		{
			patCount++;
			patIndex = i;//if found store the index value
		}
	}
	if (patCount != 1)//if not found send the user back to the menu
	{
		cout << "The patron ID entered was not recognized in the library system" << endl;
		return;
	}
	payment = payment * -1.0; //set in the input value to negative so that it will decrement from the fine amount
	members[patIndex].amendFine(payment); //send payment amount to the amend fine function
	cout << "The fines for " << members[patIndex].getName() << " is now: " << setw(2) << "$" << fixed << setprecision(2) << members[patIndex].getFineAmount() << endl; //report the current fine amount
}
/***************************************************************
                      View Patron Info Function
 * Input:
 * Patron ID from Menu
 *
 * Output:
 * Shows Patron ID, Name, as well as books currently checked out
 * **************************************************************/
void Library::viewPatronInfo(string patronID)
{
	int patCount = 0, patIndex = 0;
	vector <Book*> tempBookList;
	for (int i = 0; i < members.size(); i++)//search for patron in the patrons list
	{
		if (patronID == members[i].getIdNum())
		{
			patCount++;
			patIndex = i;// if founds store index
		}
	}
	if (patCount != 1)// if not found then send user back to menu
	{
		cout << "The patron ID entered was not recognized in the library system" << endl;
		return;
	}
	cout << "Patron ID: " << members[patIndex].getIdNum() << endl;// print ID and name
	cout << "Name: " << members[patIndex].getName() << endl;
	cout << "Books currently checked out: " << endl;
	tempBookList = members[patIndex].getCheckedOutBooks();
	for (int i = 0; i < tempBookList.size(); i++)//print all the books checked out by patron
	{
		cout << tempBookList[i]->getTitle() << endl;
	}
	cout << "Current Fine Amount is" << setw(2) << "$" << fixed << setprecision(2) << members[patIndex].getFineAmount() << endl;//report current fine amount
}
/***************************************************************
                      View Book Info Function
 * Input:
 * Book ID from Menu
 *
 * Output:
 * Book ID, Title, Author, and who has requested the book and checked
 * out the book.
 * **************************************************************/
void Library::viewBookInfo(string bookID)
{
	int bookCount = 0, bookIndex = 0;
	Patron* tempPatron;
	for (int i = 0; i < holdings.size(); i++) //search for book Id in book list
	{
		if (bookID == holdings[i].getIdCode())
		{
			bookCount++;
			bookIndex = i;// if found store index value
		}
	}
	if (bookCount != 1)// if not found send user back to main menu
	{
		cout << "The book ID entered was not recognized in the library system" << endl;
		return;
	}
	cout << "Book ID: " << holdings[bookIndex].getIdCode() << endl; //print book ID, title, and author
	cout << "Title: " << holdings[bookIndex].getTitle() << endl;
	cout << "Author: " << holdings[bookIndex].getAuthor() << endl;
	cout << "Location: ";// print location
	if (holdings[bookIndex].getLocation() == ON_HOLD) 
	{ 
		cout << "On Hold" << endl; 
	}
	else if (holdings[bookIndex].getLocation() == ON_SHELF) 
	{ 
		cout << "On Shelf" << endl;
	}
	if (holdings[bookIndex].getLocation() == CHECKED_OUT) 
	{ 
		cout << "Checked Out" << endl;
	}
	tempPatron = holdings[bookIndex].getRequestedBy();
	if (tempPatron != NULL)// print who has requested the book if it has been requested
	{
		cout << "Currently Requested By: " << tempPatron->getName() << endl;
	}
	tempPatron = holdings[bookIndex].getCheckedOutBy();
	if (holdings[bookIndex].getLocation() == CHECKED_OUT)//print who has the book checked out
	{
		cout << "Currently Checked Out By: " << tempPatron->getName() << endl;
		cout << "Due Date: " << holdings[bookIndex].getDateCheckedOut() + holdings[bookIndex].CHECK_OUT_LENGTH << endl; // if its checked out print the due date
	}
}