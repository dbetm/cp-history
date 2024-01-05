#include <bits/stdc++.h>
// Time complexity: O(n*m)
// Space complexity: O(sum*n)
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;

bool partition(int arr[], int n);

int main() {
    int n;
    cout << "Type n: ";
    cin >> n;
    int arr[n];
    cout << "Type each element separate with a space: " << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Is it possible to separate into 2 subsets such that the sum is equal in both?" << endl;
    int ans = partition(arr, n);
    //watch(ans)
    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}

bool partition(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    if(sum & 1) return false;
    //watch(sum)
    sum /= 2;
    bool tabla[sum + 1][n+1];

    // Casos base
    // 1) Tener 0 elementos en el conjunto y la suma mayor a 0
    for (int i = 0; i <= sum; i++) tabla[i][0] = false;
    // 2) Tener que sumar 0, con n elementos
    for (int j = 0; j <= n; j++) tabla[0][j] = true;

    for (int i = 1; i <= sum; i++) {
        for (int j = 1; j <= n; j++) {
            tabla[i][j] = tabla[i][j-1];
            if(arr[j-1] <= i) {
                // Caso 1
                bool incluir = tabla[i-arr[j-1]][j-1];
                // Caso 2
                bool excluir = tabla[i][j-1];
                tabla[i][j] = incluir or excluir;
            }
        }
    }

    // ### Printing matrix ###
    // for (int i = 0; i <= sum; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << tabla[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    return tabla[sum][n];
}
