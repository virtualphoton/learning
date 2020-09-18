#include <iostream>
#include <cmath>
#include <stdio.h>

using std::cin;

int main(int argc, char *argv[]){
	double a, b, c;
	cin >> a >> b >> c;
	if (a){
		double d = b*b - 4*a*c;
		if (d >= 0){
			double d1 = std::sqrt(d)/a/2,
						 b1 = -b/a/2;
			if (d)
				printf("%f %f\n",  b1-d1, b1+d1);
			else
				printf("%f\n",  b1-d1);
		} else
			printf("No real roots\n");
	} else {
		if (b){
			printf("%f\n",  -c/b);
		} else {
			if (c)
				printf("No roots");
			else
				printf("(-Inf;+Inf)");
		}
	}
}
