#include <iostream>
#include <cstdlib>

using namespace std;

void menuBusqueda();
void menuCompresion();
void menuCifrado();

int main() {
    int opcion;

    do {
        system("cls");
        cout << "        SISTEMA GESTOR DE CONTRASENAS        \n";
        cout << "1. Modulo de Busqueda\n";
        cout << "2. Modulo de Compresion\n";
        cout << "3. Modulo de Cifrado\n";
        cout << "0. Salir\n";
        cout << "---------------------------------------------\n";
        cout << "Seleccione una opcion de las anteriores: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            menuBusqueda();
            break;
        case 2:
            menuCompresion();
            break;
        case 3:
            menuCifrado();
            break;
        case 0:
            cout << "\nSaliendo del programa...\n";
            break;
        default:
            cout << "\nOpcion invalida. Intente nuevamente.\n";
        }

        system("pause");
    } while (opcion != 0);

    return 0;
}

// Modulo de busqueda
void menuBusqueda() {
    system("cls");
    cout << "      MODULO DE BUSQUEDA DE CONTRASENAS      \n";
    cout << "Ejecutando prueba: Prueba Busqueda!\n";
}


// Modulo de compresion
void menuCompresion1() {
    system("cls");
    cout << "      MODULO DE COMPRESION DE DATOS          \n";
    cout << "Ejecutando prueba: Prueba Compresion!\n";
}


// Modulo de cifrado
void menuCifrado1() {
    system("cls");
    cout << "         MODULO DE CIFRADO DE DATOS          \n";
    cout << "Ejecutando prueba: Prueba Cifrado!\n";
}
