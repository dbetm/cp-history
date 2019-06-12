#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int lli;

int main() {
    vector<lli> arr(4);
    for (size_t i = 0; i < 4; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (size_t i = 0; i < 3; i++) cout << arr[i] << " ";
    cout << arr[3] << endl;
    return 0;
}
