/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co
Nombre: Juan Esteban Valencia Carvajal
Correo: juan.valencia.carvajal@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: Desarrollar un programa que permita evaluar una función por partes. Dado un valor de x se calcula el
valor de f(x) utilizando la función que se muestra a continuación:
f(x) =
3x³ + 3.5, si x < 0
4x²- 10.8, si x >= 0
El programa a desarrollar debe definir una función en la que se calcula el valor de f(x). 

Entradas: X
Salidas: fx

Paso 2: Pseudocódigo
Inicio
    Inicio real fx(real x)
        Si x < 0 Entonces
            Retornar 3*pow(x, 3) + 3.5
        Sino Si x >= 0 Entonces
            Retornar 4*pow(x, 2) - 10.8
        Fin
    Inicio entero main()
        x: real
        preguntar(x)
        mostrar("El valor de f(x) es: " + fx(x))
    Fin
Fin

Paso 3: Pruebas de escritorio
x            fx
-2.6       -49.228
-3.2       -94.804
0.2        -10.64

Paso 4: Codificación en C++
*/
#include <iostream>
#include <cmath>

using namespace std;

double fx(double x) {
    if (x < 0) {
        return 3.0*pow(x, 3.0) + 3.5;
    } else if (x >= 0) {
        return 4.0*pow(x, 2.0) - 10.8;
    }else{
        return 0;
    }
}

int main() {
    float x;
    cout << "Ingrese el valor de x:\n";
    cin >> x;
    cout << "f("<< x << ")= " << fx(x) << endl;
}