#include <bits/stdc++.h>

using namespace std;

int main() {
    long int n, dig, total = 0;
    char c;
    cin >> n;
    long int inicial[n];

    for (int i = 0; i < n; i++) {
        cin >> c;
        dig = (int)c-48;
        inicial[i] = dig;
    }
    for (int i = 0; i < n; i++) {
        cin >> c;
        dig = (int)c-48;
        int res1 = abs(inicial[i]-dig);
        int res2 = inicial[i]+1;
        res2 += 9-dig;
        if(res1 <= res2) total += res1;
        else total += res2;
        //total += min(abs(inicial[i]-dig), abs(inicial[i] + (9-dig) + 1));
    }

    cout << total << endl;

    return 0;
}
