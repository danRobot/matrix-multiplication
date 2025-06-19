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

    vector<vector<numeric>>matrix_a;
    vector<vector<numeric>>matrix_b;
    vector<vector<numeric>>matrix_c;
    vector<vector<numeric>>result;
    //cout<<matrix_a<<endl;
    matrix_a=read_matrix<numeric>("/home/danpz/programas/matrix-multiplication/src/aux_py/matrix_a.txt");
    matrix_b=read_matrix<numeric>("/home/danpz/programas/matrix-multiplication/src/aux_py/matrix_b.txt");
    matrix_c=read_matrix<numeric>("/home/danpz/programas/matrix-multiplication/src/aux_py/matrix_c.txt");

    basic_matrix<numeric>basic_a;
    basic_matrix<numeric>basic_b;
    basic_matrix<numeric>basic_c;
    basic_a=cast_matrix(matrix_a);
    basic_b=cast_matrix(matrix_b);
    basic_c=cast_matrix(matrix_c);

    //print_matix(basic_a);
    convert_2d_to_1d(&basic_a);

    cout<<endl;

    //print_matix(basic_b);
    convert_2d_to_1d(&basic_b);

    cout<<endl;

    //print_matix(basic_c);
    convert_2d_to_1d(&basic_c);
    cout<<endl;

    basic_a.matrix=nullptr;
    basic_b.matrix=nullptr;
    basic_c.matrix=nullptr;

    convert_1d_to_2d(&basic_a);
    cout<<"error mul array "<<matrix_check(matrix_a,basic_a)<<endl;
    convert_1d_to_2d(&basic_b);
    cout<<"error mul array "<<matrix_check(matrix_b,basic_b)<<endl;
    convert_1d_to_2d(&basic_c);
    cout<<"error mul array "<<matrix_check(matrix_c,basic_c)<<endl;

   // exit(0);
    cout<<matrix_a.size()<<endl;
    cout<<matrix_a[0].size()<<endl;
    resultado r=matrix_multiplication(matrix_a,matrix_b);
    //basic_matrix basic_a;
    //basic_matrix basic_b;
    //basic_a=cast_matrix(matrix_a);
    //basic_b=cast_matrix(matrix_b);
    vector1d<numeric> matrix_a1d=convert_2d_to_1d(matrix_a);
    vector1d<numeric> matrix_b1d=convert_2d_to_1d(matrix_b);

    resultado r2=matrix_multiplication(basic_a,basic_b);
    resultado r3=matrix_multiplication_1d(basic_a,basic_b);
    resultado r4=matrix_multiplication_1d(matrix_a1d,matrix_b1d);
    double seg=1E9;
    cout<<"tiempo de ejecucoón con matrix_multiplication vect "<<r.time/seg<<endl;
    cout<<"tiempo de ejecucoón con matrix_multiplication matriz "<<r2.time/seg<<endl;
    cout<<"tiempo de ejecucoón con matrix_multiplication 1d array "<<r3.time/seg<<endl;
    cout<<"tiempo de ejecucoón con matrix_multiplication 1d vect "<<r4.time/seg<<endl;
    r3.matrix_array.matrix=nullptr;
    basic_matrix<numeric>*basic_r3=&r3.matrix_array;
    convert_1d_to_2d(basic_r3);
    vector1d<numeric> matrix_c1d;
    matrix_c1d.array=r4.matrix_1d;
    matrix_c1d.size_m=r4.matrix_array.size_m;
    vector<vector<numeric>> matrix_c2d=convert_1d_to_2d(matrix_c1d);
    cout<<"error mul vect "<<matrix_check(matrix_c,r.matrix)<<endl;
    cout<<"error mul array "<<matrix_check(matrix_c,r2.matrix_array)<<endl;
    cout<<"error mul array "<<matrix_check(matrix_c,r3.matrix_array)<<endl;
    cout<<"error mul array "<<matrix_check(matrix_c,matrix_c2d)<<endl;
}

