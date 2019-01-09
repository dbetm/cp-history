#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    short T;
    int K;
    long int total = 0;
    string op;

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> op;
        if(op == "donate") {
            cin >> K;
            total += K;
        }
        else {
            cout << total << endl;
        }
    }
    return 0;
}
