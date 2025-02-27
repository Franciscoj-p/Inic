/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: Desarrollar un programa que pregunte al usuario el valor de una venta y calcule el valor del IVA (19%).

Entradas: valorVenta
Salidas: valorIva

Paso 2: Pseudocódigo
Inicio
    valorVenta : entero
    valorIva : real
    preguntar(valorVenta)
    valorIva = valorVenta * 0.19
    mostrar(valorIva)
Fin

Paso 3: Pruebas de escritorio
ValorVenta  ValorIva
120000      22800


Paso 4: Codificación en C++
*/

#include <iostream>

using namespace std;

int main() {
    int valorVenta;
    double valorIva;
    cout << "Ingrese el valor de la venta:\n";
    cin >> valorVenta; 
    valorIva = valorVenta * 0.19;
    cout << "El valor del IVA es: " << valorIva << endl;
}