#include <iostream>

int main() {
	const int MAX_LEN = 8;
	char s[MAX_LEN];
	int base = 2;
	std::cin.getline(s, MAX_LEN);
	int length = strlen(s);
	int num = 0;
	for (int i = 0; i < length; i += 1) {
		num = num * base + (s[i] - '0');
	}
	std::cout << num;
	return 0;
}