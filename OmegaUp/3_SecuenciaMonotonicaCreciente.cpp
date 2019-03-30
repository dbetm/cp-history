#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Subsecmoncre#problems
using namespace std;

int lis(int arr[], int n) {
    int lis[n];
    lis[0] = 1;

    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1) lis[i] = lis[j] + 1;
        }
    }

    return *max_element(lis, lis+n);
}

int main(int argc, char const *argv[]) {
    // Faster I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << lis(arr, n) << endl;
    return 0;
}
