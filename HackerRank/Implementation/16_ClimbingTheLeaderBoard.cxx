#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;

ui ind, u;
vector < ui > scores;

inline ui findRank(ui *aj) {
    ui rank = 0, i;
    if(*aj > u && *aj < scores[0]) {
        for(i = ind - 1; i > 0; i--) {
            if((*aj >= scores[i] && *aj < scores[i - 1])) {
                ind = i;
                break;
            }
        }
        return (ind + 1);
    }
    else if(*aj < u) return (scores.size() + 1);
    else if(*aj == u) return scores.size();
    else return 1;
    return rank;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ui n, m, i, temp;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> temp;
        if(i == 0) m = temp;
        if(temp == m && i != 0) continue;
        scores.push_back(temp);
        m = temp;
    }
    ind = scores.size();
    u = scores[scores.size() - 1];
    cin >> m;
    for(i = 0; i < m; i++) {
        cin >> temp;
        cout << findRank(&temp) << "\n";
    }
    return 0;
}
