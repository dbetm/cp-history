#include <bits/stdc++.h>

using namespace std;

bool forB(vector < int > b, int i) {
    for(unsigned int j = 0; j < b.size(); j++) {
        if(b[j]%i == 0) continue;
        else return false;
    }
    return true;
}

int getTotalX(vector < int > a, vector < int > b){
    int cont = 0;
    bool flag = false;
    //from A
    for(int i = 1; i <= 100; i++) {
        flag = false;
        for(unsigned int j = 0; j < a.size(); j++) {
            if(i%a[j] == 0) continue;
            else {
               flag = true;
               break; 
            }
        }
        if(!flag and forB(b, i)) cont++; 
    }
    return cont;
}


int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}


