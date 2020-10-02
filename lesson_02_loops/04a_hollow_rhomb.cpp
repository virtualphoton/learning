#include <iostream>

using std::cout;

int main() {
	int n;
	std::cin >> n;

	int asterisk_width = 1;
	int shift = n - 1;
	int n1 = n * 2;
	for (int i = 1; i < n1; i += 1) {
		for (int j = 0; j < shift; j += 1) {
			cout << ' ';
		}
		cout << '*';
		for (int j = 2; j < asterisk_width; j += 1) {
			cout << ' ';
		}
		if (asterisk_width > 1)
			cout << '*';
		cout << '\n';
		if (i < n) {
			shift -= 1;
			asterisk_width += 2;
		} else {
			shift += 1;
			asterisk_width -= 2;
		}
	}
}