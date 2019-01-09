#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef unsigned long uli;

ui countNumberDig(uli n) {
    ui numDig = 0, dig;
    uli num = n;
    while(n > 0) {
        dig = n % 10;
        if(dig != 0 && num % dig == 0) numDig++;
        n /= 10;
    }

    return numDig;
}

int main(int argc, char* argv[]) {
    ui t, i = 0;
    uli n;
    cin >> t;
    while(i < t) {
        cin >> n;
        cout << countNumberDig(n) << endl;
        i++;
    }
    return 0;
}
