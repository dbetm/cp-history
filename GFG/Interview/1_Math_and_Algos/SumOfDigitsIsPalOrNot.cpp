#include <bits/stdc++.h>

using namespace std;

bool isSumDigsPali(int);

int main(int argc, char const *argv[]) {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(isSumDigsPali(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

bool isSumDigsPali(int n) {
    int sum = 0;
    string sumStr = "";
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    sumStr = to_string(sum);
    int s = sumStr.size();

    for (int i = 0, j = s-1; i <= s/2; i++, j--) {
        if(sumStr[i] != sumStr[j]) {
            return false;
        }
    }
    return true;
}
