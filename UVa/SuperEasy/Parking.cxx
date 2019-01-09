#include <bits/stdc++.h>
using namespace std;

int calc(vector<int> pos) {
    int respuesta = 0;
    sort(pos.begin(),pos.end());
    respuesta = pos[pos.size() - 1] - pos[0];
    return respuesta*2;
}

int main(int argc, char* argv[]) {
    vector <int> pos;
    int cases, shops, p;
    cin >> cases;

    for (int i = 0; i < cases; ++i) {
        cin >> shops;
        for (int j = 0; j < shops; j++) {
            cin >> p;
            pos.push_back(p);
        }
        cout << calc(pos) << endl;
        pos.clear();
    }

    return 0;
}
