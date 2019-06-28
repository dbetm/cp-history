#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Cope-Maestro-Pokemon#problems
using namespace std;

set<uint64_t> numbers;

void generarTabla();

int main() {
    generarTabla();
    int n;
    uint64_t num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto itr = numbers.find(num);
        if(itr != numbers.end()) cout << num << " ";
    }
    cout << endl;
    return 0;
}

void generarTabla() {
    numbers.insert(1);
    numbers.insert(2);
    uint64_t a = 1, b = 2, temp;

    for (int i = 2; i <= 718; i++) {
        temp = b;
        b = a + b;
        numbers.insert(b);
        a = temp;
    }
}
