/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: 

Entradas: 
Salidas: 

Paso 2: Pseudocódigo
Inicio
    
Fin

Paso 3: Pruebas de escritorio


Paso 4: Codificación en C++
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    float nota;
    vector <float> fila;
    vector <vector<float>> matriz;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Ingrese la nota "; cin >> nota;
            fila.push_back(nota);
        }
        matriz.push_back(fila);
        fila.clear();
    }
 
    cout << "Notas:" << endl;
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[0].size(); j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}