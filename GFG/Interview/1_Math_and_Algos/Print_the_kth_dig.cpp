#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/print-the-kth-digit/0/
// Tag(s): Implementation, math
using namespace std;

void print(int64_t a, int64_t b, int k);

int main() {
    int t, k;
    int64_t a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b >> k;
        print(a, b, k);
    }
    return 0;
}

void print(int64_t a, int64_t b, int k) {
    int64_t res = pow(a, b);
    string strRes = to_string(res);
    cout << strRes[strRes.size() - k] << endl;
}
