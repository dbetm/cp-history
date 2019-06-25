#include <algorithm>
#include <iostream>

using namespace std;

inline int popcount(int x){
    int count = 0;
    __asm__ volatile("POPCNT %1, %0;"
        :"=r"(count)
        :"r"(x)
        :
    );
    return count;
}

int main() {
    int a, b, cont = 0;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if(popcount(i) <= 4) cont++;
    }

    cout << cont << endl;
    return 0;
}
