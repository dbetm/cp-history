#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/dynamic-array/problem
// Tag(s): array, linked lists, vector
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;


int main() {
    fastIO
    int n, q, type, x, y, lastAnswer = 0, index;

    cin >> n >> q;
    vector< vector<int> > seqList(n);

    while(q--) {
        cin >> type >> x >> y;

        if(type == 1) {
            seqList[(x ^ lastAnswer) % n].push_back(y);
        }
        else {
            index = (x ^ lastAnswer) % n;
            lastAnswer = seqList[index][y % seqList[index].size()];
            cout << lastAnswer << endl;
        }
    }

	return 0;
}
