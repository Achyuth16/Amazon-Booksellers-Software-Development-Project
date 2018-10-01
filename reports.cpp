#include "reports.h"
#include <iostream>
#include <string>
#include <iomanip>
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

void reports()
{
	int choice = 0;
	while (choice != 7)
	{
		cout << "Amazon Booksellers reports\n\n";
		cout << "1. Inventory listing\n";
		cout << "2. Inventory wholesale value\n";
		cout << "3. Inventory retail value\n";
		cout << "4. Listing by quantity\n";
		cout << "5. Listing by cost\n";
		cout << "6. Listing by age\n";
		cout << "7. Return to Main Menu\n\n";
		cout << "Enter your choice:";
		cin >> choice;
		while (choice < 1 || choice > 7) 
		{
		cout << "\n please enter the range between 1-7" << endl;
		cout << "please enter your choice: ";
		cin >> choice;
	    }
			switch (choice)
			{
			case 1:
				replisting();
				break;
			case 2:
				repwholesale();
				break;
			case 3:
				repretail();
				break;
			case 4:
				repqty();
				break;
			case 5:
				repcost();
				break;
			case 6:
				repage();
				break;
			case 7:
				cout << "you have selected item 7" << endl;
				break;
			}
	}

}

void replisting() 
{
	char end[] = { '\0' };
	char date[STR_SIZE];
	cout << "\n\n Enter todays date: ";
	cin >> date;
	cout << endl;
	cout << "\n\n\t\tAmazon Book sellers inventory report\n";
	cout << "Date: " << date;
	for (int i = 0; i < NUM_BOOKS; i++) 
	{
		if (strcmp(isbn[i], end) != 0) //not printinfg empty records
		{
			cout << "\n_________________________________________________";
			cout << "\n\nTitle: \t\t\t " << booktitle[i];
			cout << "\nISBN: \t\t\t " << isbn[i];
			cout << "\nAuthor: \t\t " << author[i];
			cout << "\nPublisher: \t\t " << publisher[i];
			cout << "\nDate: \t\t\t " << dateadded[i];
			cout << fixed << showpoint << left << setprecision(2);
			cout << "\nQuantity on hand: \t " << qtyonhand[i];
			cout << "\nwholesale cost: \t$ " << wholesale[i];
			cout << "\nretail cost: \t\t$ " << retail[i];

		}
	}
	cout << "\n\n_________________________________________________________";
	cout << "\n\n End of inventory report \n\n\n";
	//pause reports on screen
	cout << "press enter to continue";
	cin.ignore();
	cin.get();
}
void repwholesale()
{
	char end[] = { '\0' };
	char date[STR_SIZE];
	cout << "\n\n Enter todays date: ";
	cin >> date;
	cout << endl;
	cout << "\n\n\t\tAmazon Book sellers wholesale report\n";
	cout << "Date: \t\t " << date;
	cout << "\n\tTitle\t\t\t ISBN\t\tQuantity\tWholesale\n";
	cout << "\t________________________________________________________\n\n";
	double itemsubtotal = 0;
	double subtotal = 0;
	for (int i = 0; i < NUM_BOOKS; i++) 
	{
		if (strcmp(isbn[i], end) != 0) //not printinfg empty records
		{
			cout << "\n\t" << left << setw(26) << booktitle[i];
			cout << left << setw(26) << isbn[i];
			cout << right << setw(6) << qtyonhand[i] << "\t";
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(6) << "\t$ " << wholesale[i];
			itemsubtotal = qtyonhand[i] * wholesale[i];
			subtotal += itemsubtotal;		
		}
	}
	cout << "\n\n\n\t Total wholesale value: $ " << subtotal << endl;
	cout << "\t_____________________________________________________\n";
	cout << "\n\t End of wholesale report \n\n\n";

	//pause report on screen
	cout << "press enter to continue";
	cin.ignore();
	cin.get();
}
void repretail()
{
	char end[] = { '\0' };
	char date[STR_SIZE];
	cout << "\n\n Enter todays date: ";
	cin >> date;
	cout << endl;
	cout << "\n\n\t\tAmazon Book sellers retail report\n";
	cout << "Date: \t\t " << date;
	cout << "\n\tTitle\t\t\t ISBN\t\tQuantity\tRetaill\n";
	cout << "\t________________________________________________________\n\n";
	double itemsubtotal = 0;
	double subtotal = 0;
	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(isbn[i], end) != 0) //not printinfg empty records
		{
			cout << "\n\t" << left << setw(26) << booktitle[i];
			cout << left << setw(26) << isbn[i];
			cout << right << setw(6) << qtyonhand[i] << "\t";
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(6) << "\t$ " << retail[i];
			itemsubtotal = qtyonhand[i] * retail[i];
			subtotal += itemsubtotal;
		}
	}
	cout << "\n\n\n\t Total wholesale value: $ " << subtotal << endl;
	cout << "\t_____________________________________________________\n";
	cout << "\n\t End of retail report \n\n\n";

	//pause report on screen
	cout << "press enter to continue";
	cin.ignore();
	cin.get();
}
void repqty()
{
	int id[NUM_BOOKS]; //array to track original subscripts
	int* idptr[NUM_BOOKS]; //pointer to tracking array
	int* qtyptr[NUM_BOOKS]; //array of pointers to qtyonhand array
	for (int i = 0; i < NUM_BOOKS; i++) 
	{
		id[i] = i;
		idptr[i] = &id[i];
		qtyptr[i] = &qtyonhand[i];
	}
	int startscan;
	int maxindex;
	int* tempid;
	int* maxvalue;
	// selection sort to do qtyonhand in descending order
	for (startscan = 0; startscan < NUM_BOOKS - 1; startscan++) 
	{
		maxindex = startscan;
		maxvalue = qtyptr[startscan];
		tempid = idptr[startscan];
		for (int index = startscan + 1; index < NUM_BOOKS; index++) 
		{
			if (*(qtyptr[index]) > *maxvalue) 
			{
				maxvalue = qtyptr[index];
				tempid = idptr[index];
				maxindex = index;
			}
		}
		qtyptr[maxindex] = qtyptr[startscan];
		idptr[maxindex] = idptr[startscan];
		qtyptr[startscan] = maxvalue;
		idptr[startscan] = tempid;
	}
	char date[STR_SIZE];
	cout << "\n\n Enter todays date: ";
	cin >> date;
	cout << endl;
	cout << "\n\n\t\tAmazon Book sellers quantity report\n";
	cout << "Date: \t\t " << date;
	cout << "\n\tTitle\t\t\t ISBN\t\tQuantity\n";
	cout << "\t_____________________________________________________\n\n";
	char end[] = { '\0' };
	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(isbn[j], end) != 0) //not printinfg empty records
		{
			cout << "\n\t" << left << setw(6) << booktitle[*(idptr[j])];
			cout << left << setw(14) << isbn[*(idptr[j])];
			cout << right << setw(6) << *qtyptr[j] << "\n";
		}	
	}
	cout << "\t_____________________________________________________\n";
	cout << "\n\t End of quantity report \n\n\n";

	//pause report on screen
	cout << "press enter to continue";
	cin.ignore();
	cin.get();
}

void repcost()
{
	int id[NUM_BOOKS]; //array to track original subscripts
	int* idptr[NUM_BOOKS]; //pointer to tracking array
	double* wholeptr[NUM_BOOKS]; //array of pointers wholesale array
	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idptr[i] = &id[i];
		wholeptr[i] = &wholesale[i];
	}
	int startscan;
	int maxindex;
	int* tempid;
	double* maxvalue;

	for (startscan = 0; startscan < NUM_BOOKS - 1; startscan++)
	{
		maxindex = startscan;
		maxvalue = wholeptr[startscan];
		tempid = idptr[startscan];
		for (int index = startscan + 1; index < NUM_BOOKS; index++)
		{
			if (*(wholeptr[index]) > *maxvalue)
			{
				maxvalue = wholeptr[index];
				tempid = idptr[index];
				maxindex = index;
			}
		}
		wholeptr[maxindex] = wholeptr[startscan];
		idptr[maxindex] = idptr[startscan];
		wholeptr[startscan] = maxvalue;
		idptr[startscan] = tempid;
	}
	char date[STR_SIZE];
	cout << "\n\n Enter todays date: ";
	cin >> date;
	cout << endl;
	cout << "\n\n\t\tAmazon Book sellers cost report\n";
	cout << "Date: \t\t " << date;
	cout << "\n\tTitle\t\t\t ISBN\t\tQuantity\tWholesale\n";
	cout << "\t_____________________________________________________\n\n";
	char end[] = { '\0' };
	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(isbn[j], end) != 0) //not printinfg empty records
		{
			cout << "\n\t" << left << setw(6) << booktitle[*(idptr[j])];
			cout << left << setw(14) << isbn[*(idptr[j])];
			cout << fixed << showpoint << right << setprecision(2);
			cout << right << setw(6) << qtyonhand[j];
			cout << setw(6) << "\t$ " << *wholeptr[j] << "\n";
		}
	}
	cout << "\t_____________________________________________________\n";
	cout << "\n\t End of cost report \n\n\n";

	//pause report on screen
	cout << "press enter to continue";
	cin.ignore();
	cin.get();

}

void repage()
{
	int id[NUM_BOOKS]; //array to track original subscripts
	int* idptr[NUM_BOOKS]; //pointer to tracking array
	char* dateptr[NUM_BOOKS]; //array of pointers wholesale array
	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idptr[i] = &id[i];
		dateptr[i] = dateadded[i];
	}
	int startscan;
	int maxindex;
	int* tempid;
	char* maxvalue;

	for (startscan = 0; startscan < NUM_BOOKS - 1; startscan++)
	{
		maxindex = startscan;
		maxvalue = dateptr[startscan];
		tempid = idptr[startscan];
		for (int index = startscan + 1; index < NUM_BOOKS; index++)
		{
			if (*(dateptr[index]) > *maxvalue)
			{
				maxvalue = dateptr[index];
				tempid = idptr[index];
				maxindex = index;
			}
		}
		dateptr[maxindex] = dateptr[startscan];
		idptr[maxindex] = idptr[startscan];
		dateptr[startscan] = maxvalue;
		idptr[startscan] = tempid;
	}
	char date[STR_SIZE];
	cout << "\n\n Enter todays date: ";
	cin >> date;
	cout << endl;
	cout << "\n\n\t\tAmazon Book sellers date added report\n";
	cout << "Date: \t\t " << date;
	cout << "\n\tTitle\t\t\t ISBN\t\tQuantity\tDateadded\n";
	cout << "\t_____________________________________________________\n\n";
	char end[] = { '\0' };
	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(isbn[j], end) != 0) //not printinfg empty records
		{
			cout << "\n\t" << left << setw(6) << booktitle[*(idptr[j])];
			cout << left << setw(14) << isbn[*(idptr[j])];
			cout << fixed << showpoint << right << setprecision(2);
			cout << right << setw(6) << qtyonhand[j];
			cout << setw(6) << "\t$ " << dateadded[*idptr[j]] << "\n";
		}
	}
	cout << "\t_____________________________________________________\n";
	cout << "\n\t End of date report \n\n\n";

	//pause report on screen
	cout << "press enter to continue";
	cin.ignore();
	cin.get();
}