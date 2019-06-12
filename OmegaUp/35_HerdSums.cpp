#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/herdsums#problems
using namespace std;

int main() {
    int64_t n, cont = 0;
    cin >> n;
    for (int64_t i = (n/2)+1; i >= 1; i--) {
        int64_t sum = 0;
        int64_t j = i;
        while(sum < n && j > 0) {
            sum += j;
            j--;
        }
        if(sum == n) cont++;
    }
    cout << cont+1 << endl;
    return 0;
}
