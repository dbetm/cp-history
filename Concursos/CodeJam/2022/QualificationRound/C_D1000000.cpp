#include <bits/stdc++.h>
// TEST #1: AC
// TEST #2: AC
#define watch(x) cout << (#x) << " es " << (x) << endl;

using namespace std;

int computeMaxLength(vector<int> &dice) {
    int ans = 0, cont = 1;
    sort(dice.begin(), dice.end());

    for(int &s : dice) {
        if(cont <= s) {
            ++cont;
            ++ans;
        }
    }

    return ans;
}

int main() {
    int t, n, ans;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> n;
        vector<int> dice(n);
        for (int j = 0; j < n; ++j) cin >> dice[j];
        ans = computeMaxLength(dice);
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}
