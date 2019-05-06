#include <bits/stdc++.h>
// Pasa 6 casos
using namespace std;
typedef vector<int> vec;

int lis(vec &, int);
void myFunction(int);

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
    int l[n];
    l[0] = 1;

    for (int i = 0; i < n; i++) {
        l[i] = 1;
        for (int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && l[i] < l[j] + 1) l[i] = l[j] + 1;
        }
    }
    /*
    for_each(l, l+n, myFunction);
    cout << endl;
    */
    return *max_element(l, l+n);
}

void myFunction(int element) {
    cout << element << " ";
}
