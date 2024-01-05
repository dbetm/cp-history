#include <bits/stdc++.h>
// WA in all cases
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

string process(vector<pair<int, string>> &patrones);

int main() {
    fastIO
    string patron;
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<pair<int, string>> patrones(n);
        for (int j = 0; j < n; j++) {
            cin >> patron;
            patrones[j] = {patron.size() - 1, patron};
        }
        sort(patrones.begin(), patrones.end());
        cout << "Case #" << (i+1) << ": " << process(patrones) << endl;
    }
	return 0;
}

string process(vector<pair<int, string>> &patrones) {
    int len = patrones.size();
    string actual = patrones[0].second.substr(1, patrones[0].second.size()-1);
    string ans = actual;
    string aux;
    bool pert = false;

    for (int i = 1; i < len; i++) {
        aux = patrones[i].second.substr(1, patrones[i].second.size()-1);
        if(actual.size() == aux.size()) {
            if(actual != aux) {
                ans = "*";
                break;
            }
        }
        else {
            int delta = aux.size() - actual.size();
            string matching = aux.substr(delta, aux.size()-delta);
            string addition = aux.substr(0, delta);
            // watch(matching)
            // watch(addition)
            if(actual != matching) {
                ans = "*";
                break;
            }
            else {
                reverse(addition.begin(), addition.end());
                // string aux2 = actual + addition;
                // reverse(aux2.begin(), aux2.end());
                // if(aux2 != ans)
                ans += addition;
                pert = true;
            }
        }
        actual = aux;
    }

    if(ans.size() > 10001) ans = "*";
    if(pert) reverse(ans.begin(), ans.end());
    return ans;
}
