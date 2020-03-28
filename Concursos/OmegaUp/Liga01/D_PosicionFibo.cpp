#include <bits/stdc++.h>

// Parcialmente correcta

using namespace std;
typedef long long int lli;

lli findIndex(lli n) {
	long double fibo = 2.078087 * log(n) + 1.672276;

	// returning rounded off value of index
	return round(fibo);
}


bool isFibo(lli n) {

    lli ans = round((log(n) + log(sqrt(5))) / log((sqrt(5)+1)/2));
    ans %= 60;

    return (ans != 0);
}

// Driver program to test above function
int main() {
    lli n;
    cin >> n;
    if(n == 1) cout << 1 << endl;
    else if(!isFibo(n)) {
        cout << -1 << endl;
    }
    else {
        cout << findIndex(n) << endl;
    }
}
