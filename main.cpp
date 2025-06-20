#include "include/utils/utils.h"
#include "include/utils/types.h"
#include "include/algorithms/simple.h"
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

resultado_step matrix_test(int dim1,int dim2,int dim3){
    
    std::cout << "Current path is " << fs::current_path() << '\n'; // (1)
    fs::current_path(fs::temp_directory_path()); // (3)
    std::cout << "Current path is " << fs::current_path() << '\n';

    vector<vector<numeric>>matrix_a = gnererate_random_matrix<numeric>(dim1,dim2);
    vector<vector<numeric>>matrix_b = gnererate_random_matrix<numeric>(dim2,dim3);
    vector1d<numeric> matrix_a1d=convert_2d_to_1d(matrix_a);
    vector1d<numeric> matrix_b1d=convert_2d_to_1d(matrix_b);

    basic_matrix<numeric>basic_a;
    basic_matrix<numeric>basic_b;
    basic_a=cast_matrix(matrix_a);
    basic_b=cast_matrix(matrix_b);
    convert_2d_to_1d(&basic_a);
    convert_2d_to_1d(&basic_b);

    //print_matix(basic_c);

   // exit(0);
    cout<<matrix_a.size()<<endl;
    cout<<matrix_a[0].size()<<endl;
    resultado r1=matrix_multiplication(matrix_a,matrix_b);
    resultado r2=matrix_multiplication(basic_a,basic_b);
    resultado r3=matrix_multiplication_1d(basic_a,basic_b);
    resultado r4=matrix_multiplication_1d(matrix_a1d,matrix_b1d);
    double seg=1E9;
    resultado_step result;
    result.time_0=r1.time/seg;
    result.time_1=r2.time/seg;
    result.time_2=r3.time/seg;
    result.time_3=r4.time/seg;
    
    clean_matrix(&basic_a);
    clean_matrix(&basic_b);
    clean_matrix(&r1.matrix_array);
    clean_matrix(&r2.matrix_array);
    clean_matrix(&r3.matrix_array);
    clean_matrix(&r4.matrix_array);
    
    return result;
}

int main(){
    int dims[]={5000};
    ofstream outputFile("../output.csv");
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<strerror(errno) << endl;
        return 1;
    }
    resultado_step result;
    outputFile << "dim,matmul_vect,matmul_array,matmul_1d,matmul_1d_vect" << endl;
    for (size_t i = 0; i < sizeof(dims) / sizeof(dims[0]); i++){
        result=matrix_test(dims[i] ,dims[i],dims[i]);
        outputFile << dims[i]<<","<< result.time_0 << "," << result.time_1 << ","
                   << result.time_2 << "," << result.time_3 << endl;
        cout<<result.time_1<<" "<<result.time_2<<" "<<result.time_3<<endl;
    }
    outputFile.close();
    return 0;
}
