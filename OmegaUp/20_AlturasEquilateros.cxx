#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Alturas-equilateros#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    double res, lado;
    while(n--) {
        cin >> lado;
        // por el despeje en teorema de Pitágoras
        res = sqrt(pow(lado, 2) - pow(lado/2, 2));
        printf("%0.2lf\n", res);
    }
    return 0;
}
