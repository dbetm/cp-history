#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){
    int n, k, i, e = 100;
    cin >> n >> k;
    int C[n];

    for (int i = 0; i < n; i++){
        cin >> C[i];
    }
    i = 0;
    while (true) {
        e--;
        i = (i + k) % n;
        if(C[i] == 1) e -= 2;
        if(i == 0) break;
    }

    cout << e << endl;

    return 0;
}
