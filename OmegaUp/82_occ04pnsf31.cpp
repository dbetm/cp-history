#include <iostream>
// https://omegaup.com/arena/problem/Histograma_Horizontal#problems
using namespace std;

int main() {
    int a[4];
    scanf("%d %d %d %d",&a[0], &a[1], &a[2], &a[3]);
    for (int i = 0; i < 4; i++) {
        while(a[i]--) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
