#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Contar-Valor#problems
using namespace std;
#define MAX 1000000
int a[MAX];

int main() {
    int n, num;
    cin >> n;
    while(n--) {
        cin >> num;
        a[num]++;
    }
    cin >> num;
    cout << a[num] << endl;
    return 0;
}
