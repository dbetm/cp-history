#include <bits/stdc++.h>
/* Explain what the code does: ((n & (n-1)) == 0)
Do AND operation bit a bit (bitwise) between the integer n and n-1. And then it
compares if the result is equal to 0.
Sometimes will be true. For example, for numbers that are powers of two.
*/
using namespace std;


int main(int argc, char const *argv[]) {
    int n;

    cin >> n;

    int res = (n & (n-1));

    cout << res << endl;
    cout << (res == 0) << endl;

    return 0;
}
