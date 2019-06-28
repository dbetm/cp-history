#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/bisiesto#problems
using namespace std;

int main() {
    int n, year;
    cin >> n;
    while(n--) {
        cin >> year;
        if(year % 4 == 0 && !(year % 100 == 0)) cout << "S" << endl;
        else if(year % 100 == 0 && year % 400 == 0) cout << "S" << endl;
        else cout << "N" << endl;
    }
    return 0;
}
