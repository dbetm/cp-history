#include <bits/stdc++.h>
//
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

/* Mejor idea:
Crear un Trie con el banco
Tomar cada mutación hasta i y buscar si existe un prefijo en el banco
*/
int minMutation(string start, string end, vector<string>& bank) {
    set<string> bankSet(bank.begin(), bank.end());

    auto it = bankSet.find(end);
    if(it == bankSet.end()) return -1;

    int ans = 0;

    for (int i = 0; i < 8; ++i) {
        if(start[i] != end[i]) ++ans;
    }

    return ans;
}

int main() {
    fastIO
    string start, end;
    int numValids;

    cin >> start >> end;
    cin >> numValids;

    vector<string> bank(numValids);
    for (int i = 0; i < numValids; i++) {
        cin >> bank[i];
    }

    cout << minMutation(start, end, bank) << endl;

	return 0;
}
