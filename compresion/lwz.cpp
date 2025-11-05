#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void lzwCompress(const string& texto) {
    if (texto.empty()) {
        cout << "No se ingreso texto para comprimir.\n";
        return;
    }

    map<string, int> dic;
    for (int i = 0; i < 256; i++)
        dic[string(1, i)] = i;

    string p = "";
    vector<int> salida;
    int codigo = 256;

    for (char c : texto) {
        string pc = p + c;
        if (dic.count(pc))
            p = pc;
        else {
            salida.push_back(dic[p]);
            dic[pc] = codigo++;
            p = string(1, c);
        }
    }

    if (!p.empty())
        salida.push_back(dic[p]);

    cout << "\n=== COMPRESION LZW ===\n";
    cout << "Texto original: " << texto << endl;
    cout << "Codigos LZW: ";
    for (int x : salida)
        cout << x << " ";
    cout << endl;

    cout << "Tamano original: " << texto.size() * 8 << " bits\n";
    cout << "Tamano comprimido (estimado): " << salida.size() * 12 << " bits\n";
}
