#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int min = 0, n;
    bool dig = false, low = false, up = false, special = false;
    char aux;
    cin >> n;
    cin.get();
    for(unsigned int i = 0; i < n; i++) {
        cin.get(aux);
        if(!dig && (int)aux >= 48 && (int)aux <= 57) dig = true;
        else if(!low && (int)aux >= 97 && (int)aux <= 122) low = true;
        else if(!up && (int)aux >= 65 && (int)aux <= 90) up = true;
        else if(!special && (aux == '!' || aux == '@' || aux == '#' || aux == '$' || aux == '%' || aux == '^' || aux == '&' || aux == '*' || aux == '(' || aux == ')' || aux == '-' || aux == '+')) special = true;
    }

    if(n < 6) {
        if(dig && low && up && special) min = 6 - n;
        else {
            if(!dig) min++;
            if(!low) min++;
            if(!up) min++;
            if(!special) min++;
            if(min + n < 6)
                min += 6 - (min + n);
        }
    }
    else if(n >= 6) {
        if(!dig) min++;
        if(!low) min++;
        if(!up) min++;
        if(!special) min++;
    }
    cout << min << endl;
    return 0;
}
