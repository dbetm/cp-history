#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/2016-Aritmetica-Elemental#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a;
    cin >> b;
    int cont = 0, carry = 0;
    int i = a.size()-1, j = b.size()-1;
    int sum;

    do {
        sum = ((int)(a[i])-48) + ((int)(b[j])-48) + carry;
        if(sum >= 10) {
            carry = 1;
            cont++;
        }
        else carry = 0;
        if(j-1 < 0 || i-1 < 0) {
            break;
        }
        i--;
        j--;
    } while(true);

    if(a.size() > b.size()) {
        while(i--) {
            sum = ((int)(a[i])-48) + carry;
            if(sum >= 10) {
                cont++;
                carry = 1;
            }
            else break;
        }
    }
    else {
        while(j--) {
            sum = ((int)(b[j])-48) + carry;
            if(sum >= 10) {
                cont++;
                carry = 1;
            }
            else break;
        }
    }

    cout << cont << endl;
    return 0;
}
