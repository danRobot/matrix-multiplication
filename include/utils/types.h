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
    vector<vector<double>> matrix;
    double**matrix_array=nullptr;
    long double time=-1;
    size_matrix size; 
} resultado;

#endif // MACRO
