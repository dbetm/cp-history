#include <iostream>
#include <string>
#include <algorithm>
// https://omegaup.com/arena/problem/Buddy-y-las-palabras-locas#problems
using namespace std;

int main(void) {
    // Faster I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Implementation
    int n, q;
    cin >> n >> q;
    char op;
    // Accs
    int invert = 0, upperLowerCase = 0, transform = 0;
    // string
    string str;
    cin >> str;
    //
    while(q--) {
        cin >> op;
        if(op == 'M') upperLowerCase++;
        else if(op == 'I') invert++;
        else transform++;
    }

    if(transform % 2) {
        for (int j = n-1; j >= 0; j--) {
            if(str[j] > 'm') {
                str[j] = (char)((int)(str[j]) - 13);
            }
            else {
                str[j] = (char)((int)(str[j]) + 13);
            }
        }
    }

    if(invert % 2) {
        reverse(str.begin(), str.end());
    }
    if(upperLowerCase % 2) {
        for (auto & c: str) c = toupper(c);
    }
    // print the res
    cout << str << endl;
    return 0;
}
