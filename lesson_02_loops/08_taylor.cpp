#include <iostream>
#include <cmath>

int main(){
	double x1, x2, dx, eps;
	std::cin >> x1 >> x2 >> dx >> eps;
	double add, sum, fact;
	for (double x = x1; x <= x2; x += dx) {
		fact = 2;
		add = x*x*x;
		sum = 0;
		while (abs(add) > eps) {
			sum += add;
			add *= -1 * x * x / fact / (fact+1);
			fact += 2;
		}
		std::cout << x << ' ' << sum << ' ' << std::sin(x) << ' ' << x - std::sin(x) << '\n';
	}
}