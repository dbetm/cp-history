#include <iostream>
#include <iomanip>
using namespace std;
// https://www.hackerrank.com/challenges/prettyprint/problem
int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

        cout << setw(0) << showbase << nouppercase << hex << (int64_t)A << endl;
        cout << setfill('_') << fixed << setw(15);
        cout << setprecision(2) << showpos << right << B << endl;
        cout << setw(0) << uppercase << noshowpos << setprecision(9) << scientific << C << endl;
	}
	return 0;
}
