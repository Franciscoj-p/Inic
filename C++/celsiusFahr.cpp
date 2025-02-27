/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: Desarrollar un programa que pregunte al usuario la temperatura en grados Celcius y muestre la temperatura en grados Fahrenheit.

Entradas: celcius
Salidas: fahrenheit

Paso 2: Pseudocódigo
Inicio
    celcius, fahrenheit : real
    preguntar(celcius)
    fahrenheit = (celcius * 9/5) + 32
    mostrar(fahrenheit)
Fin

Paso 3: Pruebas de escritorio
Celsius  Fahrenheit
20       68

Paso 4: Codificación en C++
*/
#include <iostream>

using namespace std;

int main() {
    float celcius, fahrenheit;
    cout << "Ingrese la temperatura en grados Celcius:\n";
    cin >> celcius;
    fahrenheit = (celcius * 9/5.0) + 32;
    cout << "La temperatura en grados Fahrenheit es: " << fahrenheit << endl;
}