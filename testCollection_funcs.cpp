// tests collection implementation
// Mikhail Nesterenko
// 4/6/2022

#include "collection.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
//
// Function definitions
//
void output(const double* colPtr, const int size) {
	for (int i = 0; i < size; ++i) {
		cout << colPtr[i] << " ";
	}
}

double value(const double* colPtr, const int size) {
	double new_value = 0.0;
	for (int i = 0; i < size; ++i) {
		new_value += colPtr[i];
	}
	return new_value;
}

int check(const double* colPtr, const double number, const int size) {
	int temp_number;
	for (int i = 0; i < size; ++i) {
		if (colPtr[i] == number) {
			return i;
		}
	}
	return -1;
}

void addNumber(double*& colPtr, const double number, int& size) {
	int index_check = check(*&colPtr, number, size);
	if (index_check == -1) {
		++size;
		double* tmp = new double[size];
		for (int i = 0; i < size; ++i) {
			tmp[i] = colPtr[i];
		}
		tmp[size - 1] = number;
		delete[] colPtr;
		colPtr = tmp;
	} else {
		cout << "Duplicate!" << endl;
	}
}

void removeNumber(double*& colPtr, const double number, int& size) {
	int index_check_2 = check(*&colPtr, number, size);
	if (index_check_2 != -1) {
		bool found = false;
		--size;
		double* tmp = new double[size];
		for (int i = 0; i < size + 1; ++i) {
			if (colPtr[i] == number) {
				found = true;
			}
			else {
				if (found == false) {
					tmp[i] = colPtr[i];
				}
				else {
					tmp[i - 1] = colPtr[i];
				}
			}
		}
		delete[] colPtr;
		colPtr = tmp;
	} else {
		cout << "That number is not on the array!" << endl;
	}
}