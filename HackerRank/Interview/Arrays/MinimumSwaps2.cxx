#include <bits/stdc++.h>
//
// Tag(s):
using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;

int getMinSwaps(vector<int> &arr);

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> arr(n+1);

    for (int i = 1; i <= n; ++i) cin >> arr[i];

    cout << getMinSwaps(arr) << endl;

    return 0;
}

int getMinSwaps(vector<int> &arr) {
    int n = arr.size()-1;
    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        if(arr[i] == i) continue;
        int index;
        for (int j = i+1; j <= n; ++j) {
            if(arr[j] == i or arr[i] == j) {
                index = j;
                break;
            }
        }
        swap(arr[i], arr[index]);
        ++ans;
    }

    return ans;
}
