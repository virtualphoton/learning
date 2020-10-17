#include <iostream>
#include "dyn_arrs_funcs.h"

int main() {
	int n, a, b;
	std::cout << "Input:\n\tarr len, min for random, max for random\n";
	std::cin >> n >> a >> b;
	int * arr = new int[n];
	fill_random_int(arr, n, a, b);
	print_arr(arr, n, "arr:", false);

	double mean = 0;
	double num_of_mean = 0;
	for (int i = 0; i < n; i += 1)
		if (arr[i] > 0 and arr[i] % 2 == 0) {
			mean = mean * (num_of_mean / (num_of_mean + 1)) + arr[i] / (num_of_mean + 1);
			num_of_mean += 1;
		}
	delete[] arr;
	std::cout << "mean: " << mean << '\n';
}