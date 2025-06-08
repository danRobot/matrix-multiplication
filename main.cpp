#include"include/functions.h"
#include<iostream>
#include<fstream>
#include <cstring>
#include <vector>
#include <chrono>

using namespace std;
const int dim1=10;
struct resultado{
    vector<vector<double>> matrix;
    double time;
};


vector<string> split(string& s, const string& delimiter) {
    vector<string> tokens;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);

    return tokens;
}

vector<vector<double>>read_matrix(string path){
    vector<vector<double>>matrix;
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Error opening file: " << strerror(errno) << endl;
        exit(1);
    }
    string linea;
    int i=0;
    while (getline(input_file,linea))
    {
        vector<double> m;
        matrix.push_back(m);
        vector<string> numeros=split(linea," ");
        for (auto &&numero : numeros){
            double n=stod(numero);
            matrix[i].push_back(n);
        }
        i++;
    }
    return matrix;
}

resultado matrix_multiplication(vector<vector<double>>a,vector<vector<double>>b){
    int dim_a=a.size();
    int dim_b=b[0].size();
    if(a[0].size()!=b.size()){
        cout<<"dimensiones incorrectas"<<endl;
        exit(1);
    }
    vector<vector<double>>c(dim_a,vector<double>(dim_b, 0.0));
    int dim_c=b.size();
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    for (size_t i = 0; i < dim_a; i++){
        for (size_t j = 0; j < dim_b; j++){
            for (size_t k = 0; k < dim_c; k++){
                double a_ik=a[i][k];
                double b_kj=b[k][j];
                c[i][j]+=a_ik*b_kj;
            }
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    resultado res;
    res.matrix=c;
    res.time=9;
    const std::chrono::duration<double,nano> diff = end - begin;
    res.time=diff.count();
    return res;
}

void print_matix(vector<vector<double>>mat){
    int dim_a=mat.size();
    int dim_b=mat[0].size();
    cout<<endl;
    for (size_t i = 0; i < dim_a; i++){
        for (size_t j = 0; j < dim_b; j++){
            cout<<' '<<mat[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(int argc,char**argv){
    vector<vector<double>>matrix_a;
    vector<vector<double>>matrix_b;
    vector<vector<double>>matrix_c;
    vector<vector<double>>result;
    //cout<<matrix_a<<endl;
    matrix_a=read_matrix("../src/aux_py/matrix_a.txt");
    matrix_b=read_matrix("../src/aux_py/matrix_b.txt");
    matrix_c=read_matrix("../src/aux_py/matrix_c.txt");
    cout<<matrix_a.size()<<endl;
    cout<<matrix_a[0].size()<<endl;
    resultado r=matrix_multiplication(matrix_a,matrix_b);
    //print_matix(matrix_c);
    //print_matix(r.matrix);
    double seg=1E9;
    cout<<r.time/seg<<endl;
}

