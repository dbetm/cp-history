#include <bits/stdc++.h>
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Tag(s): Implementación, cursores
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        vector<int> ans(2);

        while(start < end) {
            if((numbers[start] + numbers[end]) == target) {
                ans[0] = start + 1;
                ans[1] = end + 1;
                break;
            }
            else if(numbers[start] + numbers[end] > target) end--;
            else start++;
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    int n, target;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++) cin >> numbers[i];
    cin >> target;

    vector<int> ans = sol.twoSum(numbers, target);

    cout << ans[0] << ", " << ans[1] << endl;

    return 0;
}
