#include <bits/stdc++.h>
using namespace std;
// https://omegaup.com/arena/problem/Suma-Manhattan#problems
#define MAX 1000000007

// Return the sum of distance of one axis.
long long distancesum(long long arrx[], long long arry[], long long n) {
	// sorting the array.
	sort(arry, arry + n);
    sort(arrx, arrx + n);

	// for each point, finding the distance.
	long long resx = 0, sumx = 0;
    long long resy = 0, sumy = 0;

	for (long long i = 0; i < n; i++) {
		resx += abs(((arrx[i] * i) - sumx));
		sumx += arrx[i];
        resy += abs(((arry[i] * i) - sumy));
		sumy += arry[i];
	}

	return ((resx % MAX) + (resy % MAX))%MAX;
}

// Driven Program
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    long long x[n];
    long long y[n];
    for (long long i = 0; i < n; i++) cin >> x[i] >> y[i];

	cout << distancesum(x, y, n) << endl;
	return 0;
}
