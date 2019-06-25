#include <iostream>
// https://omegaup.com/arena/problem/Buzz-Fizz#problems
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if(i % 3 == 0 && i % 5 == 0) cout << "BuzzFizz" << endl;
        else if(i % 3 == 0) cout << "Buzz" << endl;
        else if(i % 5 == 0) cout << "Fizz" << endl;
        else cout << i << endl;
    }
    return 0;
}
