#include <iostream>
#include "bookinfo.h"
#include "cashier.h"
#include "reports.h"
#include "inventmenu.h"
using namespace std;
const int NUM_BOOKS = 20;
const int STR_SIZE = 51;	
char booktitle[NUM_BOOKS][STR_SIZE];
char isbn[NUM_BOOKS][STR_SIZE];
char author[NUM_BOOKS][STR_SIZE];
char publisher[NUM_BOOKS][STR_SIZE];
char dateadded[NUM_BOOKS][STR_SIZE];
int qtyonhand[NUM_BOOKS];
double wholesale[NUM_BOOKS];
double retail[NUM_BOOKS];
int main() 
{
	int choice = 0;
	while (choice != 4) 
	{
		cout << "Amazon Booksellers Main Menu\n\n";
		cout << "1. Cashier Module\n";
		cout << "2. Inventory Database Module\n";
		cout << "3. Report Module\n";
		cout << "4. Exit\n\n";
		cout << "Enter your choice:";
		cin >> choice;

		while (choice < 1 || choice > 4) 
		{
			cout << "\n please enter the range between 1-4" << endl;
			cout << "please enter your choice: ";
			cin >> choice;
		}
			switch (choice)
			{
			case 1:
				cashier();
				break;
			case 2:
				inventmenu();
				break;
			case 3:
				reports();
				break;
			case 4:
				cout << "you have selected item 4" << endl;
				break;
			}
	}
	return 0;
}