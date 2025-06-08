#ifndef _UTILS_H
#define _UTILS_H

#include<iostream>
#include<fstream>
#include <cstring>
#include <vector>
#include <chrono>

using namespace std;

vector<string> split(string& s, const string& delimiter);
vector<vector<double>>read_matrix(string path);
void print_matix(vector<vector<double>>mat);

#endif // MACRO
