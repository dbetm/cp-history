#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;

int main() {
    ui N, x, y, Q;
    vector < ui > A;
    vector < ui >::iterator low;
    cin >> N;
    for (ui i = 0; i < N; ++i) {
        cin >> x;
        A.push_back(x);
    }
    cin >> Q;
    for (ui i = 0; i < Q; ++i) {
        cin >> y;
        low = lower_bound(A.begin(), A.end(), y);
        if(binary_search(A.begin(), A.end(), y)) {
            cout << "Yes " << (low - A.begin() + 1) << endl;
        }
        else cout << "No " << (low - A.begin() + 1) << endl;
    }
    return 0;
}
