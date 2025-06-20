#include "../../include/utils/utils.h"


vector<string> split(string& s, const string& delimiter) {
    vector<string> tokens;
    int pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);

    return tokens;
}

template<typename T>
vector<vector<T>>read_matrix(string path){
    vector<vector<T>>matrix;
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Error opening file: " << strerror(errno) << ' '<<path<<endl;
        exit(1);
    }
    string linea;
    int i=0;
    while (getline(input_file,linea))
    {
        vector<T> m;
        matrix.push_back(m);
        vector<string> numeros=split(linea," ");
        for (auto &&numero : numeros){
            T n=stod(numero);
            matrix[i].push_back(n);
        }
        i++;
    }
    return matrix;
}

template<typename T>
void print_matix(vector<vector<T>>mat){
    int dim_a=mat.size();
    int dim_b=mat[0].size();
    cout<<endl;
    for (int i = 0; i < dim_a; i++){
        for (int j = 0; j < dim_b; j++){
            cout<<' '<<mat[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
template<typename T>
void print_matix(basic_matrix<T> mat){
    cout<<endl;
    for (int i = 0; i < mat.size_m.i; i++){
        for (int j = 0; j < mat.size_m.j; j++){
            cout<<' '<<mat.matrix[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
template<typename T>
basic_matrix<T> cast_matrix(vector<vector<T>>mat){
    T**result=nullptr;
    int dim_a=mat.size();
    int dim_b=mat[0].size();
    result=new T*[dim_a];
    for (int i = 0; i < dim_a; i++){
        result[i]=new T[dim_b];
    }
    for (int i = 0; i < dim_a; i++){
        for (int j = 0; j < dim_b; j++){
            result[i][j]=mat[i][j];
        }
        
    }
    basic_matrix<T> r;
    r.matrix=result;
    r.size_m.i=dim_a;
    r.size_m.j=dim_b;
    return r;
}

template<typename T>
T matrix_check(vector<vector<T>>mat1,basic_matrix<T> mat2){
    if(mat1.size()!=mat2.size_m.i&&mat1[0].size()!=mat2.size_m.j){
        cout<<"dimensiones incorrectas"<<endl;
        exit(1);
    }
    int dim_a=mat2.size_m.i;
    int dim_b=mat2.size_m.j;
    T error=0;
    for (int i = 0; i < dim_a; i++){
        for (int j = 0; j < dim_b; j++){
            error+=abs(mat1[i][j])-abs(mat2.matrix[i][j]);
        }
    }
    return error;
}

template<typename T>
T matrix_check(vector<vector<T>>mat1,vector<vector<T>>mat2){
    if(mat1.size()!=mat2.size()&&mat1[0].size()!=mat2[0].size()){
        cout<<"dimensiones incorrectas"<<endl;
        exit(1);
    }
    int dim_a=mat1.size();
    int dim_b=mat1[0].size();
    T error=0;
    for (int i = 0; i < dim_a; i++){
        for (int j = 0; j < dim_b; j++){
            error+=abs(mat1[i][j])-abs(mat2[i][j]);
        }
    }
    return error;
}

template<typename T>
void convert_1d_to_2d(basic_matrix<T>*mat){
    int dim1=mat->size_m.i;
    int dim2=mat->size_m.j;
    T**mat2d=new T*[dim1];
    for (int i = 0; i < dim1; i++){
        mat2d[i]=new T[dim2];
    }
    for (int i = 0; i < dim1; i++){
        for (int j = 0; j < dim2; j++){
            int index=j+i*dim2;
            T el=mat->array[index];
            mat2d[i][j]=el;
        }
    }
    mat->matrix=mat2d;
}

template<typename T>
void convert_2d_to_1d(basic_matrix<T>*mat){
    int dim1=mat->size_m.i;
    int dim2=mat->size_m.j;
    T*mat2d=new T[dim1*dim2];
    for (int i = 0; i < dim1; i++){
        for (int j = 0; j < dim2; j++){
            int dim=i*(dim2)+j;
            T el=mat->matrix[i][j];
            mat2d[dim]=el;
        }
    }
    mat->array=mat2d;
}

template<typename T>
vector<vector<T>> convert_1d_to_2d(vector1d<T> mat){
    int dim1=mat.size_m.i;
    int dim2=mat.size_m.j;
    vector<vector<T>> mat2d;//(dim1, std::vector<T>(dim2));
    for (int i = 0; i < dim1; i++){
        vector<T> row(mat.array.begin() + i * dim2, mat.array.begin() + (i + 1) * dim2);
        mat2d.push_back(row);
    }
    return mat2d;
}
template<typename T>
vector1d<T> convert_2d_to_1d(vector<vector<T>>mat){
    int dim_a=mat.size();
    int dim_b=mat[0].size();
    std::vector<T> flat_vector;
    for (const auto& row : mat) {
        flat_vector.insert(flat_vector.end(), row.begin(), row.end());
    }
    vector1d<T> res;
    res.array=flat_vector;
    res.size_m.i=dim_a;
    res.size_m.j=dim_b;
    return res;
}

template<typename T>
void clean_matrix(basic_matrix<T>*mat){
    if(mat->matrix!=nullptr){
        for (int i = 0; i < mat->size_m.i; i++){
            delete[] mat->matrix[i];
        }
        delete[] mat->matrix;
        mat->matrix=nullptr;
    }
    if(mat->array!=nullptr){
        delete[] mat->array;
        mat->array=nullptr;
    }
}

template<typename T>
vector<vector<T>> gnererate_random_matrix(int dim_a, int dim_b) {
    random_device rd;
    mt19937 generator(rd());
    normal_distribution distribution(5.0,2.0);
    vector<vector<T>> matrix(dim_a, vector<T>(dim_b,0));
    for (int i = 0; i < dim_a; ++i) {
        for (int j = 0; j < dim_b; ++j) {
            auto element = distribution(generator);
            matrix[i][j] = static_cast<T>(element);//static_cast<T>(rand() % 100); // Random values between 0 and 99
        }
    }
    return matrix;
}