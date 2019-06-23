#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/La-familia-de-Buddy#problems
using namespace std;

map<int, int> perros;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        try {
            perros[num]++;
        }
        catch(...) {
            perros.insert(pair<int, int>(num, 1));
        }
    }

    vector<pair<int, int>> frecOrdenadas;
    //map<int, int>::iterator itr;
    for(auto itr = perros.rbegin(); itr != perros.rend(); ++itr) {
        frecOrdenadas.push_back(make_pair(itr->second, itr->first));
    }

    sort(frecOrdenadas.begin(), frecOrdenadas.end());

    for (int i = frecOrdenadas.size()-1; i >= 0; i--) {
        cout << frecOrdenadas[i].second << endl;
    }

    return 0;
}
