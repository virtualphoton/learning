#include <iostream>

using std::cout;

int main(){
	int num;
	std::cin >> num;
	do {
		if (!num or num & 1 and num >> 1){
			cout << "no" << '\n';
			return 0;
		}
		num >>= 1;
	} while(num);
	cout << "yes" << '\n';
	return 0;
}
