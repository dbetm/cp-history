#include <iostream>

using namespace std;

int64_t datos[161];
int cont = 0;

int64_t fn(int64_t n) {
    if(n <= 5) {
        return datos[cont++] = 1;
    }
    return datos[cont++] = fn(n-2)*5;
}

int main() {
    int64_t n;
    cin >> n;
    fn(n);
    for (int i = cont-1; i >= 0; i--) {
        cout << datos[i] << endl;
    }
    return 0;
}
