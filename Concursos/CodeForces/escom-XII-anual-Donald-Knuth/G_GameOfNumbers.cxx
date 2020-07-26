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

bool compare(string n1, string n2);

int main() {
    fastIO
    int n;
    string number;
    cin >> n;
    vector<string> numbers;
    for (int i = 0; i < n; i++) {
        cin >> number;
        sort(number.rbegin(), number.rend());
        numbers.push_back(number);
    }

    sort(numbers.rbegin(), numbers.rend(), compare);
    int len = numbers.size();
    for (int i = 0; i < len; i++) {
        //cout << numbers[i] << endl;
        cout << numbers[i];
    }
    cout << endl;

	return 0;
}

bool compare(string n1, string n2) {
    int len = min(n1.size(), n2.size());

    bool ans = false;
    bool broken = false;
    // watch(n1)
    // watch(n2)

    for (int i = 0; i < len; i++) {
        if(n2[i] > n1[i]) {
            ans = true;
            broken = true;
            break;
        }
        else if(n2[i] < n1[i]) {
            broken = true;
            break;
        }
    }
    if(!broken) {
        if(n2.size() < n1.size()) {
            ans = true;
        }
    }
    // watch(ans)
    // cout << "-----------" << endl;
    return ans;
}
