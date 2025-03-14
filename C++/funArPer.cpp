/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: 

Entradas: 
Salidas: 

Paso 2: Pseudocódigo
Inicio
    Inicio doble calArea(alto, ancho)
        retornar(alto * ancho)
    Fin

    Inicio doble calPerimetro(alto, ancho)
        retornar(2 * (alto + ancho))
    Fin
    Inicio entero main()
        alto, ancho: flotante
        preguntar(alto)
        preguntar(ancho)
        mostrar(calArea(alto, ancho))
        mostrar(calPerimetro(alto, ancho))
    Fin
Fin

Paso 3: Pruebas de escritorio


Paso 4: Codificación en C++
*/

#include <iostream>
#include <cmath>

using namespace std;

double calArea(float alto, float ancho) {
    return alto * ancho;
}

double calPerimetro(float alto, float ancho) {
    return 2 * (alto + ancho);
}

int main() {
    float alto, ancho;
    cout << "Ingrese el alto del rectángulo:\n";
    cin >> alto;
    cout << "Ingrese el ancho del rectángulo:\n";
    cin >> ancho;
    cout << "El área del rectángulo es: " << calArea(alto, ancho) << endl;
    cout << "El perímetro del rectángulo es: " << calPerimetro(alto, ancho) << endl;
}
