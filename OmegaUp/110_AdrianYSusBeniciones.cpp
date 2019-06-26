#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q, pos, ele;
    cin >> n >> q;
    int arr[n] = {0};
    while(q--) {
        cin >> pos >> ele;
        arr[pos] = ele;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
