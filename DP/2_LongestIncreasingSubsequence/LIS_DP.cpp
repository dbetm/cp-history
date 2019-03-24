/* Dynamic Programming C++ implementation of LIS problem */
#include <bits/stdc++.h>
// Source: GFG.
// Time complexity: O(n^2)
using namespace std;

/* lis() returns the length of the longest increasing
    subsequence in arr[] of size n */
int lis(int arr[], int n);

int main(int argc, char const *argv[]) {
    int n;
    cout << "Type n: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Length of LIS is: " << lis(arr, n) << endl;
    return 0;
    return 0;
}
// ## Implementation

int lis(int arr[], int n) {
    int lis[n];
    lis[0] = 1; // trivial case
    // Compute optimized LIS values in bottom up manner
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1) lis[i] = lis[j] + 1;
        }
    }

    // Return maximum value in lis
    return *max_element(lis, lis+n);
}
