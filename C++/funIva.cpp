/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: 

Entradas: 
Salidas: 

Paso 2: Pseudocódigo
Inicio
    Inicio real Iva(entero valorVenta)
            retornar (valorVenta * 0.19)
    Fin

    Inicio entero main()
        valorVenta: entero
        preguntar(valorVenta)
        mostrar(Iva(valorVenta))
    Fin
    
Fin

Paso 3: Pruebas de escritorio


Paso 4: Codificación en C++
*/

#include <iostream>

using namespace std;

float Iva(int valorVenta) {
    return valorVenta * 0.19;
}

int main() {
    int valorVenta;
    cout << "Ingrese el valor de la venta:\n";
    cin >> valorVenta; 
    cout << "El valor del IVA es: " << Iva(valorVenta) << endl;
}