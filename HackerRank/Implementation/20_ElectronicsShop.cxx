#include <bits/stdc++.h>

using namespace std;

int getMoneySpent(vector < int >, vector < int >, int);
int maxAdd(int, int, vector < int >);

int main() {
    int s;
    int n;
    int m;
    cin >> s >> n >> m;
    vector<int> keyboards(n);
    for(int keyboards_i = 0; keyboards_i < n; keyboards_i++){
       cin >> keyboards[keyboards_i];
    }
    vector<int> drives(m);
    for(int drives_i = 0; drives_i < m; drives_i++) {
       cin >> drives[drives_i];
    }
    //  The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
    int moneySpent = getMoneySpent(keyboards, drives, s);
    cout << moneySpent << endl;
    return 0;
}

int getMoneySpent(vector < int > keyboards, vector < int > drives, int s) {
    int total = -1, add;
    int addAux = 0;
    for(int i = 0; i < keyboards.size(); i++) {
        add = maxAdd(keyboards[i], s, drives);
        if(add == s) {
            return add;
        }
        if(addAux < add) {
            addAux = add;
        }
    }
    if(addAux != 0) total = addAux;
    return total;
}

int maxAdd(int k, int s, vector < int > drives) {
    int max = 0;
    for(int i = 0; i < drives.size(); i++) {
        if(k + drives[i] <= s && k + drives[i] > max) {
            max = k + drives[i];
        }
    }
    return max;
}
