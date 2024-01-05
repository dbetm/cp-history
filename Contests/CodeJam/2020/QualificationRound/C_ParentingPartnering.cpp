#include <bits/stdc++.h>
// Test 1/2: Accepted, Test 2/2: Accepted
// Tag(s): Greedy, Implementation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

string schedule(vector<pair<int, pair<int, int>>> tiempos);
bool isOverlap(int s1, int e1, int s2);
string format(vector<pair<int, char>> ans);

int main() {
    fastIO
    int t, cont = 1, n, si, ei;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<pair<int, pair<int, int>>> tiempos(n);
        for (int i = 0; i < n; i++) {
            cin >> si >> ei;
            tiempos[i] = {si, {ei, i}};
        }
        sort(tiempos.begin(), tiempos.end());
        cout << "Case #" << (cont++) << ": " << schedule(tiempos) << endl;
    }
	return 0;
}

string schedule(vector<pair<int, pair<int, int>>> tiempos) {
    char c = 'C', j = 'J';
    pair<int, int> cameron, jamie;
    vector<pair<int, char>> ans;
    int n = tiempos.size();

    cameron = {tiempos[0].first, tiempos[0].second.first};
    ans.push_back({tiempos[0].second.second, c});
    jamie = {-1, -1};
    // watch(tiempos[0].first)
    // watch(tiempos[0].second)

    for (int i = 1; i < n; i++) {
        // watch(tiempos[i].first)
        // watch(tiempos[i].second)
        if(!isOverlap(cameron.first, cameron.second, tiempos[i].first)) {
            ans.push_back({tiempos[i].second.second, c});
            cameron = {tiempos[i].first, tiempos[i].second.first};
        }
        else if(!isOverlap(jamie.first, jamie.second, tiempos[i].first)) {
            ans.push_back({tiempos[i].second.second, j});
            jamie = {tiempos[i].first, tiempos[i].second.first};
        }
        else {
            return "IMPOSSIBLE";
        }
    }

    return format(ans);
}

bool isOverlap(int s1, int e1, int s2) {
    return (s2 >= s1 && s2 < e1);
}

string format(vector<pair<int, char>> ans) {
    string schedule = "";
    sort(ans.begin(), ans.end());
    int n = ans.size();
    for (int i = 0; i < n; i++) {
        schedule += ans[i].second;
    }

    return schedule;
}
