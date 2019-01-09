#include <bits/stdc++.h>

using namespace std;

int findPosition(int, int, int[]);

int main(int argc, char* argv[]) {
    int n, a;
    cin >> n;
    int A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        a = findPosition(i, n, A);
        cout << findPosition(a, n, A) << endl;
    }
    return 0;
}

int findPosition(int x, int n, int A[]) {
    int i;
    for (i = 0; i < n; i++) {
        if(A[i] == x) break;
    }
    return i+1;
}
