#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/CR-Angry-Birds#problems
using namespace std;

int main(int argc, char const *argv[]) {
    string res;
    unsigned long suma = 0;
    while(cin >> res) {
        if(res == "o--") suma += 1;
        else if(res == "oo-") suma += 2;
        else if(res == "ooo") suma += 3;
    }

    cout << suma << endl;
    return 0;
}
