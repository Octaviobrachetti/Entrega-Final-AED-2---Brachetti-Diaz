#include <iostream>
#include <string>
using namespace std;

void cifradoVigenere(const string& texto) {
    string clave;
    cout << "Ingrese palabra clave: ";
    cin >> clave;
    cin.ignore();

    string resultado = texto;
    int j = 0;
    for (int i = 0; i < texto.size(); i++) {
        char c = texto[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = tolower(clave[j % clave.size()]) - 'a';
            resultado[i] = (tolower(c) - 'a' + k) % 26 + base;
            j++;
        }
    }

    cout << "\nTexto cifrado: " << resultado << endl;
}

void descifradoVigenere(const string& texto) {
    string clave;
    cout << "Ingrese la palabra clave a cifrar: ";
    cin >> clave;
    cin.ignore();

    string resultado = texto;
    int j = 0;
    for (int i = 0; i < texto.size(); i++) {
        char c = texto[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = tolower(clave[j % clave.size()]) - 'a';
            resultado[i] = (tolower(c) - 'a' - k + 26) % 26 + base;
            j++;
        }
    }

    cout << "\nTexto descifrado: " << resultado << endl;
}
