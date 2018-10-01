#include "cashier.h"
#include <iostream>
#include <cctype>
#include <iomanip>
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

void cashier()
{
	const double sales_tax = 0.06;
	string date;
	char isbnnumber[NUM_BOOKS][STR_SIZE];
	char thistitle[NUM_BOOKS][STR_SIZE];
	int quantitybooks[NUM_BOOKS];
	double unitprice[NUM_BOOKS];
	double subtotal[NUM_BOOKS];
	char transdate[STR_SIZE];
	double ordersalestax = 0;
	double runningtotal = 0;
	double grandtotal = 0;
	int validqty;
	char choice = 'Y';
	int counter = 0;
	string message;

	while (choice == 'y' || choice == 'Y')
	{
		cout << "Amazon Booksellers Main Menu\n";
		cout << "Cashier module\n\n";
		cout << "Enter date: ";
		cin.getline(transdate,STR_SIZE);
		cout << "Enter ISBN: ";
		cin.getline(isbnnumber[counter],STR_SIZE);
		strupper(isbnnumber[counter]);
		for (int row = 0; row < NUM_BOOKS; row++)
		{
			if (strcmp(isbnnumber[counter],isbn[row]) == 0)
			{
				cout << "Title: " << booktitle[row] << endl;
				cout << fixed << showpoint << setprecision(2) << "price: " << retail[row] << endl;
				unitprice[counter] = retail[row];
				strcpy(thistitle[counter],booktitle[row]);
				validqty = qtyonhand[row];
				if (validqty == 0)
				{
					cout << "the book is out of stock";
					return;
				}
				cout << "enter qunatity of books:";
				cin >> quantitybooks[counter];
				while (quantitybooks[counter] < 1 || quantitybooks[counter] > validqty)
				{
					if (quantitybooks[counter] < 1)
						cout << " \nthe books should be atleast 1.\n";
					else
						cout << "\n insufficient books in inventory";
					cout << "\nENter qunatity of books";
					cin >> quantitybooks[counter];
				}
				qtyonhand[row] -= quantitybooks[counter];
				counter++;
				message = "\n add another title to this order: ";
				choice = anothertransaction(message);
				cout << endl;
				break;
			}
			else if (row == NUM_BOOKS - 1)
			{
				cout << "\n the isbn number not found in the list of books";
				message = "\n Re-enter the ISBN number";
				choice = anothertransaction(message);
			}
		} //end for loop
	} // end while loop

	if (counter > 0)
	{
		cout << "Date" << date << " \n\n";
		cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal\n";
		cout << "__________________________________________________________________________________";
		cout << "\n\n\n";
		for (int i = 0; i < counter; i++)
		{
			subtotal[i] = quantitybooks[i] * unitprice[i];
			ordersalestax += subtotal[i] * sales_tax;
			runningtotal += subtotal[i];
			grandtotal = ordersalestax + runningtotal;
			// inline information
			cout << quantitybooks[i] << "\t";
			cout << left << setw(14) << isbn << "\t";
			cout << left << setw(26) << thistitle[i] << "\t";
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(2) << "$ " << unitprice[i] << "\t\t$ ";
			cout << setw(6) << subtotal[i] << "\n\n\n";
		}
		// calculated totals
		cout << "\t\tsubtotal\t\t\t\t\t\t$ ";
		cout << setw(6) << runningtotal << "\n";

		cout << "\t\tTax\t\t\t\t\t\t\t$ ";
		cout << setw(6) << ordersalestax << "\n";
		cout << "\t\ttotal\t\t\t\t\t\t\t$ ";
		cout << setw(6) << grandtotal << "\n\n";
		cout << "\n\nThank you for shopping at serendipity!\n";
		message = "process another transaction (Y/N)";
		choice = anothertransaction(message);
	} // end if counter

	cout << endl;
}
char anothertransaction(string message) 
{
	char choice;
	cout << message;
	cout << "\n Y = Yes, N = no \n";
	cout << "Enter your choice: ";
	cin >> choice;
	cin.ignore();
	while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') 
	{
		cout << "you have entered the invalid character: Please enter the Y or N \n";
		cout << message << endl;
		cin >> choice;
		cin.ignore();
	}
	return choice;
}