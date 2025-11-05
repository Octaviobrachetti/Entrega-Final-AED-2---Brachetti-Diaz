#include <iostream>
#include <string>
using namespace std;

void huffmanCompress(const string& texto);
void lzwCompress(const string& texto);

void menuCompresion() {
    int opcion;
    string texto;

    do {
        system("cls");
        cout << "         MODULO DE COMPRESION DE DATOS        \n";
        cout << "1. Comprimir texto con Huffman\n";
        cout << "2. Comprimir texto con Lempel-Ziv-Welch (LZW)\n";
        cout << "0. Volver al menu principal\n";
        cout << "----------------------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion != 0) {
            cout << "\nIngrese el texto a comprimir: ";
            getline(cin, texto);
        }

        switch (opcion) {
        case 1:
            cout << "\n--- Ejecutando algoritmo de Huffman ---\n";
            huffmanCompress(texto);
            break;

        case 2:
            cout << "\n--- Ejecutando algoritmo LZW ---\n";
            lzwCompress(texto);
            break;

        case 0:
            cout << "\nVolviendo al menu principal...\n";
            break;

        default:
            cout << "\nOpcion invalida. Intente nuevamente.\n";
        }

        system("pause");
    } while (opcion != 0);
}
