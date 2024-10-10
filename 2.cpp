#include <iostream>

using namespace std;


int* create_matrix(int rows, int cols) {
    return new int[rows * cols];
}


int get_element(int* matrix, int rows, int cols, int i, int j) {
    return matrix[i * cols + j];
}


void set_element(int* matrix, int rows, int cols, int i, int j, int value) {
    matrix[i * cols + j] = value;
}


int* transpose_matrix(int* matrix, int rows, int cols) {
    int* transposed_matrix = create_matrix(cols, rows);
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            set_element(transposed_matrix, cols, rows, j, i, get_element(matrix, rows, cols, i, j));
        }
    }

    return transposed_matrix;
}


void print_matrix(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << get_element(matrix, rows, cols, i, j) << " ";
        }
        cout << endl;
    }
}


void delete_matrix(int* matrix) {
    delete[] matrix;
}

int main() {
    int rows = 3;
    int cols = 4;

  
    int* matrix = create_matrix(rows, cols);
    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            set_element(matrix, rows, cols, i, j, value++);
        }
    }

    cout << "Original matrix:" << endl;
    print_matrix(matrix, rows, cols);

    
    int* transposed_matrix = transpose_matrix(matrix, rows, cols);

    cout << "Transported matrix:" << endl;
    print_matrix(transposed_matrix, cols, rows);


    delete_matrix(matrix);
    delete_matrix(transposed_matrix);

    return 0;
}
