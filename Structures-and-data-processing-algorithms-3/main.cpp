#include <iostream>

using namespace std;

template <typename IN>
void enter_mass(IN ** &mass, int n, int m)//функция вывода
{
	
		for (int i = 0; i < n; i++) //цикл вводит матрицу
		{
			cout << "Row " << (i + 1) << endl;
			for (int j = 0; j < m; j++)
			{
				cout << "Element " << (j + 1) << endl;
				if (cin >> mass[i][j]) {}
				else
				{
					cout << "ERROR!";
					exit(0);
				}
			}
		}
	
}

template<typename OUT>
void print_mass(OUT ** &mass, int n, int m)//функция вывода
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mass[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template <typename SOR>
SOR sort_mass(SOR ** &mass, int n, int m)
{
	SOR c;
	for (int k = 0; k < n; k++)
	{
		for (int a = 1; a < m; a++)
		{
			for (int b = m - 1; b >= a ; b--)
			{
				if (mass[k][b-1] > mass[k][b])
				{
					c = mass[k][b - 1];
					mass[k][b - 1] = mass[k][b];
					mass[k][b] = c;
				}
			}
		}
	}
	return *mass[0];
}

template <typename DEL>
void deletee(DEL ** &mass, int j)
{
	for (int i = 0; i < j; i++)
	{
		delete[] mass[i];
	}
	delete[] mass;
}

void print_menu()
{
	cout << "....................." << endl;
	cout << ":  1. Matrix INT    :" << endl;
	cout << ":  2. Matrix DOUBLE :" << endl;
	cout << ":...................:" << endl;
}

int main()
{
	int temp = 0;
	int choose;
	int check = 0;
	int n = 0; int m = 0;

	print_menu();

	cout << "Enter N: ";
	if (cin >> n && n > 0) {}
	else
	{
		cout << "ERROR!" << endl;
		exit(0);
	}

	cout << "Enter M: ";
	if (cin >> m && m > 0) {}
	else
	{
		cout << "ERROR!" << endl;
		exit(0);
	}

	// инициализация массивов
	int **arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}

	double **arr2 = new double*[n];
	for (int i = 0; i < n; i++)
	{
		arr2[i] = new double[m];
	}

	cout << "Choose type of matrix: ";

	while (check == 0)
	{

		if (cin >> choose && choose > 0 && choose < 3) { check++; }
		else
		{
			cout << "Incorrect data entry! Restart the programe." << endl;
			exit(0);
		}

	}

	switch (choose)
	{
	case 1:
		cout << "Enter matrix 3x3 type INT" << "\n";
		enter_mass(arr, n, m);							// функция ввода int

		cout << "Show matrix" << "\n";
		print_mass(arr, n, m);							//функция для вывода записи матрицы int

		sort_mass(arr, n, m);

		cout << "Sorting matrix" << "\n";
		print_mass(arr, n, m);							//функция для вывода записи матрицы int

		deletee(arr, n);
		break;

	case 2:
		cout << "Enter matrix 3x3 type DOUBLE" << endl;
		enter_mass(arr2, n, m);

		cout << "Show matrix" << "\n";
		print_mass(arr2, n, m);

		sort_mass(arr2, n, m);

		cout << "Sorting matrix" << "\n";
		print_mass(arr2, n, m);

		deletee(arr2, n);
		break;
	default:
		cout << "This symbol is not supported!" << endl;
		break;
	}

	return 0;
}
