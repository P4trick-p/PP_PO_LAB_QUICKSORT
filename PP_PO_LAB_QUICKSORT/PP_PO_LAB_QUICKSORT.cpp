

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <string>
#include <conio.h>
#include <sstream>


using namespace std;

double t, start, stop;
void quicksort(int tab[], int l, int r);


int main()
{
	
	string input_str;
	vector<int> vec;
	
	getline(cin, input_str);

	stringstream ss(input_str);

	int i;

	while (ss >> i)
	{
		vec.push_back(i);

		if (ss.peek() == ',')
			ss.ignore();
	}
	cout << endl;

	int *tab;
	tab = new int[i+2];

	for (int j = 0; j < i + 2; j++)
	{
		tab[j] = vec[j];
	}

	system("pause");

	cout << endl << "Przed sortowaniem:" << endl;
	for (int j = 0; j < i+2; j++)
	{
		if (j<i + 1)
		{
			cout << tab[j] << ", ";
		}
		else
		{
			cout << tab[j] << endl << endl;
		}
	}
	system("pause");

	cout <<endl<<endl<< "Sorting data using quicksort. Please wait!" << endl;
	start = clock();
	quicksort(tab, 0, i + 1);
	stop = clock();
	t = (double)(stop - start) / (CLOCKS_PER_SEC / 1000);
	cout << endl << "Time needed to sort with quicksort: " << t << " s" << endl;
	Sleep(1000);

	//// SPRAWDZENIE TABLICY ////
	cout << "Sprawdzenie tablicy:" << endl;
	for (int j = 0; j < i+2; j++)
	{

		if (j < i + 1)
		{
			cout << tab[j] << "," << " ";
		}
		else
		{
			cout << tab[j];
		}
	}
	cout << endl << endl;
	system("pause");
	return 0;

	/*////////////////////////////////////////////////////////
	int opt;
	cout << "How many elements do you want to sort?: ";
	cin >> n;
	
	cout << "MENU" << endl;
	cout << "1.MANUAL INPUT" << endl;
	cout << "2.RANDOM INPUT" << endl;
	cout << "Choose option: ";
	cin >> opt;
	system("cls");

	if (opt==1)
	{
		///////////		MANUAL	INPUT	///////////
		...
		..
		.
	}
	if (opt==2)
	{
	
		///////////		RANDOM	INPUT	///////////
		
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			liczba = rand() % 100;
			tab[i] = liczba;
		}
	
	}
	
	//// SPRAWDZENIE TABLICY ////
	cout << "Sprawdzenie tablicy" << endl;
	for (int i = 0; i < n; i++)
	{
		
		if (i < n - 1)
		{
			cout << tab[i] << "," << " ";
		}
		else
		{
			cout << tab[i];
		}
	}
	cout << endl;
	system("pause");
	return 0;
	*/////////////////////////////////////////////////////////
}



void quicksort(int *tab, int l, int r)
{
	int t = tab[(l + r) / 2];
	int i, j, x;
	i = l;
	j = r;
	do
	{
		while (tab[i] < t) i++;
		while (tab[j] > t) j--;
		if (i <= j)
		{
			swap(tab[i], tab[j]);
			i++;
			j--;
		}
	} 
	while (i <= j);
	if (j > l) quicksort(tab, l, j);
	if (i < r) quicksort(tab, i, r);
}
