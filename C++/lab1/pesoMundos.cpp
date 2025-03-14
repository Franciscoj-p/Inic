/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co
Nombre: Juan Esteban Valencia Carvajal
Correo: juan.valencia.carvajal@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: Un grupo de astronomía quiere desarrollar un programa que permita calcular el peso de una persona
en algunos cuerpos celestes. El programa inicialmente solicita el peso de una persona en el planeta
tierra y luego calcula tres valores: el peso en Venus, en Saturno y en la Luna.

Entradas: pesoTierra
Salidas: masa, pesoVenus, pesoSaturno, pesoLuna

Paso 2: Pseudocódigo
Inicio
    pesoTierra, masa, pesoVenus, pesoSaturno, pesoLuna : real
    preguntar(pesoTierra)
    masa = pesoTierra / 9.8
    pesoVenus = masa * 8.87
    pesoSaturno = masa * 10.44
    pesoLuna = masa * 1.62
    mostrar(masa)
    mostrar(pesoVenus)
    mostrar(pesoSaturno)
    mostrar(pesoLuna)
Fin

Paso 3: Pruebas de escritorio
pesoTierra masa PesoVenus pesoSaturno pesoLuna
84.7        8.65  76.6      90.23        14.0     
55.0        5.61  49.7      58.5         9.0
70.0        7.14  63.3      74.5         11.5
Paso 4: Codificación en C++
*/
#include <iostream>

using namespace std;

int main() {
    double pesoTierra, masa, pesoVenus, pesoSaturno, pesoLuna;
    cout << "Ingrese el peso de la persona en la Tierra(kg): ";
    cin >> pesoTierra;
    masa = pesoTierra / 9.8;
    pesoVenus = masa * 8.87;
    pesoSaturno = masa * 10.44;
    pesoLuna = masa * 1.62;
    cout << "La masa de la persona es: " << masa << " N" << endl;
    cout << "El peso de la persona en Venus es: " << pesoVenus << " N" << endl;
    cout << "El peso de la persona en Saturno es: " << pesoSaturno << " N" << endl;
    cout << "El peso de la persona en la Luna es: " << pesoLuna << " N" << endl;
}