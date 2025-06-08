#include "../../include/utils/utils.h"
#include "../../include/utils/types.h"


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
        cerr << "Error opening file: " << strerror(errno) << endl;
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
void print_matix(double**mat,size_matrix size){
    int dim_a=size.i;
    int dim_b=size.j;
    cout<<endl;
    for (size_t i = 0; i < dim_a; i++){
        for (size_t j = 0; j < dim_b; j++){
            cout<<' '<<mat[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}