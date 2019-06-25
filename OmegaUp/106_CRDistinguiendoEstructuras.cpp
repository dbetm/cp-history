#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Distinguiendo-Estructuras#problems
using namespace std;

int main() {
    queue<int> cola;
    stack<int> pila;
    int opt, num;
    while(cin >> opt >> num) {
        if(opt == 1) {
            cola.push(num);
            pila.push(num);
        }
        else {
            int eCola = cola.front(), ePila = pila.top();
            cola.pop();
            pila.pop();
            if(eCola == ePila && eCola == num) continue;
            else if(eCola == num) {
                cout << "Cola" << endl;
                break;
            }
            else {
                cout << "Pila" << endl;
                break;
            }
        }
    }
    while(cin >> opt >> num) {

    }

    return 0;
}
