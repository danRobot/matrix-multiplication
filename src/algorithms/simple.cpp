#include "../../include/algorithms/simple.h"

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

