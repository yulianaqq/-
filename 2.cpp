#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    
    vector<vector<int>> transposed_matrix(cols, vector<int>(rows));

   
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed_matrix[j][i] = matrix[i][j];
        }
    }
    
    return transposed_matrix;
}


void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    
    cout << "Original Matrix:" << endl;
    print_matrix(matrix);

    
    vector<vector<int>> transposed_matrix = transpose(matrix);

  
    cout << "Transposed Matrix:" << endl;
    print_matrix(transposed_matrix);

    return 0;
}
