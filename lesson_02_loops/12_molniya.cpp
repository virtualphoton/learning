#include <iostream>

int main(){
	unsigned int a, b, n;
	std::cin >> a >> b >> n;
	if (2 * n <= sizeof(a)*8) {
		unsigned int result = 0;
		unsigned int end_shift = 0;
		for (int i = 0; i < n; i += 1) {
			result |= (b & 1) << end_shift;
			result |= (a & 1) << (end_shift + 1);
			a >>= 1;
			b >>= 1;
			end_shift += 2;
		}
		std::cout << result;
	}
}