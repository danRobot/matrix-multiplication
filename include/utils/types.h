#ifndef _TYPES_H
#define _TYPES_H
#include<vector>
#include <chrono>

using namespace std;

typedef struct{
    long int i=-1;
    long int j=-1;
} size_matrix;
template<typename T>
struct basic_matrix{
    T**matrix=nullptr;
    T*array=nullptr;
    size_matrix size_m;
};
template<typename T>
struct resultado{
    vector<vector<T>> matrix;
    basic_matrix<T> matrix_array;
    long double time=-1;
};
template<typename T>
struct vector1d {
    vector<T> array;
    size_matrix size_m;
};


#endif
