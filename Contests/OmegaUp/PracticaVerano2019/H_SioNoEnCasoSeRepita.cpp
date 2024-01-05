#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Si-o-No-en-caso-se-repita#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup();

int main() {
	_setup();
    set<int> nums;
    int n = 3, num;
    while(n--) {
        cin >> num;
        nums.insert(num);
    }
    if(nums.size() == 3) cout << "No" << endl;
    else cout << "Si" << endl;
	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
