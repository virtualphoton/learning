#include "dyn_arrs_funcs.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

void fill_random_int(int * a, int size, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < size; i += 1)
		a[i] = rand() % (max - min + 1) + min;
}

void fill_random_int(int ** a, int lines, int columns, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < lines; i += 1)
		for (int j = 0; j < columns; j += 1)
			a[i][j] = rand() % (max - min + 1) + min;
}

int ** create_int_matrix(int lines, int columns) {
	int ** arr = new int * [lines];
	for (int i = 0; i < lines; i += 1)
		arr[i] = new int[columns];
	return arr;
}

void delete_int_matrix(int ** arr, int size) {
	for (int i = 0; i < size; i += 1)
		delete[] arr[i];
	delete[] arr;
}

void print_arr(int *arr, int size, std::string msg, bool delete_arr, bool print_msg) {
	if (print_msg)
		std::cout << msg << '\n';
	for (int i = 0; i < size; i += 1)
		std::cout << arr[i] << '\t';
	std::cout << '\n';
	if (delete_arr)
		delete[] arr;
}

void print_arr(int ** arr, int lines, int columns, std::string msg, bool delete_arr, bool print_msg) {
	if (print_msg)
		std::cout << msg << '\n';
	for (int i = 0; i < lines; i += 1)
		print_arr(arr[i], columns, "", false, false);
	std::cout << '\n';
	if (delete_arr)
		delete_int_matrix(arr, lines);
}

int * shift(int * arr, int size, int shift, bool del_arr) {
	shift = shift % size;
	if (shift < 0) {
		shift += size;
	}
	int * shifted_arr = new int[size];
	for (int i = 0; i < size; i += 1)
		shifted_arr[(i + shift) % size] = arr[i];

	if (del_arr)
		delete[] arr;
	return shifted_arr;
}

int ** transpose(int ** arr, int lines, int columns, bool del_arr) {
	int ** transposed = create_int_matrix(columns, lines);
	for (int i = 0; i < lines; i += 1)
		for (int j = 0; j < columns; j += 1)
			transposed[j][i] = arr[i][j];

	if (del_arr)
		delete_int_matrix(arr, lines);
	return transposed;
}

int * flatten(int ** arr, int lines, int columns, bool del_arr) {
	int *flattened_arr = new int[columns * lines];
	int index = 0;
	for (int i = 0; i < lines; i += 1)
		for (int j = 0; j < columns; j += 1) {
			flattened_arr[index] = arr[i][j];
			index += 1;
		}

	if (del_arr)
		delete_int_matrix(arr, lines);
	return flattened_arr;
}