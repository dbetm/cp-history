#include <bits/stdc++.h>
// Pasa 6 casos
using namespace std;
typedef vector<int> vec;

int lis(vec &, int);

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vec arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << lis(arr, n) << endl;

    return 0;
}

int lis(vec &arr, int n) {
    return 0;
}

void myFunction(int element) {
    cout << element << " ";
}
