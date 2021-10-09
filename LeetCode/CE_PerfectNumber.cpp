#include <bits/stdc++.h>
// https://leetcode.com/problems/perfect-number/
// Tag(s): maths, implementation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

/*
Time: O(sqrt(n))
Memory: O(1)
*/
bool checkPerfectNumber(int num) {
    /* Note: We could apply the Euclid-Euler Theorem
    Euclid proved that 2^{p−1}*(2^p− 1) is an even perfect
    number whenever 2^p − 1 is prime, where p is prime.
    */
    int sumDivs = 0;

    for (int i = 1; i * i <= num; i++) {
        if(num % i == 0) {
            sumDivs += i;

            if(i * i != num) sumDivs += num / i;

            if((sumDivs-num) > num) break;
        }
    }
    return (sumDivs-num) == num;
}

int main() {
    fastIO
    int n;
    cin >> n;

    cout << checkPerfectNumber(n) << endl;

	return 0;
}
