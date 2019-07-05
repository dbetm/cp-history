#include <bits/stdc++.h>
// Time complexity: O(n*k)
// Auxiliary space: O(k)
using namespace std;

int bc(int n, int k) {
    int C[k+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            C[j] = C[j] + C[j-1];
        }
    }
    return C[k];
}

int main() {
    int n, k;
    cout << "Type n: ";
    cin >> n;
    cout << "Type k: ";
    cin >> k;
    cout << "The binomial coefficient is: " << bc(n, k) << endl;
    return 0;
}
