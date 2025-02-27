/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: En una tienda online se venden pines virtuales de
Netflix a $20.000 c/u. El usuario ingresa la cantidad de pines a
comprar y la aplicación debe mostrar tres valores: el total a pagar,
el IVA recaudado (19% del total a pagar) y la ganancia neta (total
a pagar – iva).

Entradas: pines
Salidas: total, iva, ganancia

Paso 2: Pseudocódigo
Inicio
    pines : entero
    total, iva, ganancia : real
    preguntar(pines)
    total = pines * 20000
    iva = total * 0.19
    ganancia = total - iva
    mostrar(total)
    mostrar(iva)
    mostrar(ganancia)
Fin

Paso 3: Pruebas de escritorio
pines   total   iva     ganancia
5       100000  19000   81000

Paso 4: Codificación en C++
*/
#include <iostream>

using namespace std;

int main() {
    int pines;
    double total, iva, ganancia;

    cout << "Ingrese la cantidad de pines a comprar: ";
    cin >> pines;

    total = pines * 20000;
    iva = total * 0.19;
    ganancia = total - iva;

    cout << "Resumen de la compra" << endl;
    cout << "Cantidad de pines: " << pines << endl;
    cout << "Total a pagar: " << total << endl;
    cout << "IVA recaudado: " << iva << endl;
    cout << "Ganancia neta: " << ganancia << endl;
}