#include <iostream>
#include <cmath>

int main(){
	double x;
	int n;
	std::cin >> x >> n;
	double result = x;
	for (int i = 0; i < n; i++) {
		result = std::sin(result);
	}
	std::cout << result << '\n';
}