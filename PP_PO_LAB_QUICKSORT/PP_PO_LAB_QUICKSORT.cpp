#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <string>
#include <conio.h>
#include <sstream>


using namespace std;

int n;

double t, start, stop;
void QuickSort(int tab[], int l, int r);
void QuickSortIterative(int* liczba, int l, int r);
int Partition(int* liczba, int left, int right);


int main()
{


	/*
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
	tab = new int[(i];

	for (int j = 0; j <= i; j++)
	{
	tab[j] = vec[j];
	}
	*/


	int i;
	cout << "How many elements do you want to sort: ";
	cin >> n;
	int *tab;
	tab = new int[n];
	
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		tab[i] = rand() % 100;
	}
	system("pause");
	
	cout << endl << "Przed sortowaniem:" << endl;
	for (int j = 0; j < n; j++)
	{
		if (j<n-1)
		{
			cout << tab[j] << ", ";
		}
		else
		{
			cout << tab[j] << endl << endl;
		}
	}
	system("pause");

	int option;
	cout << endl << endl << "1.Recursive" << endl << "2.Iterative" << endl << "Choose quicksort method: ";
	cin >> option;
	switch (option)
	{
	case 1:
		cout << endl << endl << "Sorting data using quicksort. Please wait!" << endl;
		start = clock();
		QuickSort(tab, 0, n + 1);
		stop = clock();
		t = (double)(stop - start) / (CLOCKS_PER_SEC / 1000);
		cout << endl << "Time needed to sort with quicksort: " << t << " s" << endl;
		Sleep(1000);
		break;
	case 2:
		cout << endl << endl << "Sorting data using quicksort. Please wait!" << endl;
		start = clock();
		QuickSortIterative(tab, 0, n-1);
		stop = clock();
		t = (double)(stop - start) / (CLOCKS_PER_SEC / 1000);
		cout << endl << "Time needed to sort with quicksort: " << t << " s" << endl;
		Sleep(1000);

		break;
	default:
		cout << "Error";
		exit(0);
		break;
	}


	/*
	cout << endl << endl << "Sorting data using quicksort. Please wait!" << endl;
	start = clock();
	QuickSort(tab, 0, n-1);
	stop = clock();
	t = (double)(stop - start) / (CLOCKS_PER_SEC / 1000);
	cout << endl << "Time needed to sort with quicksort: " << t << " s" << endl;
	Sleep(1000);
	*/


	//// SPRAWDZENIE TABLICY ////
	cout << "Sprawdzenie tablicy:" << endl;
	for (int j = 0; j < n; j++)
	{

		if (j < n - 1)
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
	cout << "How many elements do you want to sort?: ";
	cin >> n;


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


	delete tab;
}



void QuickSort(int *tab, int l, int r)
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
	} while (i <= j);
	if (j > l) QuickSort(tab, l, j);
	if (i < r) QuickSort(tab, i, r);
}

int Partition(int* liczba, int left, int right) {
	int x = liczba[right];
	int i = (left - 1);

	for (int j = left; j <= right - 1; ++j)
	{
		if (liczba[j] <= x)
		{
			++i;
			swap(liczba[i], liczba[j]);
		}
	}

	swap(liczba[i + 1], liczba[right]);

	return (i + 1);
}

void QuickSortIterative(int* liczba, int l, int r) {
	int i = l;
	int j = r - 1;
	int top = -1;
	int* stack = new int[r];

	stack[++top] = i;
	stack[++top] = j;

	while (top >= 0)
	{
		j = stack[top--];
		i = stack[top--];

		int p = Partition(liczba, i, j);

		if (p - 1 > i)
		{
			stack[++top] = i;
			stack[++top] = p - 1;
		}

		if (p + 1 < j)
		{
			stack[++top] = p + 1;
			stack[++top] = j;
		}
	}

	delete stack;
}
