#include <bits/stdc++.h>
// Completed:
// - Test 1 -> +7 pts
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

lli getCost(vector<int> &numbers, const int n);
void reverse(vector<int> &numbers, int start, int end);

int main() {
    fastIO
    int t, n;
    cin >> t;

    for (int x = 1; x <= t; ++x) {
        cin >> n;

        vector<int> numbers(n+1);
        for (int i = 1; i <= n; ++i) cin >> numbers[i];

        lli cost = getCost(numbers, n);
        cout << "Case #" << x << ": " << cost << endl;
    }

	return 0;
}

lli getCost(vector<int> &numbers, const int n) {
    int minIndex;
    lli cost = 0;

    for (int i = 1; i < n; ++i) {
        minIndex = i;

        for (int j = i+1; j <= n; ++j) {
            if(numbers[j] < numbers[minIndex]) {
                minIndex = j;
            }
        }

        reverse(numbers, i, minIndex);

        cost += minIndex - i + 1;
        //watch(cost)
    }

    return cost;
}

void reverse(vector<int> &numbers, int start, int end) {
    while(start < end) {
        swap(numbers[start], numbers[end]);
        ++start;
        --end;
    }
}
