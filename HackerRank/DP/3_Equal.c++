#include <bits/stdc++.h>

using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

int getMinOps(vector<int> &chocolates, int n);

int main() {
    fastIO();
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> chocolates(n);
        for (int i = 0; i < n; i++) cin >> chocolates[i];
        cout << getMinOps(chocolates, n) << endl;
    }
    return 0;
}

int getMinOps(vector<int> &chocolates, int n) {
    int totalOps = 0;
    int minimo = chocolates[0], maximo = chocolates[0];
    int cantidades[3] = {1, 2, 5};

    for (int i = 1; i < n; i++) {
        if(chocolates[i] > maximo) maximo = chocolates[i];
        else if(chocolates[i] < minimo) minimo = chocolates[i];
        if(maximo == minimo) continue;
        int ans = INT_MAX, index;
        for (int j = 0; j < 3; j++) {
            int res = abs((minimo + cantidades[j]) - maximo);
            if(res < ans) {
                ans = res;
                index = j;
            }
        }
        if(ans != INT_MAX) {
            if(ans == 0) totalOps++;
            else totalOps += ans+1;
        }
    }

    return totalOps;
}
