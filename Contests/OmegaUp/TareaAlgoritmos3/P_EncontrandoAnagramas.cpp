#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    string A, B;

    cin >> A;
    sort(A.begin(), A.end());

    cin >> B;
    sort(B.begin(), B.end());

    if(A == B) cout << "ANAGRAMA!\n";
    else cout << "No :(\n";

    return 0;
}
