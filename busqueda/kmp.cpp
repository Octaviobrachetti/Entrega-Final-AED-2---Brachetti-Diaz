#include <vector>
#include <string>
using namespace std;

vector<int> construirLPS(const string& patron) {
    int m = patron.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (patron[i] == patron[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmpBuscar(const string& texto, const string& patron) {
    vector<int> posiciones;
    int n = texto.length();
    int m = patron.length();

    vector<int> lps = construirLPS(patron);
    int i = 0, j = 0;

    while (i < n) {
        if (patron[j] == texto[i]) {
            i++; j++;
        }
        if (j == m) {
            posiciones.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n && patron[j] != texto[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return posiciones;
}
