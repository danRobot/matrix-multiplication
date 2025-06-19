#include "../../include/algorithms/simple.h"

template<typename T>
resultado<T> matrix_multiplication(vector<vector<T>>a,vector<vector<T>>b){
    int dim_a=a.size();
    int dim_b=b[0].size();
    if(a[0].size()!=b.size()){
        cout<<"dimensiones incorrectas"<<endl;
        exit(1);
    }
    vector<vector<T>>c(dim_a,vector<T>(dim_b, 0.0));
    int dim_c=b.size();
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    #pragma omp parallel for num_threads(20)
    for (size_t i = 0; i < dim_a; i++){
        #pragma omp parallel for num_threads(10)
        for (size_t j = 0; j < dim_b; j++){
            #pragma omp simd
            for (size_t k = 0; k < dim_c; k++){
                T a_ik=a[i][k];
                T b_kj=b[k][j];
                c[i][j]+=a_ik*b_kj;
            }
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    resultado<T> res;
    res.matrix=c;
    const std::chrono::duration<T,nano> diff = end - begin;
    res.time=diff.count();
    return res;
}

template<typename T>
resultado<T>matrix_multiplication_1d(vector1d<T>a,vector1d<T>b){
    int dim_a=a.size_m.i;
    int dim_b=b.size_m.j;
    if(a.size_m.j!=b.size_m.i){
        cout<<"dimensiones incorrectas"<<endl;
        exit(1);
    }
    vector<T>c(dim_a*dim_b,0.0);
    int dim_c=b.size_m.i;
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    #pragma omp parallel for num_threads(20)
    for (size_t i = 0; i < dim_a; i++){
        #pragma omp parallel for num_threads(10)
        for (size_t j = 0; j < dim_b; j++){
            int dim=i*(dim_b)+j;
            #pragma omp simd
            for (size_t k = 0; k < dim_c; k++){
                int dim_a_k=i*(dim_c)+k;
                int dim_b_k=k*(dim_b)+j;
                T a_ik=a.array[dim_a_k];
                T b_kj=b.array[dim_b_k];
                c[dim]+=a_ik*b_kj;
            }
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    resultado<T>res;
    res.matrix_1d=c;
    const std::chrono::duration<T,nano> diff = end - begin;
    res.time=diff.count();
    res.matrix_array.size_m.i=dim_a;
    res.matrix_array.size_m.j=dim_b;
    return res;
}

template<typename T>
resultado<T>matrix_multiplication(basic_matrix<T>a,basic_matrix<T>b){
    int dim_a=a.size_m.i;
    int dim_b=b.size_m.j;
    if(a.size_m.j!=b.size_m.i){
        cout<<"dimensiones incorrectas"<<endl;
        exit(1);
    }
    T**c=nullptr;
    int dim_c=b.size_m.i;
    c=new T*[dim_a];
    for (size_t i = 0; i < dim_a; i++){
        c[i]=new T[dim_b];
    }
    
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    #pragma omp parallel for num_threads(20)
    for (size_t i = 0; i < dim_a; i++){
        #pragma omp parallel for num_threads(10)
        for (size_t j = 0; j < dim_b; j++){
            c[i][j]=0;
            #pragma omp simd
            for (size_t k = 0; k < dim_c; k++){
                T a_ik=a.matrix[i][k];
                T b_kj=b.matrix[k][j];
                c[i][j]+=a_ik*b_kj;
            }
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    resultado<T>res;
    basic_matrix<T>c_mat;
    c_mat.matrix=c;
    c_mat.size_m.i=dim_a;
    c_mat.size_m.j=dim_b;
    res.matrix_array=c_mat;
    const std::chrono::duration<T,nano> diff = end - begin;
    res.time=diff.count();
    return res;
}

template<typename T>
resultado<T>matrix_multiplication_1d(basic_matrix<T>a,basic_matrix<T>b){
    int dim_a=a.size_m.i;
    int dim_b=b.size_m.j;
    if(a.size_m.j!=b.size_m.i){
        cout<<"dimensiones incorrectas"<<endl;
        exit(1);
    }
    T*c=nullptr;
    int dim_c=b.size_m.i;
    c=new T[dim_a*dim_b];
    
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    #pragma omp parallel for num_threads(20)
    for (size_t i = 0; i < dim_a; i++){
        #pragma omp parallel for num_threads(10)
        for (size_t j = 0; j < dim_b; j++){

            int dim=i*(dim_b)+j;

            c[dim]=0;
            #pragma omp simd
            for (size_t k = 0; k < dim_c; k++){
                int dim_a_k=i*(dim_c)+k;
                int dim_b_k=k*(dim_b)+j;
                T a_ik=a.array[dim_a_k];
                T b_kj=b.array[dim_b_k];
                c[dim]+=a_ik*b_kj;
            }
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    resultado<T>res;
    basic_matrix<T>c_mat;
    c_mat.array=c;
    c_mat.size_m.i=dim_a;
    c_mat.size_m.j=dim_b;
    res.matrix_array=c_mat;
    const std::chrono::duration<T,nano> diff = end - begin;
    res.time=diff.count();
    return res;
}