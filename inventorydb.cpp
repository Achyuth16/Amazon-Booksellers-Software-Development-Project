#include "inventmenu.h"
#include "bookinfo.h"
#include <iostream>
#include <cctype>
#include "Strupper.h"
using namespace std;
const int NUM_BOOKS = 20;
const int STR_SIZE = 51;
extern char booktitle[NUM_BOOKS][STR_SIZE];
extern char isbn[NUM_BOOKS][STR_SIZE];
extern char author[NUM_BOOKS][STR_SIZE];
extern char publisher[NUM_BOOKS][STR_SIZE];
extern char dateadded[NUM_BOOKS][STR_SIZE];
extern int qtyonhand[NUM_BOOKS];
extern double wholesale[NUM_BOOKS];
extern double retail[NUM_BOOKS];

void inventmenu()
{
	int choice = 0;
	while (choice !=5)
	{
		cout << "Amazon Booksellers inventory database\n\n";
		cout << "1. Look up a book\n";
		cout << "2. Add a book\n";
		cout << "3. Edit a book's record\n";
		cout << "4. Delete a book\n";
		cout << "5. Return to the main menu\n\n";
		cout << "Enter your choice:";
		cin >> choice;

		while (choice < 1 || choice > 5) 
		{
			cout << "\n please enter the range between 1-5" << endl;
			cout << "please enter your choice: ";
			cin >> choice;
		}
			switch (choice)
			{
			case 1:
				lookupbook();
				break;
			case 2:
				addbook();
				break;
			case 3:
				editbook();
				break;
			case 4:
				deletebook();
				break;
			case 5:
				cout << "you have selected item 5" << endl;
				break;
			}
	}
	
}

void lookupbook() 
{
	char YesNo = ' ';
	int row = 0;
	char searchtitle[STR_SIZE];
	cin.ignore();
	cout << "Find the book that you are searching for: ";
	cin.getline(searchtitle,STR_SIZE);
	strupper(searchtitle);
	for (int row = 0; row < NUM_BOOKS; row++) 
	{
		if (strstr(booktitle[row], searchtitle))
		{
			cout << "\nPossible Match found: " << booktitle[row] << "\n\n ";
			cout << "Is this a correct match? (Y or N) ";
			cin >> YesNo;
			while (YesNo != 'Y' && YesNo != 'y'&& YesNo != 'N' && YesNo != 'n') 
			{
				cout << "Please enter  Y or N \n\n";
				cout << "\nPossible Match found: " << booktitle[row] << "\n\n ";
				cout << "Is this a correct match? (Y or N) ";
				cin >> YesNo;
			}
			if (YesNo == 'Y' || YesNo == 'y')
			{
				bookInfo(isbn[row], booktitle[row], author[row], publisher[row], dateadded[row], qtyonhand[row], wholesale[row], retail[row]);
				break;
			}
		}
	}
	if (row > NUM_BOOKS -1)
		cout << "the book youre seacrhing for is not on the inventory" << endl;

}

void addbook()
{
	
	int row = 0;
	// char searchtitle[STR_SIZE];
	for (int row = 0; row < NUM_BOOKS; row++)
	{
		// find the first book whose element is 0;
		if (booktitle[row][0] == 0)
		{
			cin.ignore();
			cout << "Enter isbn: ";
			cin.getline(isbn[row], STR_SIZE);
			strupper(isbn[row]);
			cout << "Enter book title: ";
			cin.getline(booktitle[row], STR_SIZE);
			strupper(booktitle[row]);
			cout << "Enter author: ";
			cin.getline(author[row], STR_SIZE);
			strupper(author[row]);
			cout << "Enter publisher: ";
			cin.getline(publisher[row], STR_SIZE);
			strupper(publisher[row]);
			cout << "Enter date: ";
			cin.getline(dateadded[row], STR_SIZE);
			strupper(dateadded[row]);
			cout << "Enter quantity: ";
			cin >> qtyonhand[row];
			cout << "Enter wholesale: ";
			cin >> wholesale[row];
			cout << "Enter retail: ";
			cin >> retail[row];
			cout << "\n the record was entered";
			break;
		}//endif
		cout << " \n no more book may be available\n";
	}//end for loop
}

void editbook()
{
	char YesNo = ' ';
	int row = 0;
	char searchtitle[STR_SIZE];
	int choice = 0;
	cin.ignore();
	cout << "Edit the book that you are searching for: ";
	cin.getline(searchtitle, STR_SIZE);
	strupper(searchtitle);
	for (int row = 0; row < NUM_BOOKS; row++)
	{
		if (strstr(booktitle[row], searchtitle))
		{
			cout << "\nPossible Match found: " << booktitle[row] << "\n\n ";
			cout << "Is this a correct match? (Y or N) ";
			cin >> YesNo;
			while (YesNo != 'Y' && YesNo != 'y'&& YesNo != 'N' && YesNo != 'n')
			{
				cout << "Please enter  Y or N \n\n";
				cout << "\nPossible Match found: " << booktitle[row] << "\n\n ";
				cout << "Is this a correct match? (Y or N) ";
				cin >> YesNo;
			}
			if (YesNo == 'Y' || YesNo == 'y')
			{
				bookInfo(isbn[row], booktitle[row], author[row], publisher[row], dateadded[row], qtyonhand[row], wholesale[row], retail[row]);

				do
				{
					cout << "you may edit any of the following:";
					cout << "\n 1.ISBN";
					cout << "\n 2.Title";
					cout << "\n 3.Author";
					cout << "\n 4.Publisher";
					cout << "\n 5.Date added";
					cout << "\n 6.Quantity on hand";
					cout << "\n 7.wholesale";
					cout << "\n 8.retail";
					cout << "\n 9.exit";
					cout << "\n Please enter your choice";
					cin >> choice;
					while (choice < 1 || choice >9)
					{
						cout << "\n you have exceded the range from 1-9. Please reenter your choice:";
						cin >> choice;
					}
					switch (choice)
					{
					case 1:
						cout << "\n Current ISBN:";
						cout << isbn[row];
						cin.ignore();
						cout << "\n enter new isbn:";
						cin.getline(isbn[row], STR_SIZE);
						strupper(isbn[row]);
						break;
					case 2:
						cout << "\n Current Title:";
						cout << booktitle[row];
						cin.ignore();
						cout << "\n enter new title:";
						cin.getline(booktitle[row], STR_SIZE);
						strupper(booktitle[row]);
						break;
					case 3:
						cout << "\n Current Author:";
						cout << author[row];
						cin.ignore();
						cout << "\n enter new author:";
						cin.getline(author[row], STR_SIZE);
						strupper(author[row]);
						break;
					case 4:
						cout << "\n Current publisher:";
						cout << publisher[row];
						cin.ignore();
						cout << "\n enter new publisher:";
						cin.getline(publisher[row], STR_SIZE);
						strupper(publisher[row]);
						break;
					case 5:
						cout << "\n Current date:";
						cout << dateadded[row];
						cin.ignore();
						cout << "\n enter new date:";
						cin.getline(dateadded[row], STR_SIZE);
						strupper(dateadded[row]);
						break;
					case 6:
						cout << "\n Current quantity:";
						cout << qtyonhand[row];
						cin.ignore();
						cout << "\n enter new qty:";
						cin >> qtyonhand[row];
						break;
					case 7:
						cout << "\n Current wholesale:";
						cout << wholesale[row];
						cin.ignore();
						cout << "\n enter new wholesale:";
						cin >> wholesale[row];
						break;
					case 8:
						cout << "\n Current retail:";
						cout << retail[row];
						cin.ignore();
						cout << "\n enter new retail:";
						cin >> retail[row];
						break;
					}
				} while (choice != 9);
				break;
			} // end if yesno
		}
		
	}//end for loop
	if (row > NUM_BOOKS - 1)
		cout << "\n Sorry, No tile matching: " << searchtitle << " was found \n\n";
	
}  
void deletebook()
{

	int row = 0;
	char searchtitle[STR_SIZE];
	char YesNo;
	cin.ignore();
	cout << "Edit the book that you are searching for: ";
	cin.getline(searchtitle, STR_SIZE);
	strupper(searchtitle);
	for (int row = 0; row < NUM_BOOKS; row++)
	{
		if (strstr(booktitle[row], searchtitle))
		{
			cout << "\nPossible Match found: " << booktitle[row] << "\n\n ";
			cout << "Is this a correct match? (Y or N) ";
			cin >> YesNo;
			while (YesNo != 'Y' && YesNo != 'y'&& YesNo != 'N' && YesNo != 'n')
			{
				cout << "Please enter  Y or N \n\n";
				cout << "\nPossible Match found: " << booktitle[row] << "\n\n ";
				cout << "Is this a correct match? (Y or N) ";
				cin >> YesNo;
			}
			if (YesNo == 'Y' || YesNo == 'y')
			{

				bookInfo(isbn[row], booktitle[row], author[row], publisher[row], dateadded[row], qtyonhand[row], wholesale[row], retail[row]);
				cout << "would you like to delete entire record? Y/N:";
				cin >> YesNo;
				while (YesNo != 'Y' && YesNo != 'y'&& YesNo != 'N' && YesNo != 'n')
				{
					cout << "Please enter  Y or N \n\n";
					cout << "\nPossible Match found: " << booktitle[row] << "\n\n ";
					cout << "would you like to delete entire record? Y/N:";
					cin >> YesNo;

					if (YesNo == 'Y' || YesNo == 'y')
					{
						booktitle[row][0] = 0;
						isbn[row][0] = 0;
						cout << "\n record was deleted \n";
					}
					else
						cout << "\n reocrd ws not deleted";
					break;
				}

			}
			
		}
		if (row > NUM_BOOKS - 1)
			cout << "\n Sorry, No tile matching: " << searchtitle << " was found \n\n";
	}
}