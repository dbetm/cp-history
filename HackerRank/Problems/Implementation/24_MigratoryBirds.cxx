#include <bits/stdc++.h>

using namespace std;

int migratoryBirds(int n, vector <int> ar) {
    int aux[2][5];
    unsigned int cont, id = 1;
    for(unsigned int i = 0; i < 5; i++) {
        cont = 0;
        for(unsigned int j = 0; j < ar.size(); j++) {
            if(i + 1 == ar[j]) {
                cont++;
            }
        }
        aux[0][i] = i+1;
        aux[1][i] = cont;
    }
    cont = aux[1][0];
    for(unsigned int i = 0; i < 5; i++) {
        if(aux[1][i] >= cont) {
            int idAux = id;
            id = aux[0][i];
            if(aux[1][i] == cont) {
                id = idAux;
            }
            cont = aux[1][i];
        }
    }


    return id;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}
