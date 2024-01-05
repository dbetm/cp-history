#include <bits/stdc++.h>
// https://maps20.kattis.com/problems/maps20.schoolspirit
// Tag(s): Math, implementation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int main() {
    fastIO
    int n;
    cin >> n;
    double sum = 0;
    vector<double> scores(n);

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
        sum += scores[i] * (pow(4, i) / pow(5, i));
    }

    sum /= 5;
    printf("%0.7f\n", sum);
    //cout << setprecision(11) << sum << endl;

    double sum2 = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        double aux = 0;
        for (int j = 0; j < n; j++) {
            if(j == i) {
                flag = true;
                continue;
            }
            if(!flag) {
                aux += scores[j] * (pow(4, j) / pow(5, j));
            }

            else {
                aux += scores[j] * (pow(4, j-1) / pow(5, j-1));
            }
        }
        aux /= 5;
        sum2 += aux;
    }

    sum2 /= n;

    //cout << setprecision(11) << sum2 << endl;
    printf("%0.7f\n", sum2);

	return 0;
}
