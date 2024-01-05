#include <bits/stdc++.h>
// TLE
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
set<string> subcadenas;
vector<string> subcadenas2;
void procesarSubcadenas(string s);
int procesar(string token);

int main() {
	fastIO
    string texto, token;
    int n;
    cin >> texto;
    procesarSubcadenas(texto);
    /*
    for (auto it = subcadenas.begin(); it != subcadenas.end(); it++) {
        subcadenas2.push_back(*it);
    }
    sort(subcadenas2.begin(), subcadenas2.end());
    */
    cin >> n;

    while(n--) {
        cin >> token;
        cout << procesar(token) << endl;
    }

	return 0;
}

void procesarSubcadenas(string s) {
    int n = s.size();
    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    // Calcular las potencias de p
    for(int i = 0; i < n; i++) p_pow[i] = (p_pow[i-1] * p) % m;
    // Calcular los hashes de cada prefijo
    vector<long long> h(n+1, 0);
    for (int i = 0; i < n; i++) {
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
    long long cur_h;
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n-l; i++) {
            cur_h = (h[i+l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            //watch(s.substr(i, l));
            subcadenas.insert(s.substr(i, l));
        }
    }
}

int procesar(string token) {
    int inicio = 0, fin = token.size()-1;
    string sub;
    int ans = 0;

    do {
        if(inicio < 0 || fin < inicio) {
            ans = -1;
            break;
        }
        sub = token.substr(inicio, fin-inicio+1);
        // Lo encontró
        if(binary_search(subcadenas.begin(), subcadenas.end(), sub)) {
            inicio = fin + 1;
            fin = token.size() - 1;
            ans++;
            if(fin < inicio) break;
        }
        else fin--;
        //cin.get();
    } while(true);


    return ans;
}
