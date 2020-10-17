#include <iostream>
#include "dyn_arrs_funcs.h"


int main() {
	int n, a, b;
	std::cout << "Input:\n\tarr len, min for random, max for random\n";
	std::cin >> n >> a >> b;
	int * arr = new int[n];
	fill_random_int(arr, n, a, b);
	print_arr(arr, n, "arr without changes:", false);
	int imin = 0, imax = 0;
	for (int i = 1; i < n; i += 1) {
		if (arr[i] > arr[imax])
			imax = i;
		if (arr[i] < arr[imin])
			imin = i;
	}
	int t = arr[imin];
	arr[imin] = arr[imax];
	arr[imax] = t;
	print_arr(arr, n, "changed arr:");
	return 0;
}