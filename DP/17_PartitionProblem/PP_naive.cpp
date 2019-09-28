#include <bits/stdc++.h>
// Time complexity: O(n^3)
using namespace std;

bool partition(int arr[], int n);
bool findSubset(int arr[], int n, int sum);

int main() {
    int n;
    cout << "Type n: ";
    cin >> n;
    int arr[n];
    cout << "Type each element separate with a space: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Is it possible to separate into 2 subsets such that the sum is equal in both?" << endl;
    cout << (partition(arr, n) ? "YES" : "NO") << endl;

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
    if(sum == 0) return true;
    else if(n == 0 && sum != 0) return false;
    // ## Llamada recursiva ##
    // Ignorar el elemento
    if(arr[n-1] > sum) return findSubset(arr, n-1, sum);
    // Considerar el elemento para la suma
        // 0) Se excluye
        // 1) Se incluye
    return findSubset(arr, n-1, sum) or findSubset(arr, n-1, sum - arr[n-1]);
}
