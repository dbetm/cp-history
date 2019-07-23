#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string bin;
    cin >> bin;
    int64_t n = count(bin.begin(), bin.end(), '1');
    cout << (int64_t)((n * (n+1))/2) << endl;
    return 0;
}
