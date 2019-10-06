#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d, ans = 0;
    // i < j < k
    cin >> n >> d;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    for (int k = n-1; k >= 0; k--) {
        for (int j = k-1; j >= 0; j--) {
            if(arr[k]-arr[j] == d) {
                for (int i = j-1; i >= 0; i--) {
                    if(arr[j]-arr[i] == d) ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
