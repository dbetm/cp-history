#include <bits/stdc++.h>
using namespace std;
// https://omegaup.com/arena/problem/El-Caracol#problems
int main(int argc, char const *argv[]) {
    int64_t p, s, r;
    cin >> p >> s >> r;
    int64_t pointer = 0;
    int dias = 0;

    do {
        dias++;
        if((pointer + s) >= p) break;
        pointer += (s-r);
        //cout << pointer << endl;
    } while(pointer < p);

    cout << dias << endl;
    return 0;
}
