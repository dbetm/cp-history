#include <bits/stdc++.h>
// Level: School
using namespace std;

int getNth(int n, int a, int d) {
    return (a + (n-1) * d);
}

int main(int argc, char const *argv[]) {
    int t; // número de casos
    cin >> t;
    int a, b, n;

    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        cin >> n;
        cout << getNth(n, a, b-a) << endl;
    }
    return 0;
}
