#include "include/utils/utils.h"
#include "include/utils/types.h"
#include "include/algorithms/simple.h"

using namespace std;

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
    print_matix(matrix_c);
    print_matix(r.matrix);
    double seg=1E9;
    cout<<r.time/seg<<endl;
}

