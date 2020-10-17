#include <iostream>
#include "dyn_arrs_funcs.h"


int main() {
	int n, m, a, b;
	std::cout << "Input:\n\t#lines, #columns, min for random, max for random\n";
	std::cin >> n >> m >> a >> b;
	int ** arr = create_int_matrix(n, m);
	int ** shift1 = new int * [n];
	int ** shift2 = new int * [m];
	int ** transposed = new int * [m];

	fill_random_int(arr, n, m, a, b);
	print_arr(arr, n, m, "arr:", false);

	for (int i = 0; i < n; i += 1)
		shift1[i] = shift(arr[i], m, i, false);
	print_arr(shift1, n, m, "shifted by lines:");

	transposed = transpose(arr, n, m);
	for (int i = 0; i < m; i += 1)
		shift2[i] = shift(transposed[i], n, i, false);
	print_arr(transpose(shift2, m, n), n, m, "shifted by columns:");
	delete_int_matrix(transposed, m);
	return 0;
}