#include <bits/stdc++.h>
// Se enviaron versiones anteriores no aceptadas
// Se cree que está versión sería aceptada
using namespace std;

int main(int argc, char const *argv[]) {
    int n, x, y;
    bool inconsistencia = false;
    cin >> n;
    vector<vector<int>> m;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if(x == 0 || y == 0 || y < x) inconsistencia = true;
        else if(!inconsistencia) {
            vector<int> aux;
            for (int j = x; j <= y; j++) aux.push_back(j);
            m.push_back(aux);
        }
    }

    if(inconsistencia) cout << "-1" << endl;
    else {
        int maxIndex = 0;
        int max = m[0].size();
        for (int i = 1; i < n; i++) {
            if(max < (int)m[i].size()) {
                bool ans = true;
                for (int j = 0; j < (int)m[i].size(); j++) {
                    if(i == j) continue;
                    int o = m[i][j];
                    if(find(m[o].begin(), m[o].end(), o) == m[o].end()) {
                        ans = false;
                        break;
                    }
                }
                if(ans) {
                    max = m[i].size();
                    maxIndex = i;
                }
            }
        }
        cout << m[maxIndex].size() << endl;
    }
    return 0;
}
