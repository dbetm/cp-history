#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Bombasydetonadores#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int b, d;
    long int total = 0, costo;
    int bombas[26] = {0};
    //int detonadores[26] = {0};
    int costos[26] = {0};
    char c;
    cin >> b;

    for (int i = 0; i < b; i++) {
        cin >> c;
        bombas[(int)c-65]++;
    }
    cin >> d;
    for (int i = 0; i < d; i++) {
        cin >> c;
        if(bombas[(int)c-65] != 0) {
            costos[(int)c-65]++;
            bombas[(int)c-65]--;
        }
    }

    for (int i = 0; i < 26; i++) {
        cin >> costo;
        total += costos[i] * costo;
    }
    cout << total << endl;
    return 0;
}
