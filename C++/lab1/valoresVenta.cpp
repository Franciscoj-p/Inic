/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co
Nombre: Juan Esteban Valencia Carvajal
Correo: juan.valencia.carvajal@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: En una tienda virtual que se dedica a la venta de equipos tecnológicos se quiere conocer el IVA, el
costo, y la ganancia neta de sus productos. Estos tres rubros corresponden al 19%, 61%, y 20%,
respectivamente, y se calculan sobre el valor del producto.
Desarrollar un programa que permita calcular los valores requeridos por la tienda

Entradas: equipo, valor
Salidas: valor, iva, costo, gananciaNeta

Paso 2: Pseudocódigo
Inicio
    equipo: texto 
    valor, iva, costo, gananciaNeta : real
    preguntar(equipo)
    preguntar(valor)
    iva = valor * 0.19
    costo = valor * 0.61
    gananciaNeta = valor * 0.20
    mostrar(equipo)
    mostrar(valor)
    mostrar(iva)
    mostrar(costo)
    mostrar(gananciaNeta)
Fin

Paso 3: Pruebas de escritorio
equipo      valor   iva     costo   gananciaNeta
Tablet      829900  157681  506239  165980
Celular     499900  94981   304939  99980
Portátil    899900  170981  548939  179980

Paso 4: Codificación en C++
*/
#include <iostream>

using namespace std;

int main() {
    string equipo;
    double valor, iva, costo, gananciaNeta;
    cout << "Ingrese el nombre del producto: ";
    getline(cin, equipo);
    cout << "Ingrese el valor del producto: ";
    cin >> valor;
    iva = valor * 0.19;
    costo = valor * 0.61;
    gananciaNeta = valor * 0.20;
    cout << "Datos de la venta" << endl;
    cout << "El producto es: " << equipo << endl;
    cout << "El valor del producto es: " << valor << endl;
    cout << "El IVA del producto es: " << iva << endl;
    cout << "El costo del producto es: " << costo << endl;
    cout << "La ganancia neta del producto es: " << gananciaNeta << endl;
}