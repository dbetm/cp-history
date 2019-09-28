#include <bits/stdc++.h>
// Error de compilación
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
// #define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

int main() {
    int n, q;
    cin >> n >> q;
    int arr[n];
    int res[q] = {0};
    int queries[q];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int j = 0; j < q; j++) {
        cin >> queries[j];
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int sum = arr[i] + arr[j];
            for (int k = 0; k < q; k++) {
                if(queries[k] >= sum) res[k]++;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << res[i] << endl;
    }

	return 0;
}
