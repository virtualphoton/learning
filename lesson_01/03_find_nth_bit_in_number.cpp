#include <iostream>

int main(){
	int num, pos;
	std::cin >> num >> pos;
	std::cout << ((num & (1 << pos)) >> pos) << '\n';
	return 0;
}