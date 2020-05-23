#include <bits/stdc++.h>
// J. Historical TV Remote Control
// Estado: Funcionó
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

bool buttons[10];

bool checkDigits(string n);
int getMin(int n);

int main() {
	fastIO();
    int n, aux, target;
    cin >> n;
    while(n--) {
        cin >> aux;
        buttons[aux] = true;
    }

    cin >> target;
    cout << getMin(target) << endl;

	return 0;
}

int getMin(int n) {
    int steps = 0;
    int down = n, up = n;

    if(checkDigits(to_string(n))) return 0;

    do {
        if((down - 1) < 0) {
            down = 0;
        }
        else down--;
        if((up + 1) > 999) {
            up = 999;
        }
        else up++;

        if(checkDigits(to_string(down))) {
            steps++;
            break;
        }
        else if(checkDigits(to_string(up))) {
            steps++;
            break;
        }
        else steps++;

    } while(true);


    return steps;
}

bool checkDigits(string n) {
    bool ans = true;

    for (int i = 0; i < (int)n.size(); i++) {
        int index = (int)n[i]-48;
        if(buttons[index]) {
            ans = false;
            break;
        }
    }

    return ans;
}
