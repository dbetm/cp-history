#include <bits/stdc++.h>
// Parcialmente correcta
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup();

int main() {
	_setup();
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double discriminante = pow(b, 2) - (4.0*a*c);
    if(abs(discriminante) < 0.000001) {
        double r1;
        r1 = (-1.0*b) / (2.0*a);
        cout << r1 << endl;
    }
    else if(discriminante < 0) cout << "NA" << endl;
    else {
        double resRaiz = sqrt(discriminante);
        double r1, r2;
        r1 = ((-1.0*b) + resRaiz) / (2.0*a);
        r2 = ((-1.0*b) - resRaiz) / (2.0*a);
        if(r1 < r2) {
            cout << r1 << endl;
            cout << r2 << endl;
        }
        else {
            cout << r2 << endl;
            cout << r1 << endl;
        }
    }
	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
