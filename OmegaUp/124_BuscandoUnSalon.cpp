#include <iostream>
// https://omegaup.com/arena/problem/Buscando-un-salon-ASINUS#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    double mayor = 0, lado, area;
    int index = -1;
    bool error = false;
    for (int i = 0; i < 5; i++) {
        cin >> lado;
        if(lado == 0) error = true;
        area = lado*lado;
        if(area > mayor) {
            mayor = area;
            index = i+1;
        }
    }
    if(error) cout << "ERROR" << endl;
    else {
        cout << index << endl;
        int diff = mayor - 40;
        if(diff < 0) cout << "FUERA:" << abs(diff) << endl;
        else if(diff > 0) cout << "OYENTES:" << diff << endl;
    }
    return 0;
}
