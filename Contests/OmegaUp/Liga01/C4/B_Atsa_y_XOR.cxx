#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli max_xor(lli n, lli arr[]);

int main()  {
    lli n;
    cin >> n;
    lli arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }



	return 0;
}

lli max_xor(lli n, lli arr[]) {
	lli maxx = 0, mask = 0;

	set<lli> se;
	for (int i = 63; i >= 0; i--) {

		// Actualizar la máscara
		// like 100000, 110000, 111000..
		mask |= (1 << i);

		for (int i = 0; i < n; ++i) {
			// Just keep the prefix till
			// i'th bit neglecting all
			// the bit's after i'th bit
			se.insert(arr[i] & mask);
		}

		lli newMaxx = maxx | (1 << i);

		for (int prefix : se) {
			// find two pair in set
			// such that a^b = newMaxx
			if (se.count(newMaxx ^ prefix)) {
				maxx = newMaxx;
				break;
			}
		}
		se.clear();
	}

	return maxx;
}
