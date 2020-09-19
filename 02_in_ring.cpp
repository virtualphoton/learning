/*
input:
	x, y, r, R
*/
#include <iostream>
#include <cmath>


int main(int argc, char *argv[]){
	double x, y, r, R;
	std::cin >> x >> y >> r >> R;
	double ro = std::sqrt(x*x + y*y);
	std::cout << ((ro >= r and ro <= R)? "yes":"no") << '\n'; 
	return 0;
}
