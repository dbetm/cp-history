#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string num;
    cin >> num;
    int j = 0;
    int suma = 0;
    int numDec;
    for (int i = num.size() - 1; i >= 0; i--, j++) {
        if((int)num[i] > 47 && (int)num[i] < 58) {
            suma += pow(-1, j) * ( ((int)num[i]) - 48);
        }
        else { // se trata de una letra
            switch (num[i]) {
                case 'A': // 10
                    numDec = 10;
                break;
                case 'B': // 11
                    numDec = 11;
                break;
                case 'C': // 12
                    numDec = 12;
                break;
                case 'D': // 13
                    numDec = 13;
                break;
                case 'E': // 14
                    numDec = 14;
                break;
                default: // 15
                    numDec = 15;
                break;
            }
            suma += pow(-1, j) * numDec;
        }
    }
    if(suma % 17 == 0) cout << "Es divisible" << "\n";
    else cout << "No es divisible" << "\n";

    return 0;
}
