#include <iostream>

int main(){
	// want to have 010101...0101 number. Multiplied by 3, it gives 11...111
	unsigned int mask = ~0u/3;
	unsigned int n;
	std::cin >> n;
	n = ((n & mask) << 1) | ((n & (mask << 1)) >> 1);
	std::cout << n;
}