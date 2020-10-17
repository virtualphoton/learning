#include <iostream>
#include "dyn_arrs_funcs.h"

int main() {
	int n, m, a, b;
	std::cout << "Input:\n\t#lines, #columns, min for random, max for random\n";
	std::cin >> n >> m >> a >> b;
	int ** arr = create_int_matrix(n, m);
	fill_random_int(arr, n, m, a, b);
	print_arr(arr, n, m, "matrix:", false);
	print_arr(flatten(arr, n, m, false), n * m, "merged lines:");
	print_arr(flatten(transpose(arr, n, m), m, n), n * m, "merged columns:");

	return 0;
}