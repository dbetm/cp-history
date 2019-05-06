#include <bits/stdc++.h>

using namespace std;

int saveThePrisoner(int n, int m, int s){
    int id;
    if(m == 1) id = s;
    else if(m + s - 1 > n) {
        id = (m % n) + (s-1);
        if(m % n == 0 && s == 1) id = n;
        else if(id > n) id = id - n;
    }
    else {
        id = (s - 1) + m;
    }
    return id;
}

int main() {
    int t, n, m, s;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++) {
        cin >> n >> m >> s;
        int result = saveThePrisoner(n, m, s);
        cout << result << endl;
    }
    return 0;
}
