/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: Para aprobar un curso, es necesario obtener un
promedio mínimo de 3.0 en tres actividades. Diseñe un programa
que solicite las calificaciones de las dos primeras actividades y
calcule la nota necesaria en la tercera para alcanzar al menos un
promedio de 3.0 como calificación final.

Entradas: nota1, nota2
Salidas: nota3

Paso 2: Pseudocódigo
Inicio
    nota1, nota2, nota3 : real
    preguntar(nota1)
    preguntar(nota2)
    nota3 = 3.0 * 3 - nota1 - nota2
    mostrar(nota3)
Fin

Paso 3: Pruebas de escritorio
nota1   nota2   nota3
2.5     3.0     3.5

Paso 4: Codificación en C++
*/
#include <iostream>

using namespace std;

int main() {
    double nota1, nota2, nota3;
    cout << "Ingrese la nota de la primera actividad: ";
    cin >> nota1;
    cout << "Ingrese la nota de la segunda actividad: ";
    cin >> nota2;
    nota3 = 3.0 * 3 - nota1 - nota2;
    cout << "Necesita una nota de " << nota3 << " en la tercera actividad para aprobar el curso." << endl;
}