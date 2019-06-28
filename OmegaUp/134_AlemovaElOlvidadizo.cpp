#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/el-olvidadizo#problems
using namespace std;

int main() {
    char c;
    int cont = 0;
    while(true) {
        cin >> c;
        if(c == '.') break;
        else if(c == ' ') continue;
        else cont++;
    }
    cout << cont << endl;
    return 0;
}
