/*
* let sh > 0 mean >>
*	  sh < 0 mean <<
*/

#include <iostream>

int main(){
	unsigned int n, sh;
	std::cin >> n >> sh;
	int size = sizeof(n)*8;
	if (sh >= 0)
		n = ((n & ~((~0u) << sh)) << (size - sh)) + (n >> sh);
	else
		n = ((n & ~((~0u) >> sh)) >> (size - sh)) + (n << sh);
	std::cout << n;
}