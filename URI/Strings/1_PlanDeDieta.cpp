#include <bits/stdc++.h>
// https://www.urionlinejudge.com.br/judge/es/problems/view/1248
// Tag(s): Strings
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
bool dic[27];

void process() {
    string dieta;
    string desayuno;
    string almuerzo;
    getline(cin, dieta);
    getline(cin, desayuno);
    getline(cin, almuerzo);

    memset(dic, false, sizeof(dic));

    for (int i = 0; i < dieta.size(); i++) dic[(int)dieta[i]-65] = true;

    for (int i = 0; i < desayuno.size(); i++) {
        if(dic[(int)desayuno[i]-65] == false) {
            cout << "CHEATER" << endl;
            return;
        }
        dic[(int)desayuno[i]-65] = false;
    }

    for (int i = 0; i < almuerzo.size(); i++) {
        if(dic[(int)almuerzo[i]-65] == false) {
            cout << "CHEATER" << endl;
            return;
        }
        dic[(int)almuerzo[i]-65] = false;
    }

    for (int i = 0; i <= 26; i++) {
        if(dic[i]) cout << ((char)(i+65));
    }

    cout << endl;
}

int main() {
	fastIO
    int n;
    cin >> n;
    cin.get();
    while(n--) {
        process();
    }

	return 0;
}
