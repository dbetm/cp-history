#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    int t;
    long int a, b;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> a;
        cin >> b;
        if(a == b) cout << "=" << endl;
        else if(a > b) cout << ">" << endl;
        else cout << "<" << endl;
    }

    return 0;
}
