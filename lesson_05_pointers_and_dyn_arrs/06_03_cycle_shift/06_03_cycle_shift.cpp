#include <iostream>
#include "dyn_arrs_funcs.h"

int main() {
	int n, a, b, m;
	std::cout << "Input:\n\tarr len, shift, min for random, max for random\n";
	std::cin >> n >> m >> a >> b;
	int * arr = new int[n];
	fill_random_int(arr, n, a, b);
	print_arr(arr, n, "arr:", false);

	arr = shift(arr, n, m);
	print_arr(arr, n, "shifted arr:");
	return 0;
}