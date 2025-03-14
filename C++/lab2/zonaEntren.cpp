/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co
Nombre: Juan Esteban Valencia Carvajal
Correo: juan.valencia.carvajal@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: En un gimnasio, se registran los datos de cada nuevo usuario para realizar un seguimiento de su
condición física. Al inscribirse, se solicitan los siguientes datos: Nombre, edad y frecuencia cardíaca
en reposo - FCR (latidos por minuto). El programa debe calcular la Frecuencia Cardíaca Máxima
(FCM) usando la siguiente fórmula:
FCM = 220 − edad
Desarrollar un programa que defina una función donde se calcule la zona de entrenamiento para un
usuario segun su Frecuencia Cardiaca en Reposo (FCR) y su Frecuencia Cardiaca Máxima (FCM). La FCM se calcula
como 220 - edad.

Entradas: Nombre, Edad, FCR
Salidas: FCM, Zona

Paso 2: Pseudocódigo
Inicio
    Inicio cadena zona(entero fcr, entero fcm)
        Si fcr < (fcm * 0.5) Entonces
            Retornar "Baja Intensidad"
        Sino Si (fcm * 0.51) <= fcr y fcr <= (fcm * 0.75) Entonces
            Retornar "Moderada Intensidad"
        Sino Si fcr >= (fcm * 0.76) Entonces
            Retornar "Alta Intensidad"
        Sino
            Retornar "Error"
    Fin

    Inicio entero main
        nombre: cadena
        edad, fcr, fcm: entero
        preguntar(nombre)
        preguntar(edad)
        preguntar(fcr)
        fcm = 220 - edad
        Mostrar ("PACIENTE: " + nombre)
        Mostrar ("EDAD: " + edad)
        Mostrar ("FCR: " + fcr)
        Mostrar ("FCM:" + fcm)
        Mostrar ("ZONA: " + zona(fcr, fcm))
        Retornar 0
    Fin
Fin

Paso 3: Pruebas de escritorio
nombre           edad    fcr     fcm     zona
Fernanda Perez    30     150     190     Alta Intensidad
Estela Ramirez    45     120     175     Moderada Intensidad
German Suarez     19     110     201     Moderada Intensidad


Paso 4: Codificación en C++
*/
#include <iostream>
#include <cmath>

using namespace std;

string zona(int fcr, int fcm) {
    if (fcr < (fcm * 0.5)) {
        return "Baja Intensidad";
    } else if ((fcm * 0.51) <= fcr && fcr <= (fcm * 0.75)) {
        return "Moderada Intensidad";
    } else if (fcr >= (fcm * 0.76)) {
        return "Alta Intensidad";
    } else {
        return "Error";
    }
}

int main() {
    string nombre;
    int edad, fcr, fcm;
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    cout << "Ingrese su edad: ";
    cin >> edad;
    cout << "Ingrese su FCR: ";
    cin >> fcr;
    fcm = 220 - edad;
    cout << "PACIENTE: " << nombre << endl;
    cout << "FCM:" << fcm << endl;
    cout << "ZONA: " << zona(fcr, fcm) << endl;
    return 0;
}