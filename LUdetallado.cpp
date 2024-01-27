#include <iostream>
const int MAX = 50;
using namespace std;
int cont=0;
char matriz;
void mostrar(double x[MAX][MAX],char matriz, int n){
    cout << "\nMatriz "<<matriz<<":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << x[i][j] << ' ';
            }
            cout << '\n';
        }
}
// Función para descomposición LU
void factorizacionLU(double a[MAX][MAX], double l[MAX][MAX], double u[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            l[i][j] = 0.0;
            u[i][j] = 0.0;
           
        }
    }   
    mostrar(l,'l',n);
    mostrar(u,'u',n);
    for (int i = 0; i < n; i++) {
        // L tiene unos en la diagonal
        l[i][i] = 1.0;
        mostrar(l,'l',n);
        for (int j = i; j < n; j++) {
            // Calcular el valor de U
            u[i][j] = a[i][j];
            for (int k = 0; k < i; k++) {
                u[i][j] -= l[i][k] * u[k][j];
                mostrar(u,'u',n);
            }
            mostrar(u,'u',n);
        }

        for (int j = i + 1; j < n; j++) {
            // Calcular el valor de L
            l[j][i] = a[j][i];
            for (int k = 0; k < i; k++) {
                l[j][i] -= l[j][k] * u[k][i];
                mostrar(l,'l',n);
            }
            l[j][i] /= u[i][i];
            mostrar(l,'l',n);
        }
        cout<<"________________________________________________________________"<<endl;
    }
    
}

int main() {
    int n;

    // Crear una matriz de ejemplo
    cout << "Ingrese el tamanio de la matriz (n): ";
    cin >> n;

    if (n > MAX) {
        cerr << "El tamanio de la matriz excede el limite permitido.\n";
        return 1;
    }else{
        double matriz[MAX][MAX];
        double L[MAX][MAX], U[MAX][MAX];

        cout << "Ingrese los elementos de la matriz:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "Matriz[" << i + 1 << "][" << j + 1 << "]: ";
                cin >> matriz[i][j];
            }
        }

        // Realizar la descomposición LU
        factorizacionLU(matriz, L, U, n);

        // Imprimir matrices L y U
        cout << "\nMatriz L:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << L[i][j] << ' ';
            }
            cout << '\n';
        }

        cout << "\nMatriz U:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << U[i][j] << ' ';
            }
            cout << '\n';
        }

        return 0;
    }
}
