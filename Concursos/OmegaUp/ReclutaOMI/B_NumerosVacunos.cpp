#include <iostream>
#include <algorithm>

using namespace std;

bool esVacuno(int n) {
    bool ans = true;
    int contUnos = 0;
    while(n > 0) {
        if(n % 2 == 1) {
            contUnos++;
            if(contUnos > 4) {
                ans = false;
                break;
            }
        }
        n /= 2;
    }

    return ans;
}

int main() {
    int a, b, cont = 0;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if(esVacuno(i)) cont++;
    }

    cout << cont << endl;
    return 0;
}
