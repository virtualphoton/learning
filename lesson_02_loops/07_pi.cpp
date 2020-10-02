#include <iostream>

int main(){
	double eps;
	std::cin >> eps;
	eps = 4 / eps;
	double sum = 0;
	double add = 1;
	while (add < eps) {
		sum += 1/add;
		if (add > 0)
			add = -add - 2;
		else
			add = -add + 2;
	}
	std::cout << 4*sum;
}