#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    bool ya;
    cin >> n;
    string num = to_string(n);
    int d = num.size();
    string aux = "", ni;
    long int pos = 0;

    for (int i = 1; i <= n; i++) {
        ni = to_string(i);
        aux += ni;
        pos += ni.size();
        if(aux.size() % d == 0) {
            ya = true;
            cout << "Comparando" << endl;
            for (unsigned int j = 0; j < aux.size(); j++) {
                cout << aux[j] << " " << num[j] << endl;
                if(aux[j] != num[j]) {
                    ya = false;
                    break;
                }
            }
            if(ya) {
                cout << pos - d << endl;
                break;
            }
        }
    }

    return 0;
}
