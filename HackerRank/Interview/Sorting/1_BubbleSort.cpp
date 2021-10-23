#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/ctci-bubble-sort/problem
// Tag(s): sorting, implementation
using namespace std;

void countSwaps(vector<int> a) {
    int swaps = 0;
    int n = a.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                swaps++;
            }
        }
    }

    cout << "Array is sorted in " << swaps << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n-1] << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    countSwaps(a);

    return 0;
}
