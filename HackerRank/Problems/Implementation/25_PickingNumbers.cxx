#include <bits/stdc++.h>
using namespace std;
int pickingNumbers(vector < int >);

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector < int > a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << pickingNumbers(a) << endl;
    return 0;
}

int pickingNumbers(vector < int > a) {
    int total = 0, cont;

    for(unsigned int k = 0; k < a.size(); k++) {
        cont = 0;
        for(unsigned int i = 0; i < a.size(); i++) {
            if(a[k] == a[i] || a[k] == a[i] + 1) cont++;
        }
        if(total < cont) {
            total = cont;
        }
    }
    return total;
}
