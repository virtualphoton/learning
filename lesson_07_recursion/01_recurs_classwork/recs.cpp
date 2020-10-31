#include "recs.h"
#include <iostream>

void print_range(int a, int b) {
	std::cout << a << ' ';
	if (a < b)
		print_range(a + 1, b);
	else if (a > b)
		print_range(a - 1, b);
	else
		std::cout << '\n';
}

void print_range(int a) {
	print_range(1, a);
}

bool check_palindrome(const char * s, int start, int fin) {
	if (fin == -1)
		fin = strlen(s);
	if (fin <= start)
		return true;
	return (s[start] == s[fin - 1]) and check_palindrome(s, start+1, fin-1);
}