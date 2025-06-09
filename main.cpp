#include "include/utils/utils.h"
#include "include/utils/types.h"
#include "include/algorithms/simple.h"
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main(int argc,char**argv){

    for (size_t i = 0; i < argc; i++){
        cout<<argv[i]<<endl;
    }
    
    std::cout << "Current path is " << fs::current_path() << '\n'; // (1)
    fs::current_path(fs::temp_directory_path()); // (3)
    std::cout << "Current path is " << fs::current_path() << '\n';

    vector<vector<double>>matrix_a;
    vector<vector<double>>matrix_b;
    vector<vector<double>>matrix_c;
    vector<vector<double>>result;
    //cout<<matrix_a<<endl;
    matrix_a=read_matrix("/home/danpz/programas/matrix-multiplication/src/aux_py/matrix_a.txt");
    matrix_b=read_matrix("/home/danpz/programas/matrix-multiplication/src/aux_py/matrix_b.txt");
    matrix_c=read_matrix("/home/danpz/programas/matrix-multiplication/src/aux_py/matrix_c.txt");
    cout<<matrix_a.size()<<endl;
    cout<<matrix_a[0].size()<<endl;
    resultado r=matrix_multiplication(matrix_a,matrix_b);
    basic_matrix basic_a;
    basic_matrix basic_b;
    basic_a=cast_matrix(matrix_a);
    basic_b=cast_matrix(matrix_b);
    resultado r2=matrix_multiplication(basic_a,basic_b);
    double seg=1E9;
    cout<<r.time/seg<<endl;
    cout<<r2.time/seg<<endl;
    cout<<"error mul vect "<<matrix_check(matrix_c,r.matrix)<<endl;
    cout<<"error mul array "<<matrix_check(matrix_c,r2.matrix_array)<<endl;
}

