#include <bits/stdc++.h>
// está mal!
using namespace std;

int solve(vector<pair<int, int>> questions, int n, int q, string pali) {
    int cont = 0;
    int a[27];

    for (int i = 0; i < q; i++) {
        memset(a, 0, sizeof(a));
        string aux = "";
        int diff = (questions[i].second - questions[i].first) + 1;
        for (int j = questions[i].first-1; j < questions[i].second; j++) {
            a[(int)(pali[j])-'A']++;
            aux += pali[j];
        }

        if(diff == 1) {
            cont++;
        }
        else if(diff & 1) { // impar
            bool uno = false, dos = false;
            for (int k = 0; k < 27; k++) {
                if(a[k] == 0) continue;
                if(a[k] == 1) {
                    if(uno) {
                        uno = false;
                        break;
                    }
                    else uno = true;
                }
                if(a[k] == 2 || a[k] % 2 == 1) dos = true;
            }
            if(uno && dos) {
                cont++;
            }
        }
        else { // par
            bool dos = true;
            for (int k = 0; k < 27; k++) {
                if(a[k] == 0) continue;
                if(a[k] == 1) {
                    dos = false;
                    break;
                }
            }
            if(dos) {
                cont++;
            }
        }
    }

    return cont;
}

int main(int argc, char const *argv[]) {
    int t, n, q, l, r;
    string pali;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> q;
        cin >> pali;
        vector<pair<int, int>> questions(q);
        for (int j = 0; j < q; j++) {
            cin >> l >> r;
            questions[j] = make_pair(l, r);
        }
        cout << "Case #" << i<< ": " << solve(questions, n, q, pali) << "\n";
    }
    return 0;
}
