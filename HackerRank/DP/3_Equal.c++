#include <bits/stdc++.h>

using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

int getMinOps(vector<int> &chocolates, int n, int menor);

int main() {
    fastIO();
    int t, n, menor;
    cin >> t;
    while(t--) {
        cin >> n;
        menor = INT_MAX;
        vector<int> chocolates(n);
        for (int i = 0; i < n; i++) {
            cin >> chocolates[i];
            menor = min(menor, chocolates[i]);
        }
        cout << getMinOps(chocolates, n, menor) << endl;
    }
    return 0;
}

int getMinOps(vector<int> &chocolates, int n, int menor) {
    int ans = 0, aux, cant;
    int entropia = 0;
    for (int i = 0; i < n; i++) entropia += chocolates[i] - menor;
    entropia += menor;
    //watch(menor) watch(entropia)
    if(entropia != menor) {
        // int valores[] = {1, 2, 5};
        for (int i = 0; i < n; i++) {
            cant = entropia - chocolates[i];
            aux = 0;
            if(cant >= 5) {
                aux += cant / 5;
                cant = cant % 5;
            }
            if(cant >= 2) {
                aux += cant / 2;
                cant = cant % 2;
            }
            if(cant >= 1) {
                aux += cant / 1;
            }
            ans = max(ans, aux);
        }

    }

    return ans;
}
