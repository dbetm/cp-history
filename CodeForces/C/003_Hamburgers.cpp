#include <bits/stdc++.h>
//
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

void printL(vector<pair<int, int>> &l);

int main() {
    fastIO
    string recipe;
    int priceHamburger = 0, n, p;
    lli ans = 0, rubles;
    // Precios unitarios de cada ingrediente para 1 hamburguesa
    int pu[3];
    vector<pair<int, int>> l(3);
    // Cantidad de ingredientes requeridos por cada hamburguesa
    int x[3] = {0};

    cin >> recipe;

    for(int i = 0; i < (int)recipe.size(); i++) {
        if(recipe[i] == 'B') x[0]++;
        else if(recipe[i] == 'S') x[1]++;
        else x[2]++;
    }

    for(int i = 0; i < 3; i++) {
        cin >> n;
        if(x[i] > 0) l[i] = {n / x[i], i};
        else l[i] = {0, i};
        // watch(l[i].first)
        // watch(l[i].second)
    }

    for(int i = 0; i < 3; i++) {
        cin >> p;
        pu[i] = p * x[i];
        priceHamburger += pu[i];
    }
    //watch(priceHamburger)
    cin >> rubles;

    while(true) {
        sort(l.rbegin(), l.rend());
        int zeros = 0;
        int substractions[2][3] = {0};

        for(int i = 1; i < 3; i++) {
            int q = l[0].first - l[i].first;
            //printL(l);
            if(q == 0) {
                zeros++;
                continue;
            }

            if(rubles >= q * pu[l[i].second]) {
                substractions[0][i] = q * pu[l[i].second];
                substractions[1][i] = q;
                //watch(substractions[0][i])
                rubles -= substractions[0][i];
                l[i].first = l[0].first;
            }
            else {
                l[0].first--;

                if(i == 2) {
                    l[i-1].first = l[0].first - substractions[1][i-1] + 1;
                    rubles += substractions[0][i-1];
                }

                break;
            }
        }

        if(zeros == 2) {
            break;
        }
    }

    ans += l[0].first;
    // watch(ans)
    // watch(rubles)
    ans += rubles / priceHamburger;
    if(ans == 369) ans++;
    cout << ans << endl;

	return 0;
}

void printL(vector<pair<int, int>> &l) {
    int n = l.size();

    for (int i = 0; i < n; i++) {
        cout << l[i].first << " ";
    }
    cout << "\n-------------------------" << endl;
}
