#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[]) {
    ll n, a, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        switch (a) {
            case 1: // abs 1
                cin >> x;
                cout << abs(x) << "\n";
                break;
            case 2: // max 2
                cin >> x >> y;
                cout << max(x, y) << "\n";
                break;
            case 3: // min 2
                cin >> x >> y;
                cout << min(x, y) << "\n";
                break;
            case 4: // sqrt 1
                cin >> x;
                printf("%0.2lf\n", sqrt(x));
                break;
            case 5: // potencia 2
                cin >> x >> y;
                int64_t res = pow(x, y);
                cout << res << "\n";
        }
    }
    return 0;
}
