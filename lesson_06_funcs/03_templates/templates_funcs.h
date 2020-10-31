#pragma once

// z01. returns bounding elements of matrix
template <typename T>
T * perimeter_arr(T ** matr, int lines, int cols) {
	int len = (lines + cols - 2) * 2;
	T * perim = new T[len];
	int dir = 1;
	int line = 0, col = 0;
	int dline = 0, dcol = 1;
	for (int ind = 0; ind < len; ind += 1) {
		if (dir == 1 and col == cols - 1) {
			dir = 2;
			dline = 1;
			dcol = 0;
		} else if (dir == 2 and line == lines - 1) {
			dir = 3;
			dline = 0;
			dcol = -1;
		} else if (dir == 3 and col == 0) {
			dir = 4;
			dline = -1;
			dcol = 0;
		}
		perim[ind] = matr[line][col];
		line += dline;
		col += dcol;
	}
	return perim;
}

// sort using bubble sort
template <typename T>
T * bubble_sort(T * arr0, int len) {
	T * arr = new T [len];
	for (int i = 0; i < len; i += 1)
		arr[i] = arr0[i];

	T temp;
	for (int i = 0; i < len; i += 1)
		for (int j = 0; j < len - i - 1; j += 1)
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	return arr;
}

// z02. find 2 minimal elements of arr. Writes them to passed by link variables min1 and min2.
template <typename T>
void out_2_mins(T * arr, int len, T & min1, T & min2) {
	T * sorted = bubble_sort(arr, len);
	min1 = sorted[0];
	for (int i = 0; i < len; i += 1)
		if (sorted[i] != min1) {
			min2 = sorted[i];
			break;
		}
	delete[] sorted;
}

// z03. most frequent element
template <typename T>
T most_freq(T * arr, int len) {
	T * sorted = bubble_sort(arr, len);
	int max_len = 0;
	T max_len_num = arr[0];
	int cur_len = 0;
	T cur_num = sorted[0];
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

// z04. returns array of unique numbers in arr. its length is written to set_len variable
template <typename T>
 T* set(T * arr, int len, int & set_len) {
	T * sorted = bubble_sort(arr, len);
	int num_of_diff = 1;
	for (int i = 0; i < len - 1; i += 1)
		if (sorted[i] != sorted[i + 1])
			num_of_diff += 1;
	T * arr_set = new T[num_of_diff];
	set_len = num_of_diff;
	int index = 0;
	arr_set[0] = sorted[0];
	for (int i = 0; i < len; i += 1)
		if (sorted[i] != arr_set[index]) {
			index += 1;
			arr_set[index] = sorted[i];
		}
	return arr_set;
}

// z05. Divides arr into 2 arr, 1st is positive, 2nd is negative.
// those arrays are written to passed 2-d arr `combined`, which has 2 lines. Their length is written to passed `neg_len` and `pos_len`
template <typename T>
void divide_relative_to_zero(T * arr, int len, T ** combined, int & pos_len, int & neg_len) {
	 int num_of_neg = 0;
	 for (int i = 0; i < len; i += 1)
		 if (arr[i] < 0)
			 num_of_neg += 1;
	 T * neg = new T[num_of_neg];
	 T * pos = new T[len - num_of_neg];
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
	 combined[0] = pos;
	 combined[1] = neg;
	 neg_len = num_of_neg;
	 pos_len = len - num_of_neg;
}

// z07. Recursively find sum of 1-d arr
template <typename T>
T sum(T * arr, int len, int ind=0) {
	if (len == ind)
		return 0;
	return arr[ind] + sum(arr, len, ind + 1);
}

// z09. Inplace insert array into array
template <typename T>
T* insert(T * arr, int arr_len, T * ins_arr, int pos, int ins_len) {
	T * new_arr = new T[arr_len + ins_len];
	int ind = 0;
	for (int i = 0; i <= arr_len; i += 1) {
		if (i == pos)
			for (int j = 0; j < ins_len; j += 1) {
				new_arr[ind] = ins_arr[j];
				ind += 1;
			}
		if (i != arr_len) {
			new_arr[ind] = arr[i];
			ind += 1;
		}
	}
	return new_arr;
}

// z08. inplace insert element to certain pos in array.
template <typename T>
T * insert(T * arr, int arr_len, T elem, int pos) {
	T * insert_arr = new T[1];
	insert_arr[0] = elem;
	T * new_arr = insert(arr, arr_len, insert_arr, pos, 1);
	delete[] insert_arr;
	return new_arr;
}

// slice function for determinant
template <typename T>
T ** slice(T ** matr, int size, int cut) {
	T ** new_matr = new T * [size - 1];
	int ind = 0;
	for (int i = 0; i < size; i += 1)
		if (i != cut) {
			new_matr[ind] = matr[i];
			ind += 1;
		}
	return new_matr;
}

// z06. determinant
template <typename T>
T determinant(T ** matr, int size, int shift=0, bool del=false) {
	if (size == 1){
		matr[0][shift];
		T ret = matr[0][shift];
		if (del)
			delete[] matr;

		return ret;
	}
	double mul = 1;
	double det = 0;
	for (int i = 0; i < size; i += 1) {
		det += mul * matr[i][shift] * determinant(slice(matr, size, i), size-1, shift+1, true);
		mul *= -1;
	}
	if (del)
		delete[] matr;
	return det;
}