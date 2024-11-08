#include <iostream>
// https://leetcode.com/problems/climbing-stairs/
// Tag(s): DP

using namespace std;

int climbStairs(int n) {
    int a = 1;
    int b = 1;
    int ans = 1;

    for (int i = 2; i <= n; ++i) {
        ans = (a + b);
        b = a;
        a = ans;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << climbStairs(n) << endl;

    return 0;
}
