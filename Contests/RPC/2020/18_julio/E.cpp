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

int main() {
    fastIO
    string rhyme;
    vector<string> team1, team2;
    int n;
    getline(cin, rhyme);

    int cont = 1, aux = 1, index = 0;
    int len = rhyme.size();
    for (int i = 0; i < len; i++) {
        if(int(rhyme[i]) == 32) cont++;
    }
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }
    //watch(names.size())
    bool forT1 = true;

    while(names.size() != 1) {
        if(aux++ % cont == 0) {
            //cout << names[index] << endl;
            if(forT1) {
                team1.push_back(names[index]);
                forT1 = false;
            }
            else {
                team2.push_back(names[index]);
                forT1 = true;
            }
            vector<string>::iterator it = names.begin()+index;
            names.erase(it);
            aux = 1;
            continue;
        }
        index = (index + 1) % names.size();
    }

    if(forT1) team1.push_back(names[0]);
    else team2.push_back(names[0]);

    auto output = [&](vector<string> team) {
        int m = team.size();
        cout << m << endl;
        for (int i = 0; i < m; i++) {
            cout << team[i] << endl;
        }
    };

    output(team1);
    output(team2);

	return 0;
}
