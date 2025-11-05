#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

struct Nodo {
    char c;
    int f;
    Nodo* izq, * der;
    Nodo(char c, int f) : c(c), f(f), izq(nullptr), der(nullptr) {}
};

struct cmp {
    bool operator()(Nodo* a, Nodo* b) {
        return a->f > b->f;
    }
};

void generarCodigos(Nodo* raiz, string codigo, unordered_map<char, string>& tabla) {
    if (!raiz) return;
    if (!raiz->izq && !raiz->der)
        tabla[raiz->c] = codigo;
    generarCodigos(raiz->izq, codigo + "0", tabla);
    generarCodigos(raiz->der, codigo + "1", tabla);
}

void huffmanCompress(const string& texto) {
    if (texto.empty()) {
        cout << "No se ingreso texto para comprimir.\n";
        return;
    }

    // Calcula frecuencias de los caracteres
    unordered_map<char, int> freq;
    for (char c : texto)
        freq[c]++;

    // Crea cola de prioridad
    priority_queue<Nodo*, vector<Nodo*>, cmp> pq;
    for (auto& p : freq)
        pq.push(new Nodo(p.first, p.second));

    // Construyee el arbol
    while (pq.size() > 1) {
        Nodo* izq = pq.top(); pq.pop();
        Nodo* der = pq.top(); pq.pop();
        Nodo* nuevo = new Nodo('\0', izq->f + der->f);
        nuevo->izq = izq;
        nuevo->der = der;
        pq.push(nuevo);
    }

    // Generar tabla de codigos
    unordered_map<char, string> tabla;
    generarCodigos(pq.top(), "", tabla);

    // Mostrar resultados
    cout << "\n=== COMPRESION HUFFMAN ===\n";
    cout << "Texto original: " << texto << endl;
    cout << "Codigos Huffman:\n";
    for (auto& t : tabla)
        cout << t.first << " : " << t.second << endl;
    // Generar y mostrar el texto comprimido completo
    string comprimido = "";
    for (char c : texto)
        comprimido += tabla[c];

    cout << "\nTexto comprimido (bits): " << comprimido << "\n";
    cout << "Tamano original: " << texto.size() * 8 << " bits\n";
    cout << "Tamano comprimido: " << comprimido.size() << " bits\n";

    int bitsOriginal = texto.size() * 8;
    int bitsComprimido = 0;
    for (char c : texto)
        bitsComprimido += tabla[c].size();

    cout << "\nTamano original: " << bitsOriginal << " bits\n";
    cout << "Tamano comprimido (estimado): " << bitsComprimido << " bits\n";
}
