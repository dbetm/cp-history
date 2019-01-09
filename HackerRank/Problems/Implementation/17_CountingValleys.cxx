#include <bits/stdc++.h>
using namespace std;

unsigned int countValleys(unsigned int, string);

int main(int argc, char const *argv[]) {
    string str;
    unsigned int n;
    cin >> n;
    cin >> str;
    cout << countValleys(n, str) << endl;
    return 0;
}

unsigned int countValleys(unsigned int n, string str) {
    unsigned int total = 0;
    int cont = 0;
    bool above = true;
    for(unsigned int i = 0; i < n; i++) {
        if(str[i] == 'U') {
            cont++;
            if(!above && cont == 0) {
                above = true;
                total++;
            }
        }
        else {
            cont--;
            if(cont < 0) {
                above = false;
            }
        }
    }
    return total;
}
