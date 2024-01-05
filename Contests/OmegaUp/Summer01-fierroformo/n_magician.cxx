#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int arr[n];
    int ii[n];

    int aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        arr[i] = aux;
        ii[i] = aux;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < sizeof(arr)/sizeof(arr[0]); j++) {
            if (j == 0) {
                ii[j] = (arr[n - 1] + arr[j + 1]) % 100;
            } else if (j < n - 1) {
                ii[j] = (arr[j - 1] + arr[j + 1]) % 100;
            } else {
                ii[j] = (arr[j - 1] + arr[0]) % 100;
            }
        }

        std::copy(ii, ii + n, arr);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
