/* Dynamic Programming C++ implementation of MSIS problem */
#include <bits/stdc++.h>
// Source: GFG.
// Time complexity: O(n^2)
using namespace std;

// find the sum of maximum sum subsequence of the given array
// such that the integers in the subsequence are sorted in increasing order.
int maxSis(int arr[], int n);

int main(int argc, char const *argv[]) {
    int n;
    cout << "Type n: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Sum of maximum sum increasing subsequence is: " << maxSis(arr, n) << endl;
    return 0;
}

// ## Implementation
int maxSis(int arr[], int n) {
    int msis[n];

    for (size_t i = 0; i < n; i++) msis[i] = arr[i];

    // Construimos la solución de forma ascendente, tabulado
    for (size_t i = 1; i < n; i++) {
        for (size_t j = 0; j < i; j++) {
            if(arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
                msis[i] = msis[j] + arr[i];
            }
        }
    }

    return *max_element(msis, msis+n);
}
