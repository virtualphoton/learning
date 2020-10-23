#include "funcs.h"

int gcd(int a, int b) {
	a = a > 0 ? a : -a;
	b = b > 0 ? b : -b;
	int t;
	while (a and b) {
		t = a % b;
		a = b;
		b = t;
	}
	return a + b;
}

int len_of_str(const char * s) {
	for (int index = 0; ; index += 1)
		if (s[index] == '\0')
			return index;
}

int str_to_int(const char * s) {
	int num = 0;
	int len = len_of_str(s);
	for (int ind = s[0] == '-' ? 1 : 0; ind < len; ind += 1)
		num = num * 10 + int(s[ind] - '0');
	return (s[0] == '-') ? -num : num;
}

int ** make_triang(int ** mat, int size) {
	int ** gaussed = new int * [size];
	for (int i = 0; i < size; i += 1) {
		gaussed[i] = new int[size];
		for (int j = 0; j < size; j += 1)
			gaussed[i][j] = mat[i][j];
	}
	int gcd_for_sub;
	int mul_for_main;
	int mul_for_cur;
	int gcd_to_make_smaller;
	for (int step = 0; step < size; step += 1)
		for (int i = step + 1; i < size; i += 1) {
			gcd_to_make_smaller = 0;
			for (int j = 0; j < size; j += 1) {
				gcd_for_sub = gcd(gaussed[step][step], gaussed[i][step]);
				mul_for_main = gaussed[i][step] / gcd_for_sub;
				mul_for_cur = gaussed[step][step] / gcd_for_sub;
				gaussed[i][j] = gaussed[i][j] * mul_for_cur - gaussed[step][j] * mul_for_main;
			}
		}

	return gaussed;
}

double det(int ** mat, int size) {
	int ** triang = make_triang(mat, size);
	double det = 1;
	for (int i = 0; i < size; i += 1)
		det *= triang[i][i];
	for (int i = 0; i < size; i += 1)
		delete[] triang[i];
	delete[] triang;
	return det;
}