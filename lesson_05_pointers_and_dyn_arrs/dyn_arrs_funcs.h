#pragma once
#include <string>

//fill 1-d array with randoms
void fill_random_int(int * a, int size, int min, int max);

//fill 2-d array with random
void fill_random_int(int ** a, int lines, int columns, int min, int max);

//create 2-d int matrix
int ** create_int_matrix(int lines, int columns);

//delete 2-d int matrix
void delete_int_matrix(int ** arr, int lines);

//print 1-d arr. Automatically deletes it
void print_arr(int * arr, int size, std::string msg, bool delete_arr = true, bool print_msg=true);

//print 2-d matrix. Automatically deletes it
void print_arr(int ** arr, int lines, int columns, std::string msg, bool delete_arr = true, bool print_msg = true);

//shift 1-d arr. Automatically deletes it afterwards
int * shift(int * arr, int size, int shift, bool del_arr = true);

//transpose 2-d matrix. Automatically deletes it afterwards
int ** transpose(int ** arr, int lines, int columns, bool del_arr = true);

//flattern matrix. Automatically deletes it afterwards
int * flatten(int ** arr, int lines, int columns, bool del_arr = true);