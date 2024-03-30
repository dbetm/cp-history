#include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/977/B
// Tags: Implementation, strings
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
char tabla[27][27];

void encontrarModaTwoGram(string str, int n) {
    pair<pair<int, int>,int> maximo;
    maximo.first.first = maximo.first.second = maximo.second = 0;

    int x, y;

    for (int i = 0; i < n-1; i++) {
        x = (int)str[i]-65;
        y = str[i+1]-65;
        tabla[x][y]++;

        if(tabla[x][y] > maximo.second) {
            maximo.first.first = x;
            maximo.first.second = y;
            maximo.second = tabla[x][y];
        }

    }
    cout << (char)(maximo.first.first + 65) << (char)(maximo.first.second + 65) << endl;
}

int main() {
	fastIO
    string str;
    int n;
    cin >> n;
    cin >> str;
    encontrarModaTwoGram(str, n);
	return 0;
}
