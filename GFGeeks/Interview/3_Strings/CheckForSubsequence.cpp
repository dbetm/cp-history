#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/check-for-subsequence/0/
// Tag(s): string
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

bool isSubsequence(string a, string b);

int main() {
    fastIO
    string a, b;
    int t;
    cin >> t;

    while(t--) {
        cin >> a >> b;
        cout << (isSubsequence(a, b) ? 1 : 0) << endl;
    }
	return 0;
}

bool isSubsequence(string a, string b) {
    int lenA = a.size(), lenB = b.size();
    if(lenA > lenB) return false;

    bool ans = true;

    int pointer = 0;
    for (int i = 0; i < lenA; i++) {
        bool flag = false;
        for (int j = pointer; j < lenB; j++) {
            if(a[i] == b[j]) {
                flag = true;
                pointer = j + 1;
                break;
            }
        }
        if(!flag) {
            ans = false;
            break;
        }
    }
    
    return ans;
}
