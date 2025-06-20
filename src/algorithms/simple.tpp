#include "../../include/algorithms/simple.h"


template<typename T>
resultado<T>matrix_multiplication_1d(vector1d<T>a,vector1d<T>b){
    int dim_a=a.size_m.i;
    int dim_b=b.size_m.i;
    if(a.size_m.j!=b.size_m.j){
        cout<<"dimensiones incorrectas"<<endl;
        exit(1);
    }
    vector<T>c;
    c.resize(dim_a*dim_b);
    int dim_c=b.size_m.j;
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    #pragma omp parallel for num_threads(omp_get_max_threads()) collapse(2)
    for (int i = 0; i < dim_a; i++){
        for (int j = 0; j < dim_b; j++){
            int dim=i*(dim_b)+j;
            T sum = 0;
            #pragma omp simd reduction(+:sum)
            for (int k = 0; k < dim_c; k++){
                int dim_a_k=i*(dim_c)+k;
                int dim_b_k=k+(dim_c)*j;
                T a_ik=a.array[dim_a_k];
                T b_kj=b.array[dim_b_k];
                sum+=a_ik*b_kj;
            }
            c[dim]=sum;
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    resultado<T>res;
    vector1d<T> c_vec;
    c_vec.array=c;
    c_vec.size_m.i=dim_a;
    c_vec.size_m.j=dim_b;
    res.matrix_1d=c_vec;
    const std::chrono::duration<long double,nano> diff = end - begin;
    res.time=diff.count();
    return res;
}

template<typename T>
resultado<T>matrix_multiplication_1d(basic_matrix<T>a,basic_matrix<T>b){
    int dim_a=a.size_m.i;
    int dim_b=b.size_m.i;
    if(a.size_m.j!=b.size_m.j){
        cout<<"dimensiones incorrectas"<<endl;
        exit(1);
    }
    T*c=nullptr;
    int dim_c=b.size_m.j;
    c=new T[dim_a*dim_b];
    
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    #pragma omp parallel for num_threads(omp_get_max_threads()) collapse(2)
    for (int i = 0; i < dim_a; i++){
        for (int j = 0; j < dim_b; j++){

            int dim=i*(dim_b)+j;

            T sum = 0;
            #pragma omp simd reduction(+:sum)
            for (int k = 0; k < dim_c; k++){
                int dim_a_k=i*(dim_c)+k;
                int dim_b_k=k+(dim_c)*j;
                T a_ik=a.array[dim_a_k];
                T b_kj=b.array[dim_b_k];
                sum+=a_ik*b_kj;
            }
            c[dim]=sum;
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    resultado<T>res;
    basic_matrix<T>c_mat;
    c_mat.array=c;
    c_mat.size_m.i=dim_a;
    c_mat.size_m.j=dim_b;
    res.matrix_array=c_mat;
    const std::chrono::duration<long double,nano> diff = end - begin;
    res.time=diff.count();
    return res;
}