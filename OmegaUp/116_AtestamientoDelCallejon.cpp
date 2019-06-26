#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Atestamiento-del-Callejon#problems
using namespace std;

int main() {
    int n, id, solicitado, cont = 0;
    stack<int> autos;
    cin >> n;
    while(n--) {
        cin >> id;
        autos.push(id);
    }
    cin >> solicitado;
    while(!autos.empty()) {
        cont++;
        if(autos.top() == solicitado) {
            cout << cont << endl;
            break;
        }
        autos.pop();
    }
    if(autos.empty()) cout << "No existe el auto" << endl;
    return 0;
}
