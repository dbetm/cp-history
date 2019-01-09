#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int L, min, x1;
    char aux;
    bool flag, r, d;

    while(true) {
        fflush(stdin);
        cin >> L;
        cin.get();
        if(L == 0) break;
        flag = false;
        r = false;
        d = false;
        min = L;
        for(unsigned int i = 0; i < L; i++){
            cin.get(aux);
            if(aux == 'R' && !r) {
                if(d) {
                    min = (min > i - x1)? i - x1: min;
                    r = true;
                    d = false;
                }
                else {
                    r = true;
                }
            }
            else if(aux == 'D' && !d) {
                if(r) {
                    min = (min > i - x1)? i - x1: min;
                    d = true;
                    r = false;
                }
                else {
                    d = true;
                }
            }
            else if(aux == 'Z') {
                flag = true;
                for (unsigned int j = i; j < L; j++) {
                    cin.get(aux);
                }
                break;
            }

            if(aux != '.') {
                x1 = i;
            }
        }
        if(flag) cout << "0" << endl;
        else cout << min << endl;
    }

    return 0;
}
