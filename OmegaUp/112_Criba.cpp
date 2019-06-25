#include <iostream>
#include <cmath>
// un 0 indica que es primo, un 1 que no lo es
using namespace std;
#define tam 1000001

bool A[tam];

void imprimirCriba();
void imprimirNumerosPrimos();
void generarCriba();

void fastscan(int &number) {
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-') {
        // number is negative
        negative = true;
        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, num;
    // el o y el 1 no son primos
    A[0] = 1;
    A[1] = 1;
    generarCriba();
    fastscan(k);
    while(k--) {
        fastscan(num);
        if(A[num]) cout << "NO" << endl;
        else cout << "SI" << endl;
    }

    return 0;
}

void imprimirCriba() {
    for (int i = 0; i < tam; i++) {
        cout << A[i] << " ";
        if((i+1) % 10 == 0) cout << endl;
    }
}

void imprimirNumerosPrimos() {
    int j = 1;
    for (int i = 0; i < tam; i++) {
        if(A[i] == 0) {
            cout << i << " ";
            if(j % 4 == 0) cout << endl;
            j++;
        }
    }
}

void generarCriba() {
    for (int i = 2; i < sqrt(tam); i++) {
        if(A[i] == 0) {
            for (int j = i; j <= (tam / i); j++) {
                A[i*j] = 1;
            }
        }
    }
}
