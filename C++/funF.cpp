/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: 

Entradas: 
Salidas: 

Paso 2: Pseudocódigo
Inicio
    Inicio real f(entero a, entero b)
            retornar (3*pow(a, 2) + 2*a*b - 7)
    Fin

    Inicio entero main()
        a, b: entero
        preguntar(a)
        preguntar(b)
        mostrar(f(a, b))
    
Fin

Paso 3: Pruebas de escritorio


Paso 4: Codificación en C++
*/

#include <iostream>
#include <cmath>

using namespace std;

float f(int a, int b) {
    return 3*pow(a, 2) + 2*a*b - 7;
}

int main() {
    int a, b;
    cout << "Ingrese el valor de a:\n";
    cin >> a;
    cout << "Ingrese el valor de b:\n";
    cin >> b;
    cout << "El resultado de la función es: " << f(a, b) << endl;
}