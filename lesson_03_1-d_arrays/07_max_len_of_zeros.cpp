#include <iostream>

int main() {
	const int MAX_LEN = 64;
	char s[MAX_LEN];
	std::cin.getline(s, MAX_LEN);
	int length = strlen(s);

	int end_of_max = 0;
	int max_len = 0;
	int cur_len = 0;
	// <= for those, which end with zeros
	for (int i = 0; i <= length; i += 1) {
		if (s[i] == '0')
			cur_len += 1;
		else {
			if (cur_len > max_len) {
				max_len = cur_len;
				end_of_max = i;
			}
			cur_len = 0;
		}
	}

	if (max_len)
		std::cout << end_of_max - max_len << ' ' << max_len << '\n';
	else
		std::cout << 0 << '\n';
}