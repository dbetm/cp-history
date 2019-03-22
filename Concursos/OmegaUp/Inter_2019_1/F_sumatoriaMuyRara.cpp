#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Sumatoria-de-sumatorias#problems
using namespace std;

int main(int argc, char const *argv[]) {
    unsigned int x, y;
    cin >> x >> y;
    unsigned int m = (x*(x+1))/2;
    unsigned int n = (y*(y+1))/2;

    unsigned int sumN = (n*(n+1))/2;

    m--;
    unsigned int sumM = (m*(m+1))/2;

    cout << sumN - sumM << endl;
    return 0;
}
