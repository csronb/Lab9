#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    
    // Generar cada fila
    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1); // Iniciar fila con 1's
        
        // Llenar la fila con la lógica de Pascal
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        
        // Agregar la fila al triángulo
        triangle.push_back(row);
    }
    
    return triangle;
}

int main() {
    int numRows;
    cout << "Ingresa el número de filas: ";
    cin >> numRows;

    vector<vector<int>> result = generate(numRows);

    // Mostrar el triángulo de Pascal
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j != result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
