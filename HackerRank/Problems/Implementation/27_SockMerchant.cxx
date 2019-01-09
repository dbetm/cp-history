#include <bits/stdc++.h>

using namespace std;

int sockMerchant(int, vector <int>);
int findPair(int, vector <int>);

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = sockMerchant(n, ar);
    cout << result << endl;
    return 0;
}

int sockMerchant(int n, vector <int> ar) {
    int pairs = 0, index;
    bool control = true;
    while(control) {
        for(unsigned int i = 0; i < ar.size(); i++) {
            index = findPair(i, ar);
            if(index >= 0) {
                ar.erase(ar.begin()+index);
                ar.erase(ar.begin()+i);
                pairs++;
                break;
            }
            else {
                if(i+1 == ar.size() || ar.size() == 0) {
                    control = false;
                    break;
                }
            }
        }
        if(ar.size() == 0) control = false;
    }

    return pairs;
}

int findPair(int pos, vector <int> ar) {
    int index = -1;
    for(unsigned int j = pos+1; j < ar.size(); j++) {
        if(ar[pos] == ar[j]) {
            index = j;
            break;
        }
    }
    return index;
}
