#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    string word;
    int i = 1;
    while(getline(cin, word)) {
        if(word == "HELLO") cout << "Case " << i << ": ENGLISH" << "\n";
        else if(word == "HOLA") cout << "Case " << i << ": SPANISH" << "\n";
        else if(word == "HALLO") cout << "Case " << i << ": GERMAN" << "\n";
        else if(word == "BONJOUR") cout << "Case " << i << ": FRENCH" << "\n";
        else if(word == "CIAO") cout << "Case " << i << ": ITALIAN" << "\n";
        else if(word == "ZDRAVSTVUJTE") cout << "Case " << i << ": RUSSIAN" << "\n";
        else if(word == "#") break;
        else cout << "Case " << i << ": UNKNOWN" << "\n";
        i++;
    }

    return 0;
}
