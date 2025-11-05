#include <iostream>
#include <string>
using namespace std;

void cifradoCesar(const string& texto) {
    int clave;
    cout << "Ingrese clave numerica (desplazamiento): ";
    cin >> clave;
    cin.ignore();

    string resultado = texto;
    for (char& c : resultado) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + clave) % 26 + base;
        }
    }

    cout << "\nTexto cifrado: " << resultado << endl;
}

void descifradoCesar(const string& texto) {
    int clave;
    cout << "Ingrese la misma clave numerica usada para cifrar: ";
    cin >> clave;
    cin.ignore();

    string resultado = texto;
    for (char& c : resultado) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base - clave + 26) % 26 + base;
        }
    }

    cout << "\nTexto descifrado: " << resultado << endl;
}
