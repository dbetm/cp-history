#include <iostream>
// https://omegaup.com/arena/problem/Alex-la-barba-y-las-pizzas#problems
using namespace std;

typedef long long int lli;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli n, x, total = 0, pizzas;
    cin >> n >> x;

    while(n--) {
        cin >> pizzas;
        total += (x * pizzas);
    }

    cout << total << endl;
    return 0;
}
