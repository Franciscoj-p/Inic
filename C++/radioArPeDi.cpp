/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: Desarrollar un programa que pregunte al usuario el radio de un círculo y muestre el área, el perímetro y el diámetro del círculo.

Entradas: radio
Salidas: area, perimetro, diametro

Paso 2: Pseudocódigo
Inicio
    radio, area, perimetro, diametro : real
    preguntar(radio)
    area = 3.1416 * radio * radio
    perimetro = 2 * 3.1416 * radio
    diametro = 2 * radio
    mostrar(area)
    mostrar(perimetro)
    mostrar(diametro)
Fin

Paso 3: Pruebas de escritorio
radio   area    perimetro   diametro
5       78.54   31.416      10

Paso 4: Codificación en C++
*/
#include <iostream>

using namespace std;

int main() {
    double radio, area, perimetro, diametro;

    cout << "Ingrese el radio del círculo: ";
    cin >> radio;

    area = 3.1416 * radio * radio;
    perimetro = 2 * 3.1416 * radio;
    diametro = 2 * radio;

    cout << "El área del círculo es: " << area << endl;
    cout << "El perímetro del círculo es: " << perimetro << endl;
    cout << "El diámetro del círculo es: " << diametro << endl;
}