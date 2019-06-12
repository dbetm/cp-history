#include <bits/stdc++.h>

using namespace std;

void computeNumbers();
bool isArmstrong(int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //computeNumbers();
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n == 153 || n == 370 || n == 371 || n == 407) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}


void computeNumbers() {
    for (int i = 100; i < 1000; i++) {
        if(isArmstrong(i)) cout << i << endl;
    }
}

bool isArmstrong(int n) {
    int aux = n;
    int sum = 0;

    while(aux > 0) {
        sum += pow(aux % 10, 3);
        aux /= 10;
    }

    return (sum == n);
}
