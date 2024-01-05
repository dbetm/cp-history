#include <bits/stdc++.h>

#define MAX 50001
using namespace std;

int H[MAX];

void init() {
    for (int i = 0; i < MAX; i++) H[i] = -1;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y, cont = 0;
    cin >> n;
    init();

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if(H[x] != -1 && y < H[x]) {
            H[x] = y;
        }
        else if(H[x] == -1) {
            cont++;
            H[x] = y;
        }
    }
    cout << cont << endl;

    for (int i = 0; i < MAX; i++) {
        if(H[i] != -1) cout << i << " " << H[i] << endl;
    }

    return 0;
}
