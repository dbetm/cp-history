#include <bits/stdc++.h>

using namespace std;

int main() {
    string hajj;
    long int i = 1;
    while(getline(cin, hajj)) {
        if(hajj == "Hajj") cout << "Case " << i << ": " << "Hajj-e-Akbar" << endl;
        else if(hajj == "Umrah") cout << "Case " << i << ": " << "Hajj-e-Asghar" << endl;
        else break;
        i++;
    }
}
