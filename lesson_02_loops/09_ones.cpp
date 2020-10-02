#include <iostream>

int main(){
	int n;
	std::cin >> n;
	int count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}
	std::cout << count;
}