#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/minimum-swaps-2/problem
// Tag(s): arrays, implementation
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
    int indices[n+1];

    for (int i = 1; i <= n; ++i) indices[arr[i]] = i;

    for (int i = 1; i <= n; ++i) {
        if(arr[i] == i) continue;

        int index = indices[i];

        indices[i] = i;
        indices[arr[i]] = index;
        swap(arr[i], arr[index]);
        ++ans;
    }

    return ans;
}
