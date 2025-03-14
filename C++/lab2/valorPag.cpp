/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co
Nombre: Juan Esteban Valencia Carvajal
Correo: juan.valencia.carvajal@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: Un club de ajedrez ofrece membresías con tarifas diferenciadas según la edad de los jugadores. Se
requiere desarrollar un programa que calcule el valor total a pagar según la edad del usuario y la
cantidad de meses de inscripción. Para cada persona, el programa debe solicitar los siguientes datos:
Nombre, edad y la cantidad de meses a pagar.
definir una función en la que se calculan los valores de salida para un jugador.

Entradas: edad, meses
Salidas: valor

Paso 2: Pseudocódigo
Inicio
    Inicio cadena categoria(entero edad)
        Si edad <= 10 Entonces
            Retornar "Novatos"
        Sino Si 11 <= edad <= 20 Entonces
            Retornar "Juvenil"
        Sino Si 21 <= edad <= 50 Entonces
            Retornar "Avanzados"
        Sino Si edad >= 51 Entonces
            Retornar "Maestros"
    Fin
    Inicio entero valor(cadena categoria, entero meses)
        Si categoria == "Novatos" Entonces
            Retornar 25000 * meses
        Sino Si categoria == "Juvenil" Entonces
            Retornar 35000 * meses
        Sino Si categoria == "Avanzados" Entonces
            Retornar 45000 * meses
        Sino Si categoria == "Maestros" Entonces
            Retornar 30000 * meses
    Fin
    Inicio entero main()
        edad, meses: entero
        nombre: cadena
        preguntar(nombre)
        preguntar(edad)
        preguntar(meses)
        mostrar("NOMBRE: " + nombre)
        mostrar("CATEGORIA: " + categoria(edad))
        mostrar("VALOR A PAGAR: " + valor(categoria(edad), meses))
    Fin
Fin

Paso 3: Pruebas de escritorio
nombre              edad    meses   valor   categoria
Andrea Villegas     6        5      125000  Novatos
Ingrid Hernandez    25       2      135000   Avanzados
Samuel Apraez       67       3      90000   Maestros
Paso 4: Codificación en C++
*/
#include <iostream>

using namespace std;

string categoria(int edad) {
    if (edad <= 10) {
        return "Novatos";
    } else if (11 <= edad && edad <= 20) {
        return "Juvenil";
    } else if (21 <= edad && edad <= 50) {
        return "Avanzados";
    } else if(edad >= 51) {
        return "Maestros";
    }else{
        return "Error";
    }
}

int valor(string categoria, int meses){
    if (categoria == "Novatos") {
        return 25000 * meses;
    } else if (categoria == "Juvenil") {
        return 35000 * meses;
    } else if (categoria == "Avanzados") {
        return 45000 * meses;
    } else if (categoria == "Maestros") {
        return 30000 * meses;
    }else{
        return 0;
    }
}

int main() {
    int edad, meses;
    string nombre;
    cout << "Ingrese el nombre del jugador:\n";
    getline(cin, nombre);
    cout << "Ingrese la edad del jugador:\n";
    cin >> edad;
    cout << "Ingrese los meses que lleva en el club:\n";
    cin >> meses;
    cout << "NOMBRE: " << nombre << endl;
    cout << "CATEGORIA: " << categoria(edad) << endl;
    cout << "VALOR A PAGAR: " << valor(categoria(edad), meses) << endl;
}