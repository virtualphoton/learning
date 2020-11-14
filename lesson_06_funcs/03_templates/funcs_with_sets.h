#pragma once
#include "templates_funcs.h"

//functions will have their overrided analogs, because this fucking compiler evaluates parameters in right-left order

// z10
template <class T>
void permute(T * arr, T * indexes, T * dest, int len);

// z11, intersection
template <class T>
T * intersect(T * arr1, int len1, T * arr2, int len2, int & new_len, bool del = false);
template <class T>
T * intersect(int len1, T * arr1, int len2, T * arr2, int & new_len, bool del = false);

// z12, union. Takes 2 (arrs, length); then link to new_length
template <class T>
T * unite(T * arr1, int len1, T * arr2, int len2, int & new_len, bool del = false);
template <class T>
T * unite(int len1, T * arr1, int len2, T * arr2, int & new_len, bool del = false);

// z13, symmetric difference
template <class T>
T * sym_dif(T * arr1, int len1, T * arr2, int len2, int & new_len, bool del = false);
template <class T>
T * sym_dif(int len1, T * arr1, int len2, T * arr2, int & new_len, bool del = false);

template <class T>
T * diff(T * from, int len1, T * arr, int len2, int & new_len, bool del = false);
template <class T>
T * diff(int len1, T * arr1, int len2, T * arr2, int & new_len, bool del = false);

// z14, all permutations
template <class T>
T ** all_permutations(T* arr, int len);

template <class T>
void generate_permut_rec(T * arr, int len, T ** container, int & gl_index, int full_len);

template <class T>
T * copy(T *, int len);

template <class T>
void swap(T & a, T & b);

template <class T>
void permute(T * arr, T * indexes, T * dest, int len) {
	for (int i = 0; i < len; i += 1)
		dest[indexes[i]] = arr[i];
}

template <class T>
T * intersect(T * arr1, int len1, T * arr2, int len2, int & new_len, bool del) {
	int U_len;
	T * U = unite(arr1, len1, arr2, len2, U_len); //Universum
	int diff_len1, diff_len2, union_len;

	T * ret = diff(U_len, U,
				   union_len,
				   unite(
					   diff_len1,
					   diff(U, U_len, arr1, len1, diff_len1),
					   diff_len2,
					   diff(U, U_len, arr2, len2, diff_len2),
					   union_len,
					   true
				   ),
				   new_len,
				   true
	);
	if (del) {
		delete[] arr1;
		delete[] arr2;
	}
	return ret;
}

template<class T>
T* unite(T * arr1, int len1, T* arr2, int len2, int & new_len, bool del) {
	T * merged_arr = insert(arr1, len1, arr2, 0, len2);
	T * ret_arr = set(merged_arr, len1+len2, new_len);
	delete[] merged_arr;
	if (del) {
		delete[] arr1;
		delete[] arr2;
	}
	return ret_arr;
}

template <class T>
T * diff(T * from, int len1, T * arr, int len2, int & new_len, bool del) {
	T * sorted_from = set(from, len1, len1);
	T * sorted_arr = set(arr, len2, len2);
	bool * mask = new bool[len1];
	int ind_from = 0, ind_arr = 0;
	T delta;
	while (ind_from < len1) {
		if (ind_arr < len2)
			delta = sorted_from[ind_from] - sorted_arr[ind_arr];
		else
			delta = -1;
		
		if (delta < 0) {
			mask[ind_from] = true;
			ind_from += 1;
		} else if (delta == 0) {
			mask[ind_from] = false;
			ind_from += 1;
		} else
			ind_arr += 1;
	}
	new_len = sum(mask, len1);
	int ind = 0;
	T * difference = new T[new_len];
	for (int i = 0; i < len1; i += 1)
		if (mask[i]) {
			difference[ind] = sorted_from[i];
			ind += 1;
		}

	delete[] sorted_arr;
	delete[] sorted_from;
	if (del) {
		delete[] from;
		delete[] arr;
	}

	return difference;
}

template <class T>
T * sym_dif(T * arr1, int len1, T * arr2, int len2, int & new_len, bool del) {
	int union_len, inters_len;
	return diff(
				union_len,
				unite(arr1, len1, arr2, len2, union_len),
				inters_len,
				intersect(arr1, len1, arr2, len2, inters_len, del),
				new_len,
				true
	);
}

template <class T>
T * intersect(int len1, T * arr1, int len2, T * arr2, int & new_len, bool del) {
	return intersect(arr1, len1, arr2, len2, new_len, del);
}
template<class T>
T * unite(int len1, T * arr1, int len2, T * arr2, int & new_len, bool del) {
	return unite(arr1, len1, arr2, len2, new_len, del);
}
template <class T>
T * diff(int len1, T * arr1, int len2, T * arr2, int & new_len, bool del) {
	return diff(arr1, len1, arr2, len2, new_len, del);
}
template <class T>
T * sym_dif(int len1, T * arr1, int len2, T * arr2, int & new_len, bool del) {
	return sym_dif(arr1, len1, arr2, len2, new_len, del);
}


template <class T>
T ** all_permutations(T * arr, int len) {
	int fac = 1;
	for (int i = 2; i <= len; i += 1)
		fac *= i;
	T ** container = new T * [fac];
	int index = 0;
	generate_permut_rec(copy(arr, len), len, container, index, len);
	return container;
}

template <class T>
void generate_permut_rec(T * arr, int len, T ** container, int & gl_index, int full_len) {
	len -= 1;
	if (not len) {
		// add permutation to container
		container[gl_index] = copy(arr, full_len);
		gl_index += 1;
	} else {
		generate_permut_rec(arr, len, container, gl_index, full_len);
		for (int i = 0; i < len; i += 1) {
			if ((len+1) % 2 == 0)
				swap(arr[i], arr[len]);
			else
				swap(arr[0], arr[len]);
			generate_permut_rec(arr, len, container, gl_index, full_len);
		}
	}
	if (len == (full_len - 1))
		// because we pass copy of array, when start recursion
		delete[] arr;
}

template <class T>
T * copy(T * arr, int len) {
	T * ret = new T[len];
	for (int i = 0; i < len; i += 1)
		ret[i] = arr[i];
	return ret;
}

template <class T>
void swap(T & a, T & b) {
	T t = a;
	a = b;
	b = t;
}