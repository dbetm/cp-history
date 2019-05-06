#include <bits/stdc++.h>

using namespace std;
int calculateHeight(int);

int main(int argc, char const *argv[]) {
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        cout << calculateHeight(n) << endl;
    }
    return 0;
}

int calculateHeight(int n) {
    int height = 1;
    for(int i = 1; i <= n; i++) {
        if(i % 2 != 0) height *= 2;
        else height += 1;
    }
    return height;
}
