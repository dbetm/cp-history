#include <bits/stdc++.h>

using namespace std;
int a[27];

void mapear(int pos) {
    a[pos]++;
}

void masSeRepite() {
    int aux = -1;
    int pos;
    for (int i = 0; i < 27; ++i) {
        if(a[i] > aux) {
            pos = i;
            aux = a[i];
        }
    }
    cout << (char)(pos+97) << ", " << (char)(pos+65) << endl;
}

int main(int argc, char* argv[]) {
    char aux;

    while (cin.get(aux) && aux != '\n') {
        if(aux >= 'a' && aux <= 'z')
            mapear((int)aux-97);
        else if(aux >= 'A' && aux <= 'Z')
            mapear((int)aux-65);
    }

    masSeRepite();

    return 0;
}
