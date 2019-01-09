#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/repeated-string/problem
using namespace std;

bool isA(char);

int main(int argc, char const *argv[]) {
    string str;
    long int n, ans, l;
    int m, x, extra, cont = 0;

    cin >> str;
    cin >> n;
    m = str.size();
    x = count_if(str.begin(), str.end(), isA);
    l = n / m;
    ans = l * x;
    extra = n % m;
    for (size_t i = 0; i < extra; i++) {
        if(isA(str[i])) cont++;
    }
    ans += cont;
    cout << ans << endl;
    return 0;
}

bool isA(char c) {
    return (c == 'a');
}
