#include <bits/stdc++.h>

using namespace std;
typedef vector<pair<int, pair<string, string>>> vppi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, edad, i = 0;
    pair<string, string> nombreYPasatiempo;
    cin >> n;
    vppi gente(n);
    while(n--) {
        cin >> nombreYPasatiempo.first; // nombre
        cin >> edad;
        cin >> nombreYPasatiempo.second; // hobby
        pair <int, pair<string, string>> datos;
        datos.first = edad;
        datos.second = nombreYPasatiempo;
        gente[i] = datos;
        i++;
    }
    sort(gente.begin(), gente.end());

    for (int k = gente.size()-1; k >= 0; k--) {
        cout << gente[k].second.first << " " << gente[k].first << " " << gente[k].second.second << endl;
    }

    return 0;
}
