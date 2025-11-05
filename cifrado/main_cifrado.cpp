#include <iostream>
#include <string>
using namespace std;

// ?? Prototipos
void cifradoCesar(const string& texto);
void descifradoCesar(const string& texto);

void cifradoAfin(const string& texto);
void descifradoAfin(const string& texto);

void cifradoVigenere(const string& texto);
void descifradoVigenere(const string& texto);

void menuCifrado() {
    int opcion;
    string texto;

    do {
        system("cls");
        cout << "MODULO DE CIFRADO POR SUSTITUCION\n";
        cout << "1. Cifrar con Cesar\n";
        cout << "2. Descifrar con Cesar\n";
        cout << "3. Cifrar con Afin\n";
        cout << "4. Descifrar con Afin\n";
        cout << "5. Cifrar con Vigenere\n";
        cout << "6. Descifrar con Vigenere\n";
        cout << "0. Volver al menu principal\n";
        cout << "----------------------------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion != 0) {
            cout << "\nIngrese el texto: ";
            getline(cin, texto);
        }

        switch (opcion) {
        case 1: cifradoCesar(texto); break;
        case 2: descifradoCesar(texto); break;
        case 3: cifradoAfin(texto); break;
        case 4: descifradoAfin(texto); break;
        case 5: cifradoVigenere(texto); break;
        case 6: descifradoVigenere(texto); break;
        case 0: cout << "\nVolviendo al menu principal...\n"; break;
        default: cout << "\nOpcion invalida.\n"; break;
        }

        system("pause");
    } while (opcion != 0);
}
