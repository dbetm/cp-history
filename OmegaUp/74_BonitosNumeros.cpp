#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Bonitos-Numeros#problems
using namespace std;

typedef long long int lli;

int main() {
    lli n;
    string num;

    cin >> n;
    while(n--) {
        cin >> num;
        if(num.size() & 1) cout << "NO" << endl;
        else cout << "SI" << endl;
    }
    return 0;
}
