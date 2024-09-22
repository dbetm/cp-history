#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/crush/problem
// Tag(s): Lazy propagation, arrays
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

long int arr[10000000]; // 10^7

int main() {
    fastIO
    int n, m, a, b;
    cin >> n >> m;

    int64_t k;
    int64_t aux, hip;
    while(m--) {
        cin >> a >> b >> k;
        a -= 1;
        b -= 1;
        arr[a] += k;
        if((b+1) < n) arr[b+1] -= k;
    }

    aux = arr[0];
    hip = arr[0];
    for (int i = 1; i <= n; i++) {
        aux += arr[i];
        if(aux > hip) {
            hip = aux;
        }
    }

    cout << hip << endl;

	return 0;
}
