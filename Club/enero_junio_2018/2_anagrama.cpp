#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    string A, B;

    cin >> A;
    sort(A.begin(), A.end());

    cin >> B;
    sort(B.begin(), B.end());

    if(A == B) cout << "Sí" << endl;
    else cout << "No" << endl;

    return 0;
}
