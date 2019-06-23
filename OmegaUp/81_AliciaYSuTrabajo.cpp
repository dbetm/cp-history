#include <iostream>
// https://omegaup.com/arena/problem/Alicia-y-su-trabajo#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long int n, num, caja, pos = 0;
    cin >> n >> caja;

    while(n--) {
        cin >> num;
        if(num < caja) pos++;
    }

    cout << pos + 1 << endl;
    return 0;
}
