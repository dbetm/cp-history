#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    unsigned int n, p, fromFront = 0, fromBack = 0;
    cin >> n;
    cin >> p;
    if(p % 2 == 0) {
        fromFront = p / 2;
    }
    else {
        fromFront = (p - 1) / 2;
    }

    if(n % 2 == 0) {
        fromBack = (n / 2) - fromFront;
    }
    else {
        fromBack = ((n - 1) / 2) - fromFront;
    }
    if(fromBack <= fromFront) cout << fromBack << endl;
    else cout << fromFront << endl;

    return 0;
}
