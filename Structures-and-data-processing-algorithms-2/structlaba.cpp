// structlaba.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include "Header.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	int  n = 0;		// длина массива, которую задает пользователь
	int  check = 0;		// проверка условия
	int  ch;		// пункт меню
	char begin = 'y';	// выполнить еще одну операцию или нет
	int  value = 0;		// добавить элемент в массив
	int  flag = 0;		// проверка массива на пустоту
	int  x;			// добавить Х после первого максимального элемента массива

	// Ввод размера массива с защитой от дурака
	cout << "Enter size of array: ";
	while (check == 0) {
		if (cin >> n) {}
		else
		{
			cout << "Inccorect type!" << endl;
			exit(0);
		}
		if (n <= 100) {check++;}
		else {cout << "Sorry, your size must be <= 100, try again." << endl;}
	}

	int *arr = new int[n];	// создание массива, размер которого задал пользователь
	PrintMenu();
	cout << "Choose operation: ";

	do {
		cin >> ch;
		switch (ch) {
		case 1: // Инициализация массива
			cout << "Enter elements of array: ";
			for (int i = 0; i < n; i++)
				cin >> arr[i];
			flag++;
			break;

		case 2:	// Вывод массива на экран
			if (flag == 0) {
				cout << "Array is empty!" << endl;
				break;
			}
			for (int i = 0; i < n; i++)
				cout << arr[i] << " ";
			cout << endl;
			break;

		case 3:	// cумма положительных элементов массива
			Sum(arr, n);
			break;
		case 4:
			cout << "Enter the X number: ";
			cin >> x;
			pushX(arr, n, x);
			break;

		case 5: // добавить элемент в массив
			if (flag == 0) {
				cout << "Array is emty" << endl;
			}
			cout << "enter element to push: ";
			cin >> value;
			push_back(arr, n, value);
			break;

		case 6: // удалить элемент из массива
			if (flag == 0) {
				cout << "Array is emty" << endl;
			}
			pop_back(arr, n);
			break;

		case 7: // выход из программы
			exit(0);
			break;
		}

		cout << "Run the another operation? y/n" << endl;
		cin >> begin;

	} while (begin == 'y');

	delete[] arr; // очистка памяти
	return 0;
}




