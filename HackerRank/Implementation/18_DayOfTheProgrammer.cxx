#include <bits/stdc++.h>

using namespace std;

bool esBisiestoGregorian(int);
bool esBisiestoJulian(int);

string solve(int year){
    string output = "";
    if(year == 1918) {
        output = "26.09.1918";
    }
    else if(year <= 1917) {
        if(esBisiestoJulian(year)) {
            output = "12.09." + to_string(year);
        }
        else {
            output = "13.09." + to_string(year);
        }
    }
    else {
        if(esBisiestoGregorian(year)) {
            output = "12.09." + to_string(year);
        }
        else {
            output = "13.09." + to_string(year);
        }
    }
   return output;
}

bool esBisiestoGregorian(int year) {
    bool respuesta = false;
    if(year % 400 == 0) respuesta = true;
    if(year % 4 == 0 && year % 100 != 0) respuesta = true;
    return respuesta;
}

bool esBisiestoJulian(int year) {
    bool respuesta = false;
    if(year % 4 == 0) respuesta = true;
    return respuesta;
}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}
