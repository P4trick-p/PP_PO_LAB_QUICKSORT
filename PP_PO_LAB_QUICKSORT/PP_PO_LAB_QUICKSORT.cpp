// PP_PO_LAB_QUICKSORT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

char x;
int n, liczba;
double t, start, stop;
void quicksort(int tab[], int l, int r);

int main()
{
	/*
	string rawinput;
	vector<String> numbers;
	while (getline(cin, rawinput, ' '))
	{
		numbers.push_back(rawinput);
	}
	*/
	int opt;
	cout << "Hello World" << endl;
	Sleep(1000);
	system("cls");
	cout << "How many elements do you want to sort?: ";
	cin >> n;
	system("cls");
	int *tab;
	tab = new int[n];
	
	cout << "MENU" << endl;
	cout << "1.MANUAL INPUT" << endl;
	cout << "2.RANDOM INPUT" << endl;
	cout << "Choose option: ";
	cin >> opt;
	system("cls");
	
	if (opt==1)
	{
		///////////		MANUAL	INPUT	///////////
		
		for (int i = 0; i < n; i++)
		{
			cout << "Enter values separated with commas: ";
			if (i < n - 1)
			{
				cin >> tab[i] >> x;
				system("cls");
			}
			else
			{
				cin >> tab[i];
				system("cls");
			}
		}
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

	cout << "Przed sortowaniem:" << endl;
	for (int i = 0; i < n; i++)
	{
		if (i<n - 1)
		{
			cout << tab[i] << ", ";
		}
		else
		{
			cout << tab[i] << endl << endl;
		}
	}
	cout << "Press ENTER.";
	_getch();
	
	cout << "Sorting data using quicksort. Please wait!" << endl;
	start = clock();
	quicksort(tab, 0, n - 1);
	stop = clock();
	t = (double)(stop - start) / (CLOCKS_PER_SEC / 1000);
	cout << endl << "Time needed to sort with quicksort: " << t << " s" << endl;
	Sleep(1000);
	
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
	
	





/*////////////////////////////////////////////////////////////////
int x, i = 0;
char y;               //to store commas
int arr[50];
while (!cin.eof()) {
cin >> x >> y;
arr[i] = x;
i++;
}

for (int j = 0; j<i; j++)
cout << arr[j];     //array contains only the integer part
return 0;
*/////////////////////////////////////////////////////////////////
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
	
	
	/*////////////////////////////////
	for (int i = 0; i < n; i++)
	{
		pivot = tab[n - 1];
		if (pivot < tab[i])
		{
			swap(tab[i], tab[j]);
		}
		for (int i = 0; i < n; i++)
		{
			cout << tab[i] << " ";
			cout << tab[j] << " ";
		}
		system("pause");
		system("cls");
	}
	*////////////////////////////////
}