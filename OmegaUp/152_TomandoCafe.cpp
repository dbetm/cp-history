#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/DOCENTES-SIN-DORMIR-ASINUS#problems
using namespace std;

int main() {
    double horas;
    cin >> horas;
    if(horas >= 8) cout << "NO CAFE" << endl;
    else {
        cout << (8-horas)*1.5 << endl;
    }
    return 0;
}
