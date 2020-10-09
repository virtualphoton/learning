#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>

void print_int_arr(int * arr, int len, char * msg){
	std::cout << msg << '\n';
	for (int i = 0; i < len; i += 1)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}

int main(){
	srand(time(NULL));
	int len;
	std::cout << "Enter length of arr:\n";
	std::cin >> len;
	int* a = new int[len];
	int* b = new int[len];
	for (int i = 0; i < len; i += 1){
		a[i] = rand()%201 - 100;
		b[i] = rand()%201 - 100;
	}
	print_int_arr(a, len, (char *)"First arr:");
	print_int_arr(b, len, (char *)"Second arr:");
	
	int* sum = new int[len];
	for (int i = 0; i < len; i += 1)
		sum[i] = a[i] + b[i];
	print_int_arr(sum, len, (char *)"Elementwise sum:");
	
	double norm = 0;
	for (int i = 0; i < len; i += 1)
		norm += sum[i]*sum[i];
	norm = std::sqrt(norm);
	
	std::cout << "Sum's norm is:\n" << norm << '\n';
	
	int scalar = 0;
	for (int i = 0; i < len; i += 1)
		scalar += a[i] * b[i];
	std::cout << "Scalar product is:\n" << scalar << '\n';
}
