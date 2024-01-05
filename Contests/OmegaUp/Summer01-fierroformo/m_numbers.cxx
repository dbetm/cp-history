#include <iostream>
#include <cmath>

using namespace std;


int main() {
    int n;
    cin >> n;
    unsigned long long res[n];

    for (int i = 0; i <n; i++) {
        if (i == 0 || i == 1) {
            res[i] = 1;
        } else if (i == 2) {
            res[i] = 2;
        } else {
            res[i] = res[i-1] + res[i-2] + res[i-3];
        }
        cout << res[i] << " ";
    }
}
