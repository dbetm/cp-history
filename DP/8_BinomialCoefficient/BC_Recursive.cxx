#include <bits/stdc++.h>

using namespace std;

int bc(int n, int k) {
    if(k == n || k == 0) return 1;
    return bc(n-1, k-1) + bc(n-1, k);
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
