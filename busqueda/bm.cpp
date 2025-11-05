#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> boyerMooreBuscar(const string& texto, const string& patron) {
    vector<int> posiciones;
    int n = texto.length();
    int m = patron.length();

    if (m == 0 || n == 0 || m > n) return posiciones;

    unordered_map<char, int> badChar;
    for (int i = 0; i < m; i++)
        badChar[patron[i]] = i;

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && patron[j] == texto[s + j])
            j--;
        if (j < 0) {
            posiciones.push_back(s);
            s += (s + m < n) ? m - badChar[texto[s + m]] : 1;
        }
        else {
            s += max(1, j - badChar[texto[s + j]]);
        }
    }
    return posiciones;
}
