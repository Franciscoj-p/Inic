/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: Desarrollar un programa que registre y procese los resultados de una encuesta sobre el uso del tiempo libre, obteniendo ciertos datos estadísticos a partir de la información ingresada por los usuarios.
El programa debe registrar información de una encuesta sobre cómo usan su tiempo libre diferentes personas. Además de almacenar los datos, debe analizarlos para producir estadísticas específicas relacionadas con tiempo libre, actividades, edad e índice de masa corporal (IMC).

Entradas: n, edad, tiempoLibre, actividad, peso, altura
Salidas: contadorDormir, contadorLeer, contadorDeporte, contadorObesidad, promedioEdad

Paso 2: Pseudocódigo
Inicio

    flotante IMC(flotante peso, flotante altura)
        altura = altura / 100
        retornar peso / (altura * altura)
    Fin IMC

    cadena clasificacionIMC(flotante imc)
        Si imc < 18.5 Entonces
            retornar "Bajo peso"
        Sino Si imc >= 18.5 Y imc < 24.9 Entonces
            retornar "Peso normal"
        Sino Si imc >= 25 Y imc < 29.9 Entonces
            retornar "Sobrepeso"
        Sino
            retornar "Obesidad"
    Fin clasificacionIMC

    entero main()
        n: entero
        preguntar(n)

        contDormir, contLeer, contDeporte, contObesidad, sumEdades, tiempoLibre, actividad, edad: entero

        Mientras i <= n Hacer
            preguntar(tiempoLibre)
            preguntar(actividad)

            Si actividad == 1 Entonces
                contLeer++
            Sino Si actividad == 3 Entonces
                contDeporte++
                preguntar(peso)
                preguntar(altura)
                imc: flotante = IMC(peso, altura)
                clasificacion: cadena = clasificacionIMC(imc)
                mostrar(imc)
                mostrar(clasificacion)
                    Si clasificacion == "Obesidad" Ó clasificacion == "Sobrepeso" Entonces
                        contObesidad++
            Sino Si actividad == 4 Y tiempoLibre == 3 Entonces
                contDormir++
            i++
        Fin mientras

        mostrar(contDormir)
        mostrar((contLeer*100) / n)
        mostrar(sumaEdades/n) 
        mostrar(contObesidad)

Fin main

Paso 3: Pruebas de escritorio
Prueba 1 
        n       edad    tiempoLibre   actividad    peso    altura
        2                  
    persona 1 :  18         3            4
    persona 2 :  22         1            1

    resultados:
        1 persona/s tienen más de 9 horas libres y prefieren dormir.
        50% de las personas encuestadas prefieren leer
        En promedio, las personas tienen 20 años
        De la/s 0 persona/s que hacen deporte, 0 tienen obesidad o sobrepeso.

Prueba 2 
        n       edad    tiempoLibre   actividad    peso    altura
        3
    persona 1 :  30         2              1 
    persona 2 :  27         1              3        68       172   
    persona 3 :  25         3              2

    resultados:
        IMC persona 2: 22.9854 → Peso normal
        0 persona/s tienen más de 9 horas libres y prefieren dormir.
        33.3333% de las personas encuestadas prefieren leer
        En promedio, las personas tienen 27 años
        De la/s 1 persona/s que hacen deporte, 0 tienen obesidad o sobrepeso.


Prueba 3 
        n       edad    tiempoLibre   actividad    peso    altura
        3
    persona 1 :  40         2             3         95       170
    persona 2 :  19         1             3         60       160
    persona 3 :  22         3             4         

    resultados:
        IMC persona 1: 32.8731 → Obesidad
        IMC persona 2: 23.4375 → Peso normal

        1 persona/s tienen más de 9 horas libres y prefieren dormir.
        0% de las personas encuestadas prefieren leer
        En promedio, las personas tienen 27 años
        De la/s 2 persona/s que hacen deporte, 1 tienen obesidad o sobrepeso.


Paso 4: Codificación en C++
*/
#include <iostream>

using namespace std;

float IMC(float peso, float altura) {
    altura = altura / 100;
    return peso / (altura * altura);
}

string clasificacionIMC(float imc) {
    if (imc < 18.5) {
        return "Bajo peso";
    } else if (imc >= 18.5 && imc < 24.9) {
        return "Peso normal";
    } else if (imc >= 25 && imc < 29.9) {
        return "Sobrepeso";
    } else {
        return "Obesidad";
    }
}

int main() {
    int n;
    do {
        cout << "Ingrese el número de encuestas a realizar: ";
        cin >> n;

        if (n <= 0) {
            cout << "El número de encuestas debe ser mayor a 0. Por favor intente nuevamente.\n";
        }
    } while (n <= 0);

    //contadores
    int contDormir = 0;
    int contLeer = 0;
    int contDeporte = 0;
    int contObesidad = 0;
    int sumaEdades = 0;

    for (int i = 1; i <= n; i++) {

        int tiempoLibre, actividad, edad;
        cout << "\nPersona #" << i << endl;

        do {
            cout << "Cuantos años tiene?: ";
            cin >> edad;

            if (edad <= 0) {
                cout << "Entrada inválida. Por favor ingrese un valor mayor a 0.\n";
            }
        } while (edad <= 0);
        sumaEdades += edad; 

        do {
            cout << "Cuanto tiempo libre tiene a la semana? ('1' = menos de 6h, '2' = 6 a 9h, '3'= mas de 9h): ";
            cin >> tiempoLibre;

            if (tiempoLibre < 1 || tiempoLibre > 3) {
                cout << "Entrada inválida. Por favor ingrese un valor entre 1 y 3.\n";
            }
        } while (tiempoLibre < 1 || tiempoLibre > 3);

        do {
            cout << "Cual es la actividad que mas realiza en su tiempo libre? ('1' = Leer, '2' = Ver television, '3' = Hacer deporte, '4' = Dormir): ";
            cin >> actividad;

            if (actividad < 1 || actividad > 4) {
                cout << "Entrada inválida. Por favor ingrese un valor entre 1 y 4.\n";
            }
        } while (actividad < 1 || actividad > 4);

        if (actividad == 1) {
            contLeer++;
        } else if (actividad == 3) {
            contDeporte++;

            float peso, altura;
            do {
                cout << "Ingrese su peso (en kg): ";
                cin >> peso;
                if (peso <= 0) cout << "El peso debe ser mayor a 0.\n";
            } while (peso <= 0);
            
            do {
                cout << "Ingrese su altura (en centimetros): ";
                cin >> altura;
                if (altura <= 0) cout << "La altura debe ser mayor a 0.\n";
            } while (altura <= 0);
            
            float imc = IMC(peso, altura);
            string clasificacion = clasificacionIMC(imc);
            cout << "Su IMC es: " << imc << endl;
            cout << "Clasificación: " << clasificacion << endl;
            if (clasificacion == "Obesidad" || clasificacion == "Sobrepeso") {
                contObesidad++;
            }

        } else if (actividad == 4 && tiempoLibre == 3) {
            contDormir++;
        }

    }

    cout << "\nResultados de la encuesta:\n";
    cout << contDormir << " persona/s tienen más de 9 horas libres y prefieren dormir." << endl;
    cout << (contLeer * 100.0) / n << "% de las personas encuestadas prefieren leer " <<endl;
    cout << "En promedio, las personas tienen " << sumaEdades/n << " años" << endl; 
    cout << "De la/s "<< contDeporte <<" persona/s que hacen deporte, " << contObesidad << " tienen obesidad o sobrepeso."<< endl;
}