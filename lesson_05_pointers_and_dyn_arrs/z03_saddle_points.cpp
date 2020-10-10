#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <stdio.h>


void print_int_matrix(int ** arr, int lines, int cols, char * msg) {
	std::cout << msg << '\n';

	for (int i = 0; i < lines; i += 1) {
		for (int j = 0; j < cols; j += 1)
			std::cout << arr[i][j] << ' ';

		std::cout << '\n';
	}
	std::cout << '\n';
}
void delete_int_matrix(int ** arr, int size) {
	for (int i = 0; i < size; i += 1)
		delete[] arr[i];
	delete[] arr;
}

int main() {

	srand(time(NULL));
	int lines, columns;
	std::cout << "Enter num of lines and columns:\n";
	std::cin >> lines >> columns;
	int ** a = new int * [lines];
	int ** max_in_line = new int * [lines];
	int ** min_in_col = new int * [lines];

	for (int i = 0; i < lines; i += 1) {
		a[i] = new int[columns];
		max_in_line[i] = new int[columns];
		min_in_col[i] = new int[columns];
	}

	for (int i = 0; i < lines; i += 1)
		for (int j = 0; j < columns; j += 1)
			a[i][j] = rand() % 201 - 100;

	int max;
	for (int i = 0; i < lines; i += 1) {
		max = a[i][0];
		for (int j = 1; j < columns; j += 1)
			if (a[i][j] > max)
				max = a[i][j];
		for (int j = 0; j < columns; j += 1)
			max_in_line[i][j] = a[i][j] == max ? 1 : 0;
	}

	int min;
	for (int j = 0; j < columns; j += 1) {
		min = a[0][j];
		for (int i = 1; i < lines; i += 1)
			if (a[i][j] < min)
				min = a[i][j];
		for (int i = 0; i < lines; i += 1)
			min_in_col[i][j] = a[i][j] == min ? 1 : 0;
	}
	print_int_matrix(a, lines, columns, (char *)"Arr:");


	bool found = false;
	for (int i = 0; i < lines; i += 1)
		for (int j = 0; j < columns; j += 1)
			if (max_in_line[i][j] and min_in_col[i][j]) {
				printf("On position: %d, %d; number is: %d\n", i, j, a[i][j]);
				found = true;
			}
	if (not found) {
		std::cout << "no saddle points";
	}
	delete_int_matrix(a, lines);
	delete_int_matrix(max_in_line, lines);
	delete_int_matrix(min_in_col, lines);
}