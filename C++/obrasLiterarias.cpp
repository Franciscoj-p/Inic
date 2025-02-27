/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co
Nombre: Juan Esteban Valencia Carvajal
Correo: juan.valencia.carvajal@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: En una librería se lleva el registro de las obras literarias que se comercializan. De cada obra se
solicitan cinco datos, estos son: el título, el nombre del autor, el lugar y año de la publicación y la
extensión (número de páginas). Desarrollar un programa que permita registrar la información de las
obras.

Entradas: tittle, author, place, year, pages
Salidas: tittle, author, place, year, pages

Paso 2: Pseudocódigo
Inicio
    tittle, author, place, year, pages : texto
    preguntar(tittle)
    preguntar(author)
    preguntar(place)
    preguntar(year)
    preguntar(pages)
    mostrar(tittle)
    mostrar(author)
    mostrar(place)
    mostrar(year)
    mostrar(pages)
Fin

Paso 3: Pruebas de escritorio
tittle      author      place   year    pages
El Quijote  Cervantes   Madrid  1605    863
Rayuela     Cortázar    Paris   1963    564
Maria     Jorge Isaacs  Cali    1867    345
            

Paso 4: Codificación en C++
*/
#include <iostream>

using namespace std;

int main() {
    string tittle, author, place, year, pages;
    cout << "Ingrese el título de la obra: ";
    getline(cin, tittle);
    cout << "Ingrese el nombre del autor: ";
    getline(cin, author);
    cout << "Ingrese el lugar de publicación: ";
    getline(cin, place);
    cout << "Ingrese el año de publicación: ";
    getline(cin, year);
    cout << "Ingrese el número de páginas: ";
    getline(cin, pages);
    cout << "Datos de la obra" << endl;
    cout << "Título: " << tittle << endl;
    cout << "Autor: " << author << endl;
    cout << "Lugar de publicación: " << place << endl;
    cout << "Año de publicación: " << year << endl;
    cout << "Número de páginas: " << pages << endl;
}