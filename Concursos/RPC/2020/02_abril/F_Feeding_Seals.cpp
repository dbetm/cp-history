#include <bits/stdc++.h>
// Tiempo límite excedido
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
const int MAX = 100001;
bool mapa[MAX];
vector<lli> weights(MAX);

void buscarParejaIdeal(int w, int b) {

    for (int i = b-1; i >= 0; i--) {
        if(mapa[i] && weights[i] <= w) {
            mapa[i] = false;
            break;
        }
    }
}

int main() {
    fastIO
    lli buckets, capacity, cont = 0;
    cin >> buckets >> capacity;

    for (int i = 0; i < buckets; i++) {
        cin >> weights[i];
        mapa[i] = true;
    }
    sort(weights.begin(), weights.end());
    lli ideal;
    for (int i = 0; i < buckets; i++) {
        if(mapa[i] == false) continue;
        mapa[i] = false;
        ideal = capacity - weights[i];
        buscarParejaIdeal(ideal, buckets);
        cont++;
    }

    cout << cont << endl;

	return 0;
}
