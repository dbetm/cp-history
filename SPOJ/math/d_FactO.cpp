#include <bits/stdc++.h>
// https://www.spoj.com/problems/FACT0/
// Tag(s): Teoría de números
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

void mostrarFactorizacion(map<lli, int> fact);
map<lli, int> wheelFact(lli n);

int main() {
    fastIO
    lli n;
    do {
        cin >> n;
        if(n == 0) break;
        else mostrarFactorizacion(wheelFact(n));
    } while(true);
	return 0;
}

void mostrarFactorizacion(map<lli, int> fact) {
    map<lli, int>::iterator itr;
    for (itr = fact.begin(); itr != fact.end(); ++itr) {
        cout << itr->first << "^" << itr->second << " ";
    }
    cout << endl;
}

map<lli, int> wheelFact(lli n) {
    map<lli, int> facts;
    int cont;
    for(lli d: {2, 3, 5}) {
        cont = 0;
        while(n % d == 0) {
            cont++;
            n /= d;
        }
        if(cont > 0) facts.insert({d, cont});
    }

    static array<int, 8> incrementos = {4, 2, 4, 2, 4, 6, 2, 6};
    int i;
    lli lim = sqrt(n);
    for (lli d = 7; d <= lim; d += incrementos[i++]) {
        cont = 0;
        while(n % d == 0) {
            cont++;
            n /= d;
        }
        if(cont > 0) facts.insert({d, cont});
        i %= 8;
    }

    if(n > 1) facts.insert({n, 1});

    return facts;
}
