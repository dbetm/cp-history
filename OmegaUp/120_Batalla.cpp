#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/batalla#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, pointer = 0, suma = 0;
    cin >> n;
    vector<int> mis(n);
    vector<int> Lira(n);
    for (int i = 0; i < n; i++) cin >> mis[i];
    for (int i = 0; i < n; i++) cin >> Lira[i];
    sort(mis.rbegin(), mis.rend());
    sort(Lira.rbegin(), Lira.rend());

    for (int i = 0; i < n; i++) {
        int miSoldado = mis[i];
        //cout << miSoldado << endl;
        while(pointer < n) {
            //cout << "Lira->" << Lira[pointer] << endl;
            if(Lira[pointer] < miSoldado) {
                suma += miSoldado;
                pointer++;
                break;
            }
            pointer++;
        }
        if(pointer == n) break;
    }
    cout << suma << endl;
    return 0;
}
