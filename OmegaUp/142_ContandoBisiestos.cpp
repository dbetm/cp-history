#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Contando-anos-bisiestos#problems
using namespace std;

int main() {
    int cont = 0, year;

    for (int i = 0; i < 10; i++) {
        cin >> year;
        if(year % 4 == 0 && !(year % 100 == 0)) cont++;
        else if(year % 100 == 0 && year % 400 == 0) cont++;
    }

    cout << cont << endl;
    return 0;
}
