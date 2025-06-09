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
    #pragma omp parallel for num_threads(20)
    for (size_t i = 0; i < dim_a; i++){
        #pragma omp parallel for num_threads(20)
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
    const std::chrono::duration<double,nano> diff = end - begin;
    res.time=diff.count();
    return res;
}

resultado matrix_multiplication(basic_matrix a,basic_matrix b){
    int dim_a=a.size_m.i;
    int dim_b=b.size_m.j;
    if(a.size_m.j!=b.size_m.i){
        cout<<"dimensiones incorrectas"<<endl;
        exit(1);
    }
    double**c=nullptr;
    int dim_c=b.size_m.i;
    c=new double*[dim_a];
    for (size_t i = 0; i < dim_a; i++){
        c[i]=new double[dim_b];
    }
    
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    #pragma omp parallel for num_threads(20)
    for (size_t i = 0; i < dim_a; i++){
        #pragma omp parallel for num_threads(20)
        for (size_t j = 0; j < dim_b; j++){
            c[i][j]=0;
            for (size_t k = 0; k < dim_c; k++){
                double a_ik=a.matrix[i][k];
                double b_kj=b.matrix[k][j];
                c[i][j]+=a_ik*b_kj;
            }
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    resultado res;
    basic_matrix c_mat;
    c_mat.matrix=c;
    c_mat.size_m.i=dim_a;
    c_mat.size_m.j=dim_b;
    res.matrix_array=c_mat;
    const std::chrono::duration<double,nano> diff = end - begin;
    res.time=diff.count();
    return res;
}