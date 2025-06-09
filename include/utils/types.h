#ifndef _TYPES_H
#define _TYPES_H
#include<vector>
#include <chrono>

using namespace std;

typedef struct{
    long int i=-1;
    long int j=-1;
} size_matrix;
typedef struct{
    double**matrix=nullptr;
    double*array=nullptr;
    size_matrix size_m;
} basic_matrix;
typedef struct{
    vector<vector<double>> matrix;
    basic_matrix matrix_array;
    long double time=-1;
} resultado;

#endif // MACRO
