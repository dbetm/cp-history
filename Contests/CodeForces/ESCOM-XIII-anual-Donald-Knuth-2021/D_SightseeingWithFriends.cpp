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

bool isThereAPhoto(vector<int> ranges[], int u, int v, int m);

vector<int> inits;
set<int> setInits;
/*
bool compare(pair<int, int> a, pair<int, int> b) {
    return ((abs(a.first - a.second)) > (abs(b.first - b.second)));
}
*/

int main() {
    fastIO
    int n, m, q;
    int l, r, u, v;
    cin >> n >> m >> q;

    // map<int, vector<int>> ranges;
    vector<int> ranges[n+1];

    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        ranges[l].push_back(r);
        if(setInits.find(l) == setInits.end()) {
            inits.push_back(l);
            //watch(l)
            setInits.insert(l);
        }
    }

    for (int i = 0; i < m; i++) {
        if(!ranges[i].empty()) {
            sort(ranges[i].begin(), ranges[i].end());
        }
    }
    // sort(ranges.begin(), ranges.end(), compare);

    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        if(isThereAPhoto(ranges, u, v, m)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

	return 0;
}

bool isThereAPhoto(vector<int> ranges[], int u, int v, int m) {
    bool ans = false;
    if(v < u) swap(u, v);
    //watch(u)
    //watch(v)

    int len = inits.size();

    for (int i = 0; i < len; i++) {
        //watch(inits[i])
        if(inits[i] > u) {
            break;
        }
        int z = ranges[inits[i]].size();
        if(v <= ranges[inits[i]][z-1]) {
            ans = true;
            break;
        }
    }

    return ans;
}
