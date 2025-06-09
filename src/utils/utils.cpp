#include "../../include/utils/utils.h"


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
        cerr << "Error opening file: " << strerror(errno) << ' '<<path<<endl;
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
void print_matix(basic_matrix mat){
    cout<<endl;
    for (size_t i = 0; i < mat.size_m.i; i++){
        for (size_t j = 0; j < mat.size_m.j; j++){
            cout<<' '<<mat.matrix[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

basic_matrix cast_matrix(vector<vector<double>>mat){
    double**result=nullptr;
    int dim_a=mat.size();
    int dim_b=mat[0].size();
    result=new double*[dim_a];
    for (size_t i = 0; i < dim_a; i++){
        result[i]=new double[dim_b];
    }
    for (size_t i = 0; i < dim_a; i++){
        for (size_t j = 0; j < dim_b; j++){
            result[i][j]=mat[i][j];
        }
        
    }
    basic_matrix r;
    r.matrix=result;
    r.size_m.i=dim_a;
    r.size_m.j=dim_b;
    return r;
}

double matrix_check(vector<vector<double>>mat1,basic_matrix mat2){
    if(mat1.size()!=mat2.size_m.i&&mat1[0].size()!=mat2.size_m.j){
        cout<<"dimensiones incorrectas"<<endl;
        exit(1);
    }
    int dim_a=mat2.size_m.i;
    int dim_b=mat2.size_m.j;
    double error=0;
    for (size_t i = 0; i < dim_a; i++){
        for (size_t j = 0; j < dim_b; j++){
            error+=abs(mat1[i][j])-abs(mat2.matrix[i][j]);
        }
    }
    return error;
}

double matrix_check(vector<vector<double>>mat1,vector<vector<double>>mat2){
    if(mat1.size()!=mat2.size()&&mat1[0].size()!=mat2[0].size()){
        cout<<"dimensiones incorrectas"<<endl;
        exit(1);
    }
    int dim_a=mat1.size();
    int dim_b=mat1[0].size();
    double error=0;
    for (size_t i = 0; i < dim_a; i++){
        for (size_t j = 0; j < dim_b; j++){
            error+=abs(mat1[i][j])-abs(mat2[i][j]);
        }
    }
    return error;
}