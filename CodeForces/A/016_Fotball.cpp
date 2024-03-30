#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string input;
    int cont = 0, cont2 = 0;
    bool flag = false;
    cin >> input;
    if(input.size() > 7) {
        for (int i = 0; i < (int)input.size(); i++) {
            if(input[i] == '1') {
                cont2 = 0;
                cont++;
                if(cont == 7) {
                    flag = true;
                    break;
                }
            }
            else {
                cont = 0;
                cont2++;
                if(cont2 == 7) {
                    flag = true;
                    break;
                }
            }
        }
    }

    cout << ((flag) ? "YES" : "NO") << endl;

    return 0;
}
