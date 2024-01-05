#include <bits/stdc++.h>
// Time complexity: O(n*m)
// Space complexity: O(sum*n)
using namespace std;
#define MAX 1000
#define watch(x) cout << (#x) << " is " << (x) << endl;
int tabla[MAX][MAX];

bool partition(int arr[], int n);
bool findSubset(int arr[], int n, int sum);
void debug();

int main() {
    int n;
    cout << "Type n: ";
    cin >> n;
    int arr[n];
    cout << "Type each element separate with a space: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(tabla, -1, sizeof(tabla));
    cout << "Is it possible to separate into 2 subsets such that the sum is equal in both?" << endl;
    //debug();
    int ans = partition(arr, n);
    //watch(ans)
    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}

bool partition(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    if(sum & 1) return false;

    return findSubset(arr, n, sum / 2);
}

bool findSubset(int arr[], int n, int sum) {
    // Casos base
    if(sum == 0) {
        return (tabla[sum][n] = true);
    }
    else if(n == 0 && sum != 0) {
        return (tabla[sum][n] = false);
    }
    // Buscamos la respuesta en memoria
    if(tabla[sum][n] != -1) {
        return tabla[sum][n];
    }

    // ## Llamada recursiva ##
    // Ignorar el elemento
    if(arr[n-1] > sum) {
        return (tabla[sum][n] = findSubset(arr, n-1, sum));
    }
    // Considerar el elemento para la suma
        // 0) Se excluye
        // 1) Se incluye
    return (tabla[sum][n] = (findSubset(arr, n-1, sum) or findSubset(arr, n-1, sum - arr[n-1])));
}

void debug() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cout << tabla[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------" << endl;
}
