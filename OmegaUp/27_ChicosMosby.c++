#include <iostream>
// WA
using namespace std;
typedef long long int lli;


int main() {
	lli n, m, x, y;
	cin >> n >> m;

	x = max(n, m);
	y = min(n, m);

	lli res = (x / y) + 2 * (x % y);
	cout << res << endl;

	return 0;
}
