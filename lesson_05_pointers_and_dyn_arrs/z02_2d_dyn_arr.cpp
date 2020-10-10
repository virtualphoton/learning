#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>


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
	int ** b = new int * [lines];
	int ** sum = new int * [lines];
	double ** a1 = new double * [lines];

	for (int i = 0; i < lines; i += 1) {
		a[i] = new int[columns];
		a1[i] = new double[columns];
		b[i] = new int[columns];
		sum[i] = new int[columns];
	}

	for (int i = 0; i < lines; i += 1)
		for (int j = 0; j < columns; j += 1) {
			a[i][j] = rand() % 201 - 100;
			a1[i][j] = a[i][j];
			b[i][j] = rand() % 201 - 100;
		}


	print_int_matrix(a, lines, columns, (char *)"First arr:");
	print_int_matrix(b, lines, columns, (char *)"Second arr:");

	for (int i = 0; i < lines; i += 1)
		for (int j = 0; j < columns; j += 1)
			sum[i][j] = a[i][j] + b[i][j];
	print_int_matrix(sum, lines, columns, (char *)"Elementwise sum:");

	int ** aT = new int * [columns];
	for (int i = 0; i < columns; i += 1)
		aT[i] = new int[lines];

	for (int i = 0; i < lines; i += 1)
		for (int j = 0; j < columns; j += 1)
			aT[j][i] = a[i][j];
	print_int_matrix(aT, columns, lines, (char *)"Transposed a:");


	int ** a_aT = new int * [lines];
	for (int i = 0; i < lines; i += 1)
		a_aT[i] = new int[lines];
	for (int i = 0; i < lines; i += 1)
		for (int j = 0; j < lines; j += 1) {
			a_aT[i][j] = 0;
			for (int k = 0; k < columns; k += 1) {
				a_aT[i][j] += a[i][k] * a[j][k];
			}
		}
	print_int_matrix(a_aT, lines, lines, (char *)"a*aT:");


	if (lines != columns)
		std::cout << "Determinator is not determined!" << '\n';
	else {

		int size = lines;
		long double det = 1;
		int zeros_in_col;
		bool need_swap = true;
		double temp;
		for (int diag = 0; diag < size; diag += 1) {


			zeros_in_col = 0;
			need_swap = true;
			for (int line = diag; line < size; line += 1)
				if (not a1[line][diag]) {
					zeros_in_col += 1;
					continue;
				} else {
					det *= a1[line][diag];
					for (int col_nested = size - 1; col_nested >= diag; col_nested -= 1)
						a1[line][col_nested] /= a1[line][diag];

					if (need_swap and zeros_in_col) {
						det *= -1;
						//swap to create diag later
						for (int col_nested = diag; col_nested < size; col_nested += 1) {
							temp = a1[diag][col_nested];
							a1[diag][col_nested] = a1[line][col_nested];
							a1[line][col_nested] = temp;
						}
					}
					need_swap = false;

				}

			if (zeros_in_col == size - diag) {
				det = 0;
				break;
			} else {
				for (int line = diag + 1; line < size; line += 1) {
					if (a1[line][diag])
						for (int col_nested = diag; col_nested < size; col_nested += 1) {
							a1[line][col_nested] -= a1[diag][col_nested];
						}
				}
			}
		}
		std::cout << "Determinant is: " << det << '\n';
	}

	delete_int_matrix(a, lines);
	delete_int_matrix(b, lines);
	delete_int_matrix(sum, lines);
	delete_int_matrix(aT, columns);
	for (int i = 0; i < lines; i += 1)
		delete[] a1[i];
	delete[] a1;
}