#include <iostream>
#include <string>
#include <cmath>
// Parcialmente correcta
using namespace std;

int cont = 0;

void contarOps(int n) {
    do {
        if(n == 1) break;
        cont++;
        if(n & 1) n--;
        else n /= 2;
    } while(n > 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string bin;
    cin >> n;
    cin >> bin;
    n = 0;
    for (int i = bin.size()-1, j = 0; i >= 0; i--, j++) {
        if(bin[i] == '1') n += pow(2, j);
    }

    cout << ceil(log2(n))<< endl;
    return 0;
}
