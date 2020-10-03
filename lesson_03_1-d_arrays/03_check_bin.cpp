#include <iostream>

int main() {
	char s[64];
	std::cin.getline(s, 64);
	int length = strlen(s);
	char c;
	for (int i = 0; i < length; i += 1) {
		c = s[i];
		if (c == '0' or c == '1' or not i and c == '-')
			continue;
		std::cout << "no" << '\n';
		return 0;
	}
	std::cout << "yes" << '\n';
	return 0;
}