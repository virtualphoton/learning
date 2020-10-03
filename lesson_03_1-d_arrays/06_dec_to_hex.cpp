//nothing new, just copy of previous problem with hard-coded new base

#include <iostream>

int main() {
	const int MAX_LEN = 10;
	char s[MAX_LEN];
	int new_base = 16;
	std::cin.getline(s, MAX_LEN);

	int length = strlen(s);
	int num = 0;
	int base_from = 10;
	for (int i = 0; i < length; i += 1) {
		// spaces
		if (s[i] == 32) {
			length += 1;
			continue;
		}
		// check '\0'
		if (s[i] == 0) break;
		num = num * base_from + (s[i] - '0');
	}
	char num_new_base[33];
	num_new_base[32] = '\0';

	char digit_val[] = "0123456789ABCDEF";
	int digit_pos = 31;
	do {
		num_new_base[digit_pos] = digit_val[num % new_base];
		digit_pos -= 1;
		num /= new_base;
	} while (num or digit_pos >= 0);

	bool can_write = false;
	for (int i = 0; i < 32; i += 1) {
		if ((num_new_base[i] != '0') or i == 31)
			can_write = true;
		if (can_write)
			std::cout << num_new_base[i];
	}
	std::cout << '\n';

	return 0;
}