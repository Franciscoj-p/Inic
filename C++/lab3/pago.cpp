/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co
Nombre: Juan Esteban Valencia Carvajal
Correo: juan.valencia.carvajal@correounivalle.edu.co
Nombre: Juan José Piedrahita Ipial
Correo: Juan.ipial@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: La División de Recursos Humanos de la Universidad requiere un programa que le permita calcular el
neto a pagar para cada uno de sus docentes. Este valor se calcula con base en los pagos y
descuentos que se realizan para cada empleado. Los conceptos de pago y descuento para tener en
cuenta son: pagos: transporte 20%, bonificación de servicios 10%, vacaciones 15%.
descuentos: salud 4%, pensión 4%, ARL 0.3%, retención en la fuente 5%.

Entradas: cantidad, nombre, id, salario
Salidas: totalPagos, totalDescuentos, totalPagar

Paso 2: Pseudocódigo
Inicio
    id, nombre: cadena 
    cantidad: entero
    salario, totalPagos, totalDescuentos, totalPagar, transporte, bon, vacaciones, salud, pension, arl, retefuente: decimal

    Hacer
        preguntar(cantidad)
        Si cantidad <= 0 Entonces
            Escribir "Cantidad no válida. Por favor, intente de nuevo."
    Mientras cantidad <= 0

    i = 1
    Hacer
        preguntar(nombre)
        preguntar(id)
        preguntar(salario)

        transporte = salario * 0.2
        bon = salario * 0.1
        vacaciones = salario * 0.15

        salud = salario * 0.04
        pension = salario * 0.04
        arl = salario * 0.003
        retefuente = salario * 0.05

        totalPagos = salario + transporte + bon + vacaciones
        totalDescuentos = salud + pension + arl + retefuente
        totalPagar = totalPagos - totalDescuentos

        Escribir "\n===== Datos del docente ", i, " ====="
        Escribir "Nombre: ", nombre
        Escribir "No. de Documento: ", id
        Escribir "\n===== Pagos ", i, " ====="
        Escribir "Salario Base: ", salario
        Escribir "Subsidio de Transporte: ", transporte
        Escribir "Bonificación de Servicios: ", bon
        Escribir "Vacaciones: ", vacaciones
        Escribir "\n===== Descuentos ", i, " ====="
        Escribir "Salud: ", salud
        Escribir "Pensión: ", pension
        Escribir "ARL: ", arl
        Escribir "Retefuente: ", retefuente
        Escribir "\n===== Totales ", i, " ====="
        Escribir "Total Pagos: ", totalPagos
        Escribir "Total Descuentos: ", totalDescuentos
        Escribir "Neto a Pagar: ", totalPagar

        cantidad--
        i++

    Mientras cantidad > 0

Fin

Paso 3: Pruebas de escritorio
cantidad nombre id salario totalPagos totalDescuentos totalPagar transporte bon vacaciones salud pension arl retefuente
1       Juan    123 100000  145000      13300           131700   20000   10000   15000   4000    4000    300     5000
1       Esteban 456 200000  290000      26600           263400   40000   20000   30000   8000    8000    600     10000
1       José    789 300000  435000      39900           395100   60000   30000   45000   12000   12000   900     15000


Paso 4: Codificación en C++
*/
#include <iostream>

using namespace std;

int main() {
    string id, nombre;
    int cantidad;
    double salario, totalPagos, totalDescuentos, totalPagar, transporte, bon, vacaciones, salud, pension, arl, retefuente;

    do {
        cout << "Ingrese la cantidad de docentes: ";
        cin >> cantidad;
        if (cantidad <= 0) {
            cout << "Cantidad no válida. Por favor, intente de nuevo.\n";
        }
    } while (cantidad <= 0);
    
    int i = 1;
    do {
        cout << "\nIngrese el nombre del docente "<<i<<": ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingrese el documento de identidad del docente "<<i<<": ";
        cin >> id;
        cout << "Ingrese el salario basico del docente "<<i<<": ";
        cin >> salario;

        //pagos

        transporte = salario * 0.2;
        bon = salario * 0.1;
        vacaciones = salario * 0.15;

        //descuentos

        salud = salario * 0.04;
        pension = salario * 0.04;
        arl = salario * 0.003;
        retefuente = salario * 0.05;

        totalPagos = salario + transporte + bon + vacaciones;
        totalDescuentos = salud + pension + arl + retefuente;
        totalPagar = totalPagos - totalDescuentos;

        cout << "\n===== Datos del docente " <<i<< " =====\n";
        cout << "Nombre: " << nombre << "\n";
        cout << "No. de Documento: " << id << "\n";
        cout << "\n===== Pagos " <<i<< " =====\n";
        cout << "Salario Base: " << salario << "\n";
        cout << "Subsidio de Transporte: " << transporte << "\n";
        cout << "Bonificación de Servicios: " << bon << "\n";
        cout << "Vacaciones: " << vacaciones << "\n";
        cout << "\n===== Descuentos " <<i<< " =====\n";
        cout << "Salud: " << salud << "\n";
        cout << "Pensión: " << pension << "\n";
        cout << "ARL: " << arl << "\n";
        cout << "Retefuente: " << retefuente << "\n";
        cout << "\n===== Totales " <<i<< " =====\n";
        cout << "Total Pagos: " << totalPagos << "\n";
        cout << "Total Descuentos: " << totalDescuentos << "\n";
        cout << "Neto a Pagar: " << totalPagar << "\n";

        cantidad--;
        i++;

    } while (cantidad > 0);
}