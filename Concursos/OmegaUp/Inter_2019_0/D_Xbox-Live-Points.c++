#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Xbox-Live-Points#problems
using namespace std;
// Kadane's algorithm
int main(int argc, char const *argv[]) {
    int n, punto;
    cin >> n;
    long int maxAbs = 0;
    long int maxHastaI = 0;

    for (int i = 0; i < n; i++) {
        cin >> punto;
        maxHastaI += punto;
        if(maxHastaI < 0) maxHastaI = 0;
        else if(maxHastaI > maxAbs) maxAbs = maxHastaI;
    }
    cout << maxAbs << endl;
    return 0;
}
