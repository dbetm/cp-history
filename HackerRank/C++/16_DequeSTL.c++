#include <bits/stdc++.h>
//
// Tag(s):
// Tips:
    // Revisar artículo: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/#disqus_thread - Método 3.
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
const int LIM = 10001;

void compute(int arr[LIM], int n, int k);

int main() {
    fastIO
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        compute(arr, n, k);
    }
	return 0;
}

void compute(int arr[LIM], int n, int k) {
    deque <int> dq, aux;

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        if((i+1) % k == 0) {
            watch(arr[i])
            dq.push_front(arr[i]);
        }
    }

    for (auto it = dq.begin(); it != dq.end(); it++) {
        cout << arr[*it] << " ";
    }
    cout << endl;
}
