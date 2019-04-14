#include "stdafx.h"
#include <iostream>
#include "Header.h"

using namespace std;

// ����� ������������� ��������� �������
void Sum(int *&arr, int &n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			sum = sum + arr[i];
		}
	}
	cout << "Sum '+' elements of array is " << sum << endl;

}

void Sum(int array[], int n)
{
}

// ����� ���� �� �����
void PrintMenu() {
	cout << "1. Enter array" << endl;
	cout << "2. Show array" << endl;
	cout << "3. Sum '+' elements of array " << endl;
	cout << "4. Add number X after first max element" << endl;
	cout << "5. Add element to array" << endl;
	cout << "6. Delete element from array" << endl;
	cout << "7. Exit" << endl << endl;
}

// �������� ������� � ������
void push_back(int *&arr, int &size, int value) {

	int *newArr = new int[size + 1];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}

	newArr[size] = value;
	size++;
	delete[] arr;
	arr = newArr;
}

// ������� ������� �� �������
void pop_back(int *&array, int &size) {
	size--;
	int *newArr = new int[size];
	for (int i = 0; i < size; i++) {
		newArr[i] = array[i];
	}
	array = newArr;
}

// �������� �������� X ����� ������� ������������� �������� �������
void pushX(int *&arr, int &size, int x) {
	int max = -100;
	int indexMax;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			indexMax = i;
		}
	}

	int *newArr = new int[size + 1];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	size++;
	delete[] arr;
	arr = newArr;

	for (int i = size; i > indexMax; i--)
	{
		do {
			arr[i] = arr[i - 1];

		} while (indexMax == i);
	}
	arr[indexMax + 1] = x;
}

