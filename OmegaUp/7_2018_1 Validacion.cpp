#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/2018_1_Validacion#problems
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;

    while(cin >> a >> b) {
        if(a == b || (a > 1000 && b > 1000) || ((a%2 == 0 && b%2 == 1) || (a%2 == 1 && b%2 == 0))) {
            cout << "YA" << endl;
            break;
        }
        cout << "TODAVIA NO" << endl;
    }
    return 0;
}
