#include <iostream>
#include <vector>
#include <string>
#include "fb.cpp"
#include "kmp.cpp"
#include "bm.cpp"

using namespace std;

void menuBusqueda() {
    int opcion;
    string texto, patron;
    vector<int> posiciones;

    do {
        system("cls");
        cout << "        MODULO DE BUSQUEDA DE TEXTO       \n";
        cout << "1. Fuerza Bruta (FB)\n";
        cout << "2. Knuth-Morris-Pratt (KMP)\n";
        cout << "3. Boyer-Moore (BM)\n";
        cout << "0. Volver al menu principal\n";
        cout << " Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion != 0) {
            cout << "\n Ingrese el texto: ";
            getline(cin, texto);
            cout << " Ingrese el patron a buscar: ";
            getline(cin, patron);
        }

        switch (opcion) {
        case 1:
            posiciones = fuerzaBruta(texto, patron);
            break;
        case 2:
            posiciones = kmpBuscar(texto, patron);
            break;
        case 3:
            posiciones = boyerMooreBuscar(texto, patron);
            break;
        case 0:
            cout << "\n Volviendo al menu principal...\n";
            break;
        default:
            cout << "\n Opcion invalida.\n";
            continue;
        }

        if (opcion >= 1 && opcion <= 3) {
            if (posiciones.empty()) {
                cout << "\n No se encontro el patron.\n";
            }
            else {
                cout << "\n Patron encontrado en posiciones: ";
                for (int pos : posiciones)
                    cout << pos << " ";
                cout << "\n";
            }
        }

        system("pause");
    } while (opcion != 0);
}
