#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/perfect-numbers/0/
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

bool isPerfectNumber(int64_t n);

int main() {
	fastIO
    int t;
    int64_t n;
    cin >> t;

    while(t--) {
        cin >> n;
        cout << isPerfectNumber(n) << endl;
    }

	return 0;
}

bool isPerfectNumber(int64_t n) {
    bool ans = false;
    vector<int64_t> firstPlace, secondPlace;

    for (int64_t i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) { // es divisor i
            firstPlace.push_back(i);
            if(n/i != i) {
                secondPlace.push_back(n/i);
            }
        }
    }

    int64_t sum = 0;
    int tam = firstPlace.size();
    for (int64_t i = 0; i < tam; i++) {
        sum += firstPlace[i];
        //cout << firstPlace[i] << " ";
    }

    for (int64_t i = secondPlace.size()-1; i > 0; i--) {
        sum += secondPlace[i];
        //cout << secondPlace[i] << " ";
    }
    //cout << endl;
    ans = (sum == n) ? true : ans;

    return ans;
}
