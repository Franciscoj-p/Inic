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
    int n;
    float prom, suma = 0, mayor = 0, menor = 5;
    cout << "Cuantas personas vas a ingresar" << endl;
    cin >> n;
    vector<string> nombres;
    vector<float> calificaciones;
    for (int i = 0; i < n; i++) {
        string nombre;
        float calificacion;
        cout << "Ingrese el nombre del estudiante: ";
        cin >> nombre;
        cout << "Ingrese la calificacion del estudiante: ";
        cin >> calificacion;

        nombres.push_back(nombre);
        calificaciones.push_back(calificacion);

        if (calificacion > mayor) {
            mayor = calificacion;
        }
        if (calificacion < menor) {
            menor = calificacion;
        }

    }

    cout << "----------------------" << endl;
    cout << "Los estudiantes ingresados son: " << endl;
    for (int i = 0; i < nombres.size() ; i++) {
        cout << "Nombre: " << nombres[i] << ", Calificacion: " << calificaciones[i] << endl;
        suma += calificaciones[i];
    }

    prom = suma / calificaciones.size();
    cout << "----------------------" << endl;
    cout << "El promedio de las calificaciones es: " << prom << endl;

    cout << "----------------------" << endl;
    cout << "Calificacion mas alta: " << endl;
    for (int i = 0; i < calificaciones.size(); i++) {
        if (calificaciones[i] == mayor) {
            cout << nombres[i] << endl;
            cout << calificaciones[i] << endl;
        }
    }

    cout << "----------------------" << endl;
    cout << "Calificacion mas baja: " << endl;
    for (int i = 0; i < calificaciones.size(); i++) {
        if (calificaciones[i] == menor) {
            cout << nombres[i] << endl;
            cout << calificaciones[i] << endl;
        }
    }
    

}
