/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: Desarrollar un programa que pregunte al usuario su nombre y muestre un saludo.

Entradas: nombre
Salidas: Saludo

Paso 2: Pseudocódigo
Inicio
    nombre : texto
    preguntar(nombre)
    mostrar(nombre)
Fin

Paso 3: Pruebas de escritorio
nombre Saludo
Juan    Hola, Juan

Paso 4: Codificación en C++
*/
#include <iostream>

using namespace std;

int main() {
    string nombre;
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    cout << "Hola, " << nombre << endl;
}