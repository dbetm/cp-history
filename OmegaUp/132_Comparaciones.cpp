#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/comparaciones#problems
using namespace std;

int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) cin >> arr[i];
    int numIguales = 0, aux;
    for (int i = 0; i < 4; i++) {
        aux = 1;
        for (int j = i+1; j < 5; j++) {
            if(arr[i] == arr[j]) aux++;
        }
        numIguales = max(numIguales, aux);
    }

    if(numIguales == 5) cout << "Identicamente iguales" << endl;
    else if(numIguales == 4) cout << "Muy iguales" << endl;
    else if(numIguales == 3) cout << "Iguales" << endl;
    else if(numIguales == 2) cout << "Diferentes" << endl;
    else cout << "Muy diferentes" << endl;

    return 0;
}
