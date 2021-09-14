#include <iostream>
// https://omegaup.com/arena/problem/Comparando-numero-de-galaxias/
// Tag(s): Implementación
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if(a < b) cout << "True ";
    else cout << "False ";

    if(c > a) cout << "True ";
    else cout << "False ";

    if(a == b) cout << "True ";
    else cout << "False ";

    if(a != c) cout << "True ";
    else cout << "False ";

    if(c <= b) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}
