#ifndef _SIMPLE_H
#define _SIMPLE_H
#include<vector>
#include<iostream>
#include"../utils/types.h"

using namespace std;

template<typename T>
resultado<T> matrix_multiplication(vector<vector<T>>a,vector<vector<T>>b);
template<typename T>
resultado<T> matrix_multiplication_1d(vector<vector<T>>a,vector<vector<T>>b);
template<typename T>
resultado<T> matrix_multiplication(basic_matrix<T>a,basic_matrix<T>b);
template<typename T>
resultado<T> matrix_multiplication_1d(basic_matrix<T>a,basic_matrix<T>b);


#endif // MACRO
