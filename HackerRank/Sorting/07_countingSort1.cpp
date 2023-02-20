#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/countingsort1/problem
// Tag(s): sorting, implementation

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> results(100, 0);

    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        results[x]++;
    }

    for(auto x : results) {
        cout << x << " ";
    }
    cout << endl;


    return 0;
}