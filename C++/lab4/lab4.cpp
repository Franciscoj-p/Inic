/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co
Nombre: Juan Esteban Valencia Carvajal
Correo: juan.valencia.carvajal@correounivalle.edu.co
Nombre: Juan José Piedrahita Ipial
Correo: Juan.ipial@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: 
El programa debe calcular el salario de cada empleado, el gasto semanal en nómina y mostrar los empleados que ganan más que el promedio de la empresa. 
El tamaño de las matrices y vectores debe definirse dinámicamente y el flujo debe ser interactivo a través de un menú.
Entradas: 
Salidas: 

Paso 2: Pseudocódigo
Inicio
    Inicio funcion vacia calcularSalarioTotal
        n = nombres.size() :entero
        m = horas.size() :entero
        salarios = vector(n) :vector
        total = 0 :entero

        for i desde 0 hasta n-1 Hacer
            for j desde 0 hasta m-1 Hacer
                salarios[i] += horas[i][j] * VALOR_HORA
            Fin for
            total += salarios[i]
            mostrar(nombres[i] + salarios[i])
        Fin for
        mostrar(total)
    Fin 
    Inicio funcion vacia calcularGastoSemanal
        n = nombres.size() :entero
        m = horas.size() :entero
        gastos = vector(m) :vector
        total = 0 :entero

        for j desde 0 hasta m-1 Hacer
            for i desde 0 hasta n-1 Hacer
                gastos[j] += horas[i][j] * VALOR_HORA
            Fin for
            total += gastos[j]
            mostrar(gastos[j])
        Fin for
        mostrar(total)
    Fin
    Inicio funcion vacia empleadosSobrePromedio
        n = nombres.size() :entero
        m = horas.size() :entero
        salarios = vector(n) :vector
        total = 0 :entero

        for i desde 0 hasta n-1 Hacer
            for j desde 0 hasta m-1 Hacer
                salarios[i] += horas[i][j] * VALOR_HORA
            Fin for
            total += salarios[i]
        Fin for
        promedio = total / n :decimal

        for i desde 0 hasta n-1 Hacer
            Si salarios[i] > promedio Entonces
                mostrar(nombres[i] + salarios[i])
            Fin Si
        Fin for
    Fin
    Inicio main
        n, m :entero
        opcion :entero

        preguntar(n)
        preguntar(m)

        nombres = vector(n) :vector
        horas = vector(n, vector(m)) :vector

        for i desde 0 hasta n-1 Hacer
            preguntar(nombres[i])
        Fin for

        for i desde 0 hasta n-1 Hacer
            for j desde 0 hasta m-1 Hacer
                preguntar(horas[i][j])
            Fin for
        Fin for


        mostrar(MENÚ)
        preguntar(opcion)

        switch(opcion)
            caso 1:
                calcularSalarioTotal(nombres, horas)
            caso 2:
                calcularGastoSemanal(nombres, horas)
            caso 3:
                empleadosSobrePromedio(nombres, horas)
            caso 4:
                mostrar("Saliendo del programa...")
        Fin switch
    Fin main
Fin

Paso 3: Pruebas de escritorio


Paso 4: Codificación en C++
*/
#include <iostream>
#include <vector>

using namespace std;

const int VALOR_HORA = 10000;

void calcularSalarioTotal(vector<string> nombres, vector<vector<int>> horas) {
    int n = nombres.size();
    int m = horas[0].size();
    vector<int> salarios(n, 0);
    int total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            salarios[i] += horas[i][j] * VALOR_HORA; //1er for recorre personas, segundo salario por semana
        }
        total += salarios[i]; //sumar salarios
        cout << "Salario total de " << nombres[i] << ": $" << salarios[i] << endl;
    }
    cout << "Gasto total en nómina: $" << total << endl;
}
void calcularGastoSemanal(vector<string> nombres, vector<vector<int>> horas) {
    int n = nombres.size();
    int m = horas[0].size();
    vector<int> gastos(m, 0);
    int total = 0;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            gastos[j] += horas[i][j] * VALOR_HORA;
        }
        total += gastos[j];
        cout << "Gasto en la semana $" << j + 1 << ": " << gastos[j] << endl;
    }
    cout << "Gasto total en nómina: $" << total << endl;
}
void empleadosSobrePromedio(vector<string> nombres, vector<vector<int>> horas){
    int n = nombres.size();
    int m = horas[0].size();
    vector<int> salarios(n, 0);
    int total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            salarios[i] += horas[i][j] * VALOR_HORA;
        }
        total += salarios[i];
    }
    double promedio = total / n; //calcular promedio para luego comparar salarios y mostrar los q superen

    cout << "El promedio de la nomina es: $" << promedio << endl;
    cout << "Empleados que ganan más que el promedio:"<< endl;
    for (int i = 0; i < n; i++) {
        if (salarios[i] > promedio) {
            cout << nombres[i] << ": $" << salarios[i] << endl;
        }
    }
}


int main() {
    int n, m;
    int opcion;

    do {
        cout << "Ingrese la cantidad de empleados: ";
        cin >> n;

        cout << "Ingrese la cantidad de semanas: ";
        cin >> m;

        if (n <= 0 || m <= 0) {
            cout << "La cantidad de empleados y semanas debe ser mayor a cero. Intente nuevamente.\n";
        }
    } while (n <= 0 || m <= 0);

    vector<string> nombres(n);
    vector<vector<int>> horas(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        cout << "Nombre del empleado " << i + 1 << ": ";
        cin >> nombres[i];
    }

    for (int i = 0; i < n; i++) {
        cout << "Horas trabajadas por " << nombres[i] << ":\n";
        for (int j = 0; j < m; j++) {
            cout << "  Semana " << j + 1 << ": ";
            cin >> horas[i][j];
        }
    }

    do {
        do {
            cout << "\n--- MENÚ ---\n";
            cout << "1. Calcular salario total por empleado\n";
            cout << "2. Calcular gasto por semana\n";
            cout << "3. Empleados que ganan más que el promedio\n";
            cout << "4. Salir\n";
            cout << "Opción: ";
            cin >> opcion;
            if (opcion < 1 || opcion > 4) {
            cout << "Opción inválida. Por favor, ingrese un número entre 1 y 4.\n";
            }
        } while (opcion < 1 || opcion > 4);
        cout << endl;

        switch (opcion) {
            case 1:
                calcularSalarioTotal(nombres, horas);
                break;
            case 2:
                calcularGastoSemanal(nombres, horas);
                break;
            case 3:
                empleadosSobrePromedio(nombres, horas);
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 4);

    return 0;
}
