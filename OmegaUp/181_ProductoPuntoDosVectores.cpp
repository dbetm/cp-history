#include <iostream>
// https://omegaup.com/arena/problem/Producto-punto-de-dos-vectores/#problems
// Tag(s): Implementation
using namespace std;

int main() {
    int n, answer = 0, aux;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> aux;
        answer += aux * arr[i];
    }

    cout << answer << endl;

    return 0;
}
