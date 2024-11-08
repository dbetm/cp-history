#include <bits/stdc++.h>
// https://leetcode.com/problems/k-diff-pairs-in-an-array/
// Tag(s): hash map, implementation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int findPairs(vector<int>& nums, int k) {
    unordered_set<int> uniqueNums(nums.begin(), nums.end());
    unordered_set<int> usedNumbers;
    unordered_set<int> usedNumbersTwoTimes;
    int ans = 0;

    for(auto const num : nums) {
        if(usedNumbers.find(num) != usedNumbers.end()) {
            if(k == 0 and usedNumbersTwoTimes.find(num) == usedNumbersTwoTimes.end()) {
                ans++;
                usedNumbersTwoTimes.insert(num);
            }
            continue;
        }

        int x = num - k;
        int y = num + k;

        if(k != 0 and uniqueNums.find(x) != uniqueNums.end()) {
            ++ans;
        }
        if(k != 0 and uniqueNums.find(y) != uniqueNums.end()) {
            ++ans;
        }

        uniqueNums.erase(num);
        usedNumbers.insert(num);
    }

    return ans;
}

int main() {
    fastIO
    int n, k;
    cin >> n;
    vi nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;

    cout << findPairs(nums, k) << endl;

	return 0;
}
