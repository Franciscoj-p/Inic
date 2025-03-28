/*
Nombre: Juan Francisco Popo Obando
Correo: juan.francisco.popo@correounivalle.edu.co
Nombre: Juan Esteban Valencia Carvajal
Correo: juan.valencia.carvajal@correounivalle.edu.co
Nombre: Juan José Piedrahita Ipial
Correo: Juan.ipial@correounivalle.edu.co

Paso 1: Análisis del problema
Descripcion: Una sala de cine requiere un programa que facilite el cálculo del monto total de las compras de sus
clientes en la confitería. Este cálculo debe incluir tanto el Impuesto al Valor Agregado (IVA) como los
descuentos por cantidad de unidades adquiridas. El valor total se calculará considerando:
-IVA del 19%, aplicado sobre el costo total de los productos adquiridos.
-Descuentos por cantidad comprada:
- 10% si compra 3 o 4 unidades de un mismo producto.
- 15% si compra más de 4 unidades de un mismo producto.
los descuentos se aplican sobre el subtotal antes del IVA, garantizando
que los clientes obtengan beneficios al comprar en mayor cantidad.

Entradas: opcion, cantidad
Salidas: subtotal, iva, descuento, total

Paso 2: Pseudocódigo
Inicio 
    Inicio decimal desc10(decimal subtotal)
        retornar(subtotal * 0.10)

    Fin
    Inicio decimal desc15(decimal subtotal)
        retornar(subtotal * 0.15)

    Fin
    Inicio decimal fIva(decimal subtotal)
        retornar(subtotal * 0.19)
    Fin
    Inicio decimal subt(cadena opcion, entero cantidad)
        Si opcion == "1" Entonces
            retornar 12000 * cantidad
        Sino Si opcion == "2" Entonces
            retornar 15000 * cantidad
        Sino Si opcion == "3" Entonces
            retornar 10000 * cantidad
        Sino
            retornar 0
    Fin
    Inicio main()
        opcion: cadena
        cantidad: entero 
        sub = 0, iva = 0, desc = 0: decimal 

        mostrar("Menú de Compras:")
        mostrar("1. Entradas - Valor: $12.000")
        mostrar("2. Palomitas - Valor: $15.000")
        mostrar("3. Bebida x 1000 ml - Valor: $10.000")
        mostrar("4. Salir.")

        Mientras opcion != "4" Hacer
            preguntar(opcion)

            Si opcion == "4" Entonces
                salir
            Fin

            preguntar(cantidad)
            
            Si cantidad <= 0 Entonces
                mostrar("Cantidad no valida")
                continuar
            Sino Si cantidad == 3 o cantidad == 4 Entonces
                mostrar("Tiene un descuento del 10%")
                desc += desc10(subt(opcion, cantidad))
            Sino Si cantidad > 4 Entonces
                mostrar("Tiene un descuento del 15%")
                desc += desc15(subt(opcion, cantidad))
            Fin 

            sub += subt(opcion, cantidad)
            iva += fIva(subt(opcion, cantidad))
            mostrar("Subtotal: " + sub)
            mostrar("IVA: " + iva)
            mostrar("Descuento: " + desc)
        Fin

        mostrar("Total: " + (sub - desc) + iva)
Fin

Paso 3: Pruebas de escritorio
opcion cantidad subtotal iva descuento total
1       2       24000   4560    0       28560
2       3       45000   8550    4500    49050
3       5       50000   9500    7500    52000

Paso 4: Codificación en C++
*/

#include <iostream>

using namespace std;

double desc10(double subtotal) {
    return subtotal * 0.10;
}

double desc15(double subtotal) {
    return subtotal * 0.15;
}

double fIva(double subtotal) {
    return subtotal * 0.19;
}

double subT(string opcion, int cantidad) {
    if (opcion == "1") {
        return 12000 * cantidad;
    } else if (opcion == "2") {
        return 15000 * cantidad;
    } else if (opcion == "3") {
        return 10000 * cantidad;
    } else {
        return 0;
    }
}

int main() {
    string opcion;
    int cantidad;
    double sub = 0, iva = 0, desc = 0;

    cout << "Menú de Compras:\n";
    cout << "1. Entradas - Valor: $12.000\n";
    cout << "2. Palomitas - Valor: $15.000\n";
    cout << "3. Bebida x 1000 ml - Valor: $10.000\n";
    cout << "4. Salir.\n";

    while (opcion != "4") {
        
        cout << "Digite su opción:\n";
        cin >> opcion;

        if (opcion == "4") {
            break;
        }

        do {
            cout << "Digite la cantidad de productos que desea comprar:\n";
            cin >> cantidad;

            if (cantidad <= 0) {
            cout << "Cantidad no valida\n";
            }
        } while (cantidad <= 0);

        if (cantidad == 3 || cantidad == 4) {
            cout << "Tiene un descuento del 10%\n";
            desc += desc10(subT(opcion, cantidad));
        }
        else if (cantidad > 4){
            cout << "Tiene un descuento del 15%\n";
            desc += desc15(subT(opcion, cantidad));
        } 

        sub += subT(opcion, cantidad);
        iva += fIva(subT(opcion, cantidad));
        cout << "Subtotal: " << sub << endl;
        cout << "IVA: " << iva << endl;
        cout << "Descuento: " << desc << endl;
    }

    cout << "Total: " << (sub - desc) + iva << endl;

}