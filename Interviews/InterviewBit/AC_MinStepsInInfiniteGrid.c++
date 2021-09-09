#include <bits/stdc++.h>
// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
// Tag(s): Math, geometry, implementation
using namespace std;

int coverPoints(int* A, int n1, int* B, int n2) {
    int ans = 0;

    for (int i = 0; i < (n1-1); ++i) {
        ans += max(abs(A[i]-A[i+1]), abs(B[i]-B[i+1]));
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    int B[n];

    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];

    cout << coverPoints(&A[0], n, &B[0], n) << endl;

    return 0;
}
