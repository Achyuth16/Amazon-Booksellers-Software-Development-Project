#include "bookinfo.h"
#include <iostream>
using namespace std;
const int STR_SIZE = 51;
void bookInfo(char isbn[STR_SIZE], char title[STR_SIZE], char author[STR_SIZE], char publisher[STR_SIZE], char date[STR_SIZE], int qty, double wholesale, double retail)
{
	cout << "\t\t\tAmazon Booksellers Book information\n\n";
	cout << "ISBN:" << isbn << endl;
	cout << "Title:" << title << endl;
	cout << "Author:" << author << endl;
	cout << "publisher:" << publisher << endl;
	cout << "Date added:" << date << endl;
	cout << "Quantity-On-Hand:" << qty << endl;
	cout << "Wholesale cost:" << wholesale << endl;
	cout << "Retail price:" << retail << endl;	
}