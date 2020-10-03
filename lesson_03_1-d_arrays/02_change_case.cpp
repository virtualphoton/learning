#include <iostream>

int main(){
	char s[64];
	std::cin.getline(s, 64);
	for (int i = strlen(s)-1; i >= 0; i -= 1) {
		if ('a' <= s[i] and 'z' >= s[i]) 
			s[i] = s[i] - 'a' + 'A';
		else if ('A' <= s[i] and 'Z' >= s[i]) 
			s[i] = s[i] - 'A' + 'a';
	}
	std::cout << s;
}