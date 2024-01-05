#include <bits/stdc++.h>
// TEST #1: AC
using namespace std;

void printPunchedCards(int r, int c) {

    for (int i = 0; i <= (2 * r); ++i) {
        for (int j = 0; j <= (2 * c); ++j) {
            if(i == 0 and (j == 0 or j == 1)) cout << ".";
            else if(i == 1 and (j == 0 or j == 1)) cout << ".";
            else if(i & 1) { // odd row
                if(j & 1) cout << ".";
                else cout << "|";
            }
            else { // even row
                if(j & 1) cout << "-";
                else cout << "+";
            }
        }
        cout << endl;
    }
}

int main(){
    int t, r, c;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> r >> c;
        cout << "Case #" << i << ":" << endl;
        printPunchedCards(r, c);
    }
}
