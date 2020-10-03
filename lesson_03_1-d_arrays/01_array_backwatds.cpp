#include <iostream>
#include <time.h>

int main(){
	srand(time(NULL));
	const int length = 15;
	int arr[length];
	for (int i = 0; i < length; i += 1) {
		arr[i] = rand();
	}

	for (int a : arr)
		std::cout << a << ' ';
	std::cout << '\n';

	//reverse
	int t;
	for (int i = length / 2; i < length; i += 1) {
		t = arr[i];
		arr[i] = arr[length - i - 1];
		arr[length - i - 1] = t;
	}

	for (int a : arr)
		std::cout << a << ' ';
	std::cout << '\n';
}