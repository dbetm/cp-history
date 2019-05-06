#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector < int > s, int d, int m){
    unsigned int sumaAux, cont = 0;
    for(unsigned int i = 0; i < n; i++) {
        sumaAux = 0;
        for(unsigned int j = i; j < i+m; j++) {
            sumaAux += s[j];
            if(i + m > s.size()) break;
        }
        if(sumaAux == d) cont++;
    }
    return cont;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}
