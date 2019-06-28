#include <iostream>
// https://omegaup.com/arena/problem/Consonantes-y-vocales#problems
using namespace std;
int main() {
    char c;
    int vocales = 0, consonantes = 0;
    while(cin >> c) {
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') vocales++;
        else consonantes++;
    }
    cout << consonantes << " " << vocales << endl;
}
