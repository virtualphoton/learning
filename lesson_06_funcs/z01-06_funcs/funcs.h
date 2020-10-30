#pragma once

// greatest common divisor of two ints moduluses
// returns 0 if a = b = 0
int gcd(int a, int b);

//len of string (num of chars before \0)
int len_of_str(const char * s);

//string representing decimal int to int
int str_to_int(const char * s);

//function to make triangular matrix using gauss method
//this kludge is needed because i don't know how to make default links
int ** make_triang(int ** mat, int size, double & det);

int ** make_triang(int ** mat, int size);

//determinator of square matrix
double det(int ** mat, int size);

//Concat s1 and s2 into char array dest. Not more symbols than max_len.
void concat_into(const char * s1, const char * s2, char * dest, int max_len);