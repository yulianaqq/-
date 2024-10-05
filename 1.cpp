#include <iostream>
#include <string>

using namespace std;


void printMatrix(string* matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        cout << matrix[i] << endl;
    }
}


string* removeRow(string* matrix, int& rows, int rowToRemove) {
    if (rowToRemove < 0 || rowToRemove >= rows) {
        cout << "Invalid row number!" << endl;
        return matrix;
    }

   
    string* newMatrix = new string[rows - 1];


    int newRowIndex = 0;
    for (int i = 0; i < rows; ++i) {
        if (i != rowToRemove) {
            newMatrix[newRowIndex] = matrix[i];
            newRowIndex++;
        }
    }

    
    delete[] matrix;

  
    rows--;

    return newMatrix;
}

int main() {
    int rows = 4;


    string* matrix = new string[rows];
    matrix[0] = "First row";
    matrix[1] = "Second row";
    matrix[2] = "Third row";
    matrix[3] = "Fourth row";

    cout << "Initial matrix:" << endl;
    printMatrix(matrix, rows);

   
    int rowToRemove = 2;
    matrix = removeRow(matrix, rows, rowToRemove);

    cout << "\nMatrix after removing the row:" << endl;
    printMatrix(matrix, rows);

  
    delete[] matrix;

    return 0;
}
