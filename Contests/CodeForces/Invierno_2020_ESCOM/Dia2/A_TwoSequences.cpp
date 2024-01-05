#include <bits/stdc++.h>
//
// tags: implementación
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
#define watch(x) cout << (#x) << " es " << x << endl;

void calc(int n, int k) {
	int a[n], b[n];
    int cont = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a, a+n);
	sort(b, b+n);
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if(a[i] != b[i]) {
			if(abs(a[i] - b[i]) <= k) {
                cont++;
                if(cont > 1) {
                    flag = false;
    				break;
                }
			}
            else {
                flag = false;
                break;
            }
		}
	}

	if(flag) printf("YES\n");
	else printf("NO\n");
}

int main() {
	fastIO
	vi A, B;
	int t, n, k;
	cin >> t;

	while(t--) {
		cin >> n >> k;
		calc(n, k);
	}

	return 0;
}
