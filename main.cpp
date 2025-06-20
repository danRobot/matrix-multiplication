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
    basic_matrix<numeric>basic_b_t;
    vector<vector<numeric>>matrix_b_t=transpose_matrix(matrix_b);
    vector1d<numeric> matrix_b1d_t=convert_2d_to_1d(matrix_b_t);
    basic_a=cast_matrix(matrix_a);
    basic_b=cast_matrix(matrix_b);
    basic_b_t=cast_matrix(matrix_b_t);
    convert_2d_to_1d(&basic_a);
    convert_2d_to_1d(&basic_b);
    convert_2d_to_1d(&basic_b_t);

    //print_matix(basic_c);

   // exit(0);
    cout<<matrix_a.size()<<endl;
    cout<<matrix_a[0].size()<<endl;
    resultado r3=matrix_multiplication_1d(basic_a,basic_b_t);
    resultado r4=matrix_multiplication_1d(matrix_a1d,matrix_b1d_t);
    double seg=1E9;
    resultado_step result;
    result.time_0=r3.time/seg;
    result.time_1=r4.time/seg;
    
    clean_matrix(&basic_a);
    clean_matrix(&basic_b);
    clean_matrix(&r3.matrix_array);
    clean_matrix(&r4.matrix_array);
    
    return result;
}

int main(){
    vector<vector<numeric>> dimensiones=read_matrix<numeric>("dims_test.txt");
    ofstream outputFile("output.csv");
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<strerror(errno) << endl;
        return 1;
    }
    resultado_step result;
    outputFile << "dim,raw_array,vector_class" << endl;
    for (const auto& row : dimensiones) {
        for (const auto& elem : row) {
            int dim_test=(int)elem;
            result=matrix_test(dim_test ,dim_test,dim_test);
            outputFile << elem<<","<< result.time_0 << "," << result.time_1 << endl;
            cout<<result.time_0<<" "<<result.time_1<<" "<<endl;
        }
        cout << endl;
    }
    outputFile.close();
    return 0;
}
