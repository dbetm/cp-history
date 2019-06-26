#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Acumulando-Banda#problems
using namespace std;

int main() {
    int num, k;
    int arr[6] = {0};
    for (int i = 1; i <= 5; i++) {
        cin >> num;
        arr[i] = num + arr[i-1];
    }
    cin >> k;
    cout << arr[k] << endl;
    return 0;
}
