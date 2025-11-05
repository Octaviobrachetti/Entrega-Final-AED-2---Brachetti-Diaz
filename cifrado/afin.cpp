#include <iostream>
#include <string>
using namespace std;

// Función para hallar el inverso modular (para descifrar)
int inversoModular(int a, int m) {
    a %= m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

void cifradoAfin(const string& texto) {
    int a, b;
    cout << "Ingrese clave a (debe ser coprima con 26): ";
    cin >> a;
    cout << "Ingrese clave b: ";
    cin >> b;
    cin.ignore();

    string resultado = texto;
    for (char& c : resultado) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (a * (c - base) + b) % 26 + base;
        }
    }

    cout << "\nTexto cifrado: " << resultado << endl;
}

void descifradoAfin(const string& texto) {
    int a, b;
    cout << "Ingrese clave a (la misma usada para cifrar): ";
    cin >> a;
    cout << "Ingrese clave b (la misma usada para cifrar): ";
    cin >> b;
    cin.ignore();

    int invA = inversoModular(a, 26);
    if (invA == -1) {
        cout << "Error: no existe inverso modular para a=" << a << endl;
        return;
    }

    string resultado = texto;
    for (char& c : resultado) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (invA * ((c - base - b + 26))) % 26 + base;
        }
    }

    cout << "\nTexto descifrado: " << resultado << endl;
}
