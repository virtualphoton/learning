#include "working_with_sequencies_and_arrs.h"
#include <stdio.h>

void foo_bar(int start, int end) {
	for (int i = start; i <= end; i += 1) {
		if (not (i % 3) or not (i % 5)) {
			if (not (i % 3))
				printf("%s", "Foo");
			if (not (i % 5))
				printf("%s", "Bar");
		} else
			printf("%i", i);
		printf("\n");
	}
}

void out_2_maxes(int * arr, int len) {
	int * sorted = bubble_sort(arr, len);
	printf("%i %i", sorted[1], sorted[0]);
	delete[] sorted;
}

int * bubble_sort(int * arr0, int len) {
	int * arr = new int[len];
	for (int i = 0; i < len; i += 1) {
		arr[i] = arr0[i];
	}
	int temp;
	for (int i = 0; i < len; i += 1)
		for (int j = 0; j < len - i - 1; j += 1)
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	return arr;
}

int most_freq(int * arr, int len) {
	int * sorted = bubble_sort(arr, len);
	int max_len = 0;
	int max_len_num = arr[0];
	int cur_len = 0;
	int cur_num = sorted[0];
	for (int i = 0; i < len; i += 1) {
		if (sorted[i] == cur_num)
			cur_len += 1;
		else {
			cur_num = sorted[i];
			cur_len = 1;
		}

		if (cur_len > max_len) {
			max_len_num = cur_num;
			max_len = cur_len;
		}
	}
	delete[] sorted;
	return max_len_num;
}

int * set(int * arr, int len, int & set_len) {
	int * sorted = bubble_sort(arr, len);
	int num_of_diff = 1;
	for (int i = 0; i < len - 1; i += 1)
		if (sorted[i] != sorted[i + 1])
			num_of_diff += 1;
	int * set = new int[num_of_diff];
	set_len = num_of_diff;
	int index = 0;
	set[0] = sorted[0];
	for (int i = 0; i < len; i += 1)
		if (sorted[i] != set[index]) {
			index += 1;
			set[index] = sorted[i];
		}
	return set;
}

void divide_relative_to_zero(int * arr, int len, int ** combined, int & neg_len, int & pos_len) {
	int num_of_neg = 0;
	for (int i = 0; i < len; i += 1)
		if (arr[i] < 0)
			num_of_neg += 1;
	int * neg = new int[num_of_neg];
	int * pos = new int[len - num_of_neg];
	int ind_n = 0, ind_p = 0;
	for (int i = 0; i < len; i += 1) {
		if (arr[i] < 0) {
			neg[ind_n] = arr[i];
			ind_n += 1;
		} else {
			pos[ind_p] = arr[i];
			ind_p += 1;
		}
	}
	combined[0] = neg;
	combined[1] = pos;
	neg_len = num_of_neg;
	pos_len = len - num_of_neg;
}