#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/taum-and-bday/problem
using namespace std;

int64_t getMinimumPrice(int64_t b, int64_t w, int64_t bc, int64_t wc, int64_t z) {
    int64_t ans = 0;
    if(bc > z && wc > z)
        if(bc < wc) ans = (b + w)*bc + (w*z);
        else if(wc < bc) ans = (b + w)*wc + (b*z);
        else ans = (b + w)*wc + (b*z);
    else if((bc == wc) || (z >= bc && z >= wc)) ans = ((b*bc) + (w*wc));
    else if(bc > z) ans = (b + w)*wc + (b*z);
    else ans = (b + w)*bc + (w*z);
    if(ans > ((b*bc) + (w*wc))) ans = (b*bc) + (w*wc);
    return ans;
}

int main() {
    int t;
    int64_t  b, w, bc, wc, z;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> b >> w;
        cin >> bc >> wc >> z;
        cout << getMinimumPrice(b, w, bc, wc, z) << endl;
    }
    return 0;
}
