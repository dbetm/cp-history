#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/closest-numbers/problem
// Tag(s): implementation
using namespace std;


int main() {
    int n;
    int minDiff = INT_MAX;
    cin >> n;
    vector<int> arr(n);
    vector<int> results;

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 1; i < n; ++i) {
        int diff = abs(arr[i] - arr[i-1]);

        if(diff < minDiff) {
            results.clear();
            results.push_back(arr[i-1]);
            results.push_back(arr[i]);

            minDiff = diff;
        }
        else if(diff == minDiff) {
            results.push_back(arr[i-1]);
            results.push_back(arr[i]);
        }
    }

    for(auto x : results) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

