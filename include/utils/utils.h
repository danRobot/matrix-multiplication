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
vector<vector<double>>read_matrix(string path);
void print_matix(vector<vector<double>>mat);
void print_matix(basic_matrix mat);
basic_matrix cast_matrix(vector<vector<double>>mat);
double matrix_check(vector<vector<double>>mat1,basic_matrix mat2);
double matrix_check(vector<vector<double>>mat1,vector<vector<double>>mat2);

#endif // MACRO
