#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Distancia-minima#problems
using namespace std;

int main() {
    int n, k, kilometro, taller, res;
    cin >> n >> k;
    cin >> kilometro;
    taller = abs(k-kilometro);
    res = kilometro;
    n--;
    while(n--) {
        cin >> kilometro;
        int diff = abs(k-kilometro);
        if(diff < taller) {
            taller = diff;
            res = kilometro;
        }
    }
    cout << res << endl;
    return 0;
}
