#include <iostream>
#include <stdio.h>

int main(){
	double x, eps;
	std::cin >> x >> eps;
	double sum = 0;
	double add = 1;
	while (std::abs(add) > eps) {
		sum += add;
		add *= x;
	}
	printf("sum is %f\ndifference with 1/(1-x) is %f\n", sum, std::abs(sum - 1 / (1 - x)));
}