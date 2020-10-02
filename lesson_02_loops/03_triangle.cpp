#include <iostream>

using std::cout;

int main(){
	int n;
	std::cin >> n;

	int asterisk_width = 1;
	int shift = n - 1;
	for (int i = 1; i <= n; i += 1) {
		for (int j = 0; j < shift; j += 1) {
			cout << ' ';
		}
		for (int j = 0; j < asterisk_width; j += 1) {
			cout << '*';
		}
		cout << '\n';
		shift -= 1;
		asterisk_width += 2;
	}
}