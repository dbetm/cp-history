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

void generate(vector<int> &ans, bool &impossible, int c);

int main() {
    fastIO
    int t, n, c;
    bool impossible;
    cin >> t;

    for (int x = 1; x <= t; ++x) {
        cin >> n >> c;
        impossible = false;
        vector<int> ans(n);

        if(c < (n-1)) impossible = true;
        else {
            for (int i = 0; i < n; i++) ans[i] = i+1;
            generate(ans, impossible, c);
        }

        if(impossible) {
            cout << "Case #" << x << ": IMPOSSIBLE" << endl;
        }
        else {
            cout << "Case #" << x << ": ";
            for (int i = 0; i < n-1; ++i) {
                cout << ans[i] << " ";
            }
            cout << ans[n-1] << endl;
        }
    }

	return 0;
}

void generate(vector<int> &ans, bool &impossible, int c) {
    int n = ans.size();
    int totalCost = 0;

    for (int i = n-1; i >= 1; --i) {
        int minIndex = i;

        // for (int j = i-1; j >= 0; --j) {
        //     if(ans[j] < ans[minIndex]) {
        //         minIndex = j;
        //     }
        // }

        if((i - minIndex + 1) > c) continue;

        reverse(ans)
    }

    impossible = totalCost != c;
}


void reverse(vector<int> &numbers, int start, int end) {
    while(start < end) {
        swap(numbers[start], numbers[end]);
        ++start;
        --end;
    }
}
