#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/find-first-repeated-character/0/
// tag: string
using namespace std;

string findFirstRepChar(string str);

int main(int argc, char const *argv[]) {
    int n;
    string str;
    cin >> n;

    while(n--) {
        cin >> str;
        cout << findFirstRepChar(str) << endl;
    }

    return 0;
}

string findFirstRepChar(string str) {

    int hash[26] = {0};
    int len = str.size();

    int menor = 99999;

    for (int i = 0; i < len; i++) {
        int key = int(str[i])-97;
        
        if(hash[key] == 1) {
            menor = i;
            break;
        }
        hash[key]++;
    }

    if(menor == 99999) {
        return "-1";
    }
    else {
        string a = "";
        a += str[menor];
        return a;
    }
}
