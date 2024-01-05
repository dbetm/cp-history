#include <bits/stdc++.h>

using namespace std;

int arr[] = {2, 3, 5, 7};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int tam = sizeof(arr) / sizeof(int);
    while(cin >> n) {
        for (int i = 0; i < tam; i++) {
            if(n % arr[i] == 0) cout << arr[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
