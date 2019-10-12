#include <bits/stdc++.h>
// Time complexity: O(n^2)
using namespace std;

int maxChainLength(vector<pair<int, int>> arr, int n);

int main() {
    int n;
    cout << "Type n: ";
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    // Sort, according the first (or, smaller) values in pairs.
    sort(arr.begin(), arr.end());
    cout << "Length of maximum size chain is " << maxChainLength(arr, n) << endl;
    return 0;
}

int maxChainLength(vector<pair<int, int>> arr, int n) {
    vector<int> mcl(n, 1); // se llena con unos ya que es el caso base

    // Hacemos bottom_up
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if(arr[i].first > arr[j].second and mcl[i] < mcl[j] + 1) {
                mcl[i] = mcl[j] + 1;
            }
        }
    }

    return *max_element(mcl.begin(), mcl.end());
}
