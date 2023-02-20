#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/countingsort2/problem
// tag(s): sorting, implementations

using namespace std;


int main() {
    int n, x;
    cin >> n;
    int results[100] = {0};

    for(int i = 0; i < n; ++i) {
        cin >> x;
        results[x]++;
    }

    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < results[i]; ++j) {
            cout << i << " ";
        }
    }
    cout << endl;


    return 0;
}