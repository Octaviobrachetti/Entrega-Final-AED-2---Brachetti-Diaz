#include <vector>
#include <string>
using namespace std;

vector<int> fuerzaBruta(const string& texto, const string& patron) {
    vector<int> posiciones;
    int n = texto.length();
    int m = patron.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (texto[i + j] != patron[j])
                break;
        }
        if (j == m)
            posiciones.push_back(i);
    }
    return posiciones;
}
