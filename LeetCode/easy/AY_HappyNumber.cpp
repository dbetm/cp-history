#include <bits/stdc++.h>
// https://leetcode.com/problems/happy-number
// Tag(s): Maths, implementation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

int sumDigits(int n) {
    int sum = 0;

    while(n > 0) {
        sum += pow(n % 10, 2);
        n /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    int ans;

    set<int> sums;
    sums.insert(n);

    while(true) {
        n = sumDigits(n);
        if(n == 1) {
            ans = true;
            break;
        }
        else if(sums.find(n) != sums.end()) {
            ans = false;
            break;
        }

        sums.insert(n);
    }

    return ans;
}

int main() {
    fastIO
    int n;
    cin >> n;
    cout << isHappy(n) << endl;
	return 0;
}
