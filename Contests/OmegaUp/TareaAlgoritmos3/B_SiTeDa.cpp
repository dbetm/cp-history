#include <bits/stdc++.h>

using namespace std;

pair<int, int> iniciales;
vector<int> serie;

void procesar(int);

int main(int argc, char const *argv[]) {
    cin >> iniciales.first;
    cin >> iniciales.second;
    serie.push_back(iniciales.first);
    serie.push_back(iniciales.second);

    int dig = (iniciales.first + iniciales.second) % 10;

    procesar(dig);

    for (unsigned int i = 0; i < serie.size()-1; i++) {
        cout << serie[i] << " ";
    }
    cout << serie[serie.size()-1] << "\n";

    cout << serie.size()-2 << "\n";

    return 0;
}

void procesar(int num) {
    serie.push_back(num);
    if(num == iniciales.second && serie[serie.size()-2] == iniciales.first) return;
    procesar((num + serie[serie.size()-2]) % 10);
}
