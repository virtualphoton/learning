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

int ** make_triang(int ** mat, int size, double & det) {
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
	int zeros_in_col;
	bool need_swap;
	det = 1;

	//step is column, in which we make zeros now
	for (int step = 0; step < size; step += 1) {
		zeros_in_col = 0;
		need_swap = true;

		//swap lines, so that in gaussedp[step][step] = 0;
		for (int line = step; line < size; line += 1) {
			if (not gaussed[line][step]) {
				zeros_in_col += 1;
				continue;
			}

			//swapping lines
			if (need_swap and zeros_in_col) {
				det *= -1;
				int * t_int_arr = gaussed[step];
				gaussed[step] = gaussed[line];
				gaussed[line] = t_int_arr;
			}
			need_swap = false;
			break;
		}

		//if rest of the column is zero
		if (zeros_in_col == size - step)
			det = 0;
		//subtract gaussed[step] from all lines below it
		else
			for (int line = step + 1; line < size; line += 1) {
				gcd_to_make_smaller = 0;

				//gcd of first elements in lines, that will be used in substraction
				gcd_for_sub = gcd(gaussed[step][step], gaussed[line][step]);
				mul_for_main = gaussed[line][step] / gcd_for_sub;
				mul_for_cur = gaussed[step][step] / gcd_for_sub;
				det /= mul_for_cur;
				for (int col = step; col < size; col += 1) {
					gaussed[line][col] = gaussed[line][col] * mul_for_cur - gaussed[step][col] * mul_for_main;
					gcd_to_make_smaller = gcd(gcd_to_make_smaller, gaussed[line][col]);
				}

				if (gcd_to_make_smaller) {
					det *= gcd_to_make_smaller;
					for (int col = step; col < size; col += 1)
						gaussed[line][col] /= gcd_to_make_smaller;
				}
			}

	}
	return gaussed;
}

int ** make_triang(int ** mat, int size) {
	double det = 1;
	return make_triang(mat, size, det);
}

double det(int ** mat, int size) {
	double det;
	int ** gaussed = make_triang(mat, size, det);
	for (int i = 0; i < size; i += 1) {
		det *= gaussed[i][i];
	}
	for (int i = 0; i < size; i += 1)
		delete[] gaussed[i];
	delete[] gaussed;

	return det;
}

void concat_into(const char * s1, const char * s2, char * dest, int max_len) {
	int len1 = len_of_str(s1);
	int len2 = len_of_str(s2);
	int pos = 0;
	for (; pos < max_len and pos < len1; pos += 1)
		dest[pos] = s1[pos];
	len2 += pos;
	for (; pos < max_len and pos < len2; pos += 1)
		dest[pos] = s2[pos-len1];
}