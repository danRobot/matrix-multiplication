#ifndef _UTILS_H
#define _UTILS_H

#include<iostream>
#include<fstream>
#include <cstring>
#include <vector>
#include <chrono>
#include "types.h"

using namespace std;

vector<string> split(string& s, const string& delimiter);
template<typename T>
vector<vector<T>>read_matrix(string path);
template<typename T>
void print_matix(vector<vector<T>>mat);
template<typename T>
void print_matix(basic_matrix<T>mat);
template<typename T>
basic_matrix<T>cast_matrix(vector<vector<T>>mat);
template<typename T>
T matrix_check(vector<vector<T>>mat1,basic_matrix<T>mat2);
template<typename T>
T matrix_check(vector<vector<T>>mat1,vector<vector<T>>mat2);
template<typename T>
void convert_1d_to_2d(basic_matrix<T>*mat);
template<typename T>
void convert_2d_to_1d(basic_matrix<T>*mat);

#include "../../src/utils/utils.tpp"

#endif // MACRO
