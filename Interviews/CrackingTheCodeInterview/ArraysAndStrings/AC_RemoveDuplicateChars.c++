#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " es " << x << endl;

void runTests();

string removeDuplicates(string str) {
    /*
    int i = 0, n;

    while(true) {
        n = str.size();
        if(i >= n) break;

        for (int j = i+1; j < n; ++j) {
            if(str[i] == str[j]) {
                str.erase(str.begin()+j);
                n = str.size();
                j--;
            }
            //watch(str)
        }
        //cout << "---------------------" << endl;
        ++i;
    }
    */

    int n = str.size();
    if(n < 2) return str;

    int tail = 1, j;
    for (int i = 1; i < n; ++i) {
        for (j = 0; j < tail; ++j) {
            if(str[i] == str[j]) break;
        }
        if(j == tail) {
            str[tail] = str[i];
            ++tail;
        }
    }
    //watch(tail)
    str.erase(str.begin()+tail, str.begin()+n);

    return str;

}

int main() {
    string str;
    cin >> str;

    cout << removeDuplicates(str) << endl;

    runTests();
}

void runTests() {
    assert(removeDuplicates("a") == "a");

    assert(removeDuplicates("Xxopp") == "Xxop");

    assert(removeDuplicates("weeqq") == "weq");

    assert(removeDuplicates("123456aaaaaa") == "123456a");

    assert(removeDuplicates("goooooooooooool") == "gol");

    assert(removeDuplicates("") == "");
}
